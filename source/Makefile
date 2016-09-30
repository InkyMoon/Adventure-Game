# list of the stuff i use repeatedly
	# $@ is the name of this make rule
	# $^ are all the requirements of this make rule

l=g++ -Wall -Wextra --std=c++17 -DLINUX
w=x86_64-w64-mingw32-g++ -Wall -Wextra --std=c++17 -DWINDOWS -DSFML_STATIC -static


all: Hozho Hozho.exe Hozho.apk

Hozho.apk: ../android/res/values/strings.xml ../android/build_android.sh ../android/jni/*
	pushd ../android &>/dev/null && ../android/build_android.sh && popd &>/dev/null
	if [ -f "../android/bin/Hozho-debug.apk" ]; then mv ../android/bin/Hozho-debug.apk Hozho.apk; fi
	if [ -f "../android/bin/Hozho-release.apk" ]; then mv ../android/bin/Hozho-release.apk Hozho.apk; fi

Hozho: main_linux.o events_linux.o socket_linux.o debugging_linux.o
	$l -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

Hozho.exe: main_windows.o events_windows.o socket_windows.o debugging_windows.o
	$w -o $@ $^ -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg -lopenal32 -lvorbisenc -lvorbisfile -lvorbis -logg -lws2_32

main_linux.o: main.cpp
	$l -c -o $@ $^

events_linux.o: events.cpp
	$l -c -o $@ $^

debugging_linux.o: debugging.cpp
	$l -c -o $@ $^

socket_linux.o: socket/socket.cpp socket/socket_unix.cpp
	$l -c -o $@ socket/socket.cpp

main_windows.o: main.cpp
	$w -c -o $@ $^ -lsfml-system-s -lsfml-window-s -lsfml-graphics-s

events_windows.o: events.cpp
	$w -c -o $@ $^ -lsfml-system-s -lsfml-window-s -lsfml-graphics-s

debugging_windows.o: debugging.cpp
	$w -c -o $@ $^

socket_windows.o: socket/socket.cpp socket/socket_windows.cpp
	$w -c -o $@ socket/socket.cpp

clean:
	if [[ -n *.o ]]; then rm *.o; fi
	if [ -f Hozho ]; then rm Hozho; fi
	if [ -f Hozho.exe ]; then rm Hozho.exe; fi
	if [ -f Hozho.apk ]; then rm Hozho.apk; fi