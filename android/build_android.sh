#!/bin/bash

# save the path variable before we modify it
tmpPATH=$PATH

# the path of my installation of the sdk and ndk
export PATH=$PATH":/opt/android-sdk/tools:/opt/android-ndk"

echo "android: updating the project" && \
android update project --target "android-19" --path . &> build.log && \
echo "android: building the project" && \
ndk-build &> build.log && \
echo "android: packaging the project" && \
ant debug &> build.log && \
echo "android: finished"
#adb uninstall ca.eighty7.app && \
#adb install -r bin/Hózhó-debug.apk && \
#adb shell am start -n ca.eighty7.hózhó/android.app.NativeActivity

# revert the modifications we made
export PATH=$tmpPATH