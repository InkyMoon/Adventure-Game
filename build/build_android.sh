#!/bin/bash

# save the path variable before we modify it
tmpPATH=$PATH

# the path of my installation of the sdk and ndk
export PATH=$PATH":/opt/android-ndk:/opt/android-sdk/tools"

pushd ../android &> /dev/null && \
echo "android: updating the project" && \
android update project --target "android-19" --path . &> build.log && \
echo "android: building the project" && \
ndk-build &> build.log && \
echo "android: packaging the project" && \
ant debug &> build.log && \
echo "android: finished" && \
popd &> /dev/null && \
export PATH=$tmpPATH && \
exit 0

popd
export PATH=$tmpPATH
exit 1
#adb uninstall ca.eighty7.app && \
#adb install -r bin/Hózhó-debug.apk && \
#adb shell am start -n ca.eighty7.hózhó/android.app.NativeActivity

# revert the modifications we made
