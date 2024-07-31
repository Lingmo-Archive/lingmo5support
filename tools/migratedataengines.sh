 #!/bin/sh

# C++ files
find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/Lingmo(\/|::)DataContainer/Lingmo5Support\\1DataContainer/g"
find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/Lingmo(\/|::)DataEngine/Lingmo5Support\\1DataEngine/g"
find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/Lingmo(\/|::)DataEngineConsumer/Lingmo5Support\\1DataEngineConsumer/g"

find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/Lingmo(\/|::)Service/Lingmo5Support\\1Service/g"
find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/Lingmo(\/|::)ServiceJob/Lingmo5Support\\1ServiceJob/g"

find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/namespace Lingmo(;|\n)/namespace Lingmo5Support\\1/g"



find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/lingmo\/datacontainer/lingmo5support\/datacontainer/g"
find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/lingmo\/dataengine/lingmo5support\/dataengine/g"
find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/lingmo\/dataengineconsumer/lingmo5support\/dataengineconsumer/g"

find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/lingmo\/service/lingmo5support\/service/g"
find . -name "*.h" -o -name "*.cpp" | xargs perl -p -i -e "s/lingmo\/servicejob/lingmo5support\/servicejob/g"

# Desktop files
find . -name "*.desktop" | xargs perl -p -i -e "s/Lingmo\/DataEngine/Lingmo5Support\/DataEngine/g"

# CMake
find . -name "CMakeLists.txt"  | xargs perl -p -i -e "s/KF5::Lingmo/KF5::Lingmo5Support/g"
find . -name "CMakeLists.txt"  | xargs perl -p -i -e "s/LINGMO_DATA_INSTALL_DIR/LINGMO5SUPPORT_DATA_INSTALL_DIR/g"
find . -name "CMakeLists.txt"  | xargs perl -p -i -e "s/lingmo\/dataengine/lingmo5support\/dataengine/g"
