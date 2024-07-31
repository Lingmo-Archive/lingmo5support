pkgname=lingmo5support
pkgver=2.9.0
pkgrel=1
pkgdesc='Support components for porting from KF5/Qt5 to KF6/Qt6'
arch=(x86_64)
url='https://github.com/LingmoOS/lingmo5support'
license=(LGPL-2.0-or-later)
depends=(gcc-libs
         glibc
         kconfig
         kcoreaddons
         kguiaddons
         ki18n
         knotifications
         libksysguard
         qt6-base
         qt6-declarative
         solid)
makedepends=(doxygen
             extra-cmake-modules
             qt6-tools)
source=(git+$url)
sha256sums=('SKIP')
validpgpkeys=('41EF7182553A87AC18196A77F27F2FDA54F067D8') # Lingmo OS Team <team@lingmo.org>

build() {
  cmake -B build  -S $pkgname \
    -DBUILD_TESTING=OFF \
    -DBUILD_QCH=ON
  cmake --build build -j12
}

package() {
  DESTDIR="$pkgdir" cmake --install build
}

