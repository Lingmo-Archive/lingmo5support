/*
    SPDX-FileCopyrightText: 2009 Aaron Seigo <aseigo@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "keystate.h"

#include <QDebug>

#include "keyservice.h"
#include <klocalizedstring.h>

KeyStatesEngine::KeyStatesEngine(QObject *parent)
    : Lingmo5Support::DataEngine(parent)
{
    qWarning("KeyStatesEngine is deprecated. Use KeyState from org.kde.lingmo.private.keyboardindicator instead.");
    m_mods.insert(Qt::Key_Shift, kli18n("Shift"));
    m_mods.insert(Qt::Key_Control, kli18n("Ctrl"));
    m_mods.insert(Qt::Key_Alt, kli18n("Alt"));
    m_mods.insert(Qt::Key_Meta, kli18n("Meta"));
    m_mods.insert(Qt::Key_Super_L, kli18n("Super"));
    m_mods.insert(Qt::Key_Hyper_L, kli18n("Hyper"));
    m_mods.insert(Qt::Key_AltGr, kli18n("AltGr"));
    m_mods.insert(Qt::Key_NumLock, kli18n("Num Lock"));
    m_mods.insert(Qt::Key_CapsLock, kli18n("Caps Lock"));
    m_mods.insert(Qt::Key_ScrollLock, kli18n("Scroll Lock"));

    m_buttons.insert(Qt::LeftButton, kli18n("Left Button"));
    m_buttons.insert(Qt::RightButton, kli18n("Right Button"));
    m_buttons.insert(Qt::MiddleButton, kli18n("Middle Button"));
    m_buttons.insert(Qt::XButton1, kli18n("First X Button"));
    m_buttons.insert(Qt::XButton2, kli18n("Second X Button"));
    init();
}

KeyStatesEngine::~KeyStatesEngine()
{
}

void KeyStatesEngine::init()
{
    const auto end = m_mods.constEnd();
    for (auto it = m_mods.constBegin(); it != end; ++it) {
        if (m_keyInfo.knowsKey(it.key())) {
            Data data;
            data.insert(QString::fromLatin1(kli18n("Pressed").untranslatedText()), m_keyInfo.isKeyPressed(it.key()));
            data.insert(QString::fromLatin1(kli18n("Latched").untranslatedText()), m_keyInfo.isKeyLatched(it.key()));
            data.insert(QString::fromLatin1(kli18n("Locked").untranslatedText()), m_keyInfo.isKeyLocked(it.key()));
            setData(QString::fromLatin1(it.value().untranslatedText()), data);
        }
    }

    const auto end2 = m_buttons.constEnd();
    for (auto it2 = m_buttons.constBegin(); it2 != end2; ++it2) {
        Data data;
        data.insert(QString::fromLatin1(kli18n("Pressed").untranslatedText()), m_keyInfo.isButtonPressed(it2.key()));
        setData(QString::fromLatin1(it2.value().untranslatedText()), data);
    }

    connect(&m_keyInfo, &KModifierKeyInfo::keyPressed, this, &KeyStatesEngine::keyPressed);
    connect(&m_keyInfo, &KModifierKeyInfo::keyLatched, this, &KeyStatesEngine::keyLatched);
    connect(&m_keyInfo, &KModifierKeyInfo::keyLocked, this, &KeyStatesEngine::keyLocked);
    connect(&m_keyInfo, &KModifierKeyInfo::buttonPressed, this, &KeyStatesEngine::mouseButtonPressed);
    connect(&m_keyInfo, &KModifierKeyInfo::keyAdded, this, &KeyStatesEngine::keyAdded);
    connect(&m_keyInfo, &KModifierKeyInfo::keyRemoved, this, &KeyStatesEngine::keyRemoved);
}

Lingmo5Support::Service *KeyStatesEngine::serviceForSource(const QString &source)
{
    const auto end = m_mods.constEnd();
    for (auto it = m_mods.constBegin(); it != end; ++it) {
        if (QLatin1String(it.value().untranslatedText()) == source) {
            return new KeyService(this, &m_keyInfo, it.key());
        }
    }

    return Lingmo5Support::DataEngine::serviceForSource(source);
}

void KeyStatesEngine::keyPressed(Qt::Key key, bool state)
{
    if (m_mods.contains(key)) {
        setData(QString::fromLatin1(m_mods.value(key).untranslatedText()), QString::fromLatin1(kli18n("Pressed").untranslatedText()), state);
    }
}

void KeyStatesEngine::keyLatched(Qt::Key key, bool state)
{
    if (m_mods.contains(key)) {
        setData(QString::fromLatin1(m_mods.value(key).untranslatedText()), QString::fromLatin1(kli18n("Latched").untranslatedText()), state);
    }
}

void KeyStatesEngine::keyLocked(Qt::Key key, bool state)
{
    if (m_mods.contains(key)) {
        setData(QString::fromLatin1(m_mods.value(key).untranslatedText()), QString::fromLatin1(kli18n("Locked").untranslatedText()), state);
    }
}

void KeyStatesEngine::mouseButtonPressed(Qt::MouseButton button, bool state)
{
    if (m_buttons.contains(button)) {
        setData(QString::fromLatin1(m_buttons.value(button).untranslatedText()), QString::fromLatin1(kli18n("Pressed").untranslatedText()), state);
    }
}

void KeyStatesEngine::keyAdded(Qt::Key key)
{
    if (m_mods.contains(key)) {
        Data data;
        data.insert(QString::fromLatin1(kli18n("Pressed").untranslatedText()), m_keyInfo.isKeyPressed(key));
        data.insert(QString::fromLatin1(kli18n("Latched").untranslatedText()), m_keyInfo.isKeyLatched(key));
        data.insert(QString::fromLatin1(kli18n("Locked").untranslatedText()), m_keyInfo.isKeyLocked(key));
        setData(QString::fromLatin1(m_mods.value(key).untranslatedText()), data);
    }
}

void KeyStatesEngine::keyRemoved(Qt::Key key)
{
    if (m_mods.contains(key)) {
        removeSource(QString::fromLatin1(m_mods.value(key).untranslatedText()));
    }
}

K_PLUGIN_CLASS_WITH_JSON(KeyStatesEngine, "lingmo-dataengine-keystate.json")

#include "keystate.moc"
