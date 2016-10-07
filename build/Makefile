# list of the stuff i use repeatedly
	# $@ is the name of this make rule
	# $^ are all the requirements of this make rule

l=g++ -Wall -Wextra --std=c++17 -DLINUX
w=x86_64-w64-mingw32-g++ -Wall -Wextra --std=c++17 -DWINDOWS -DSFML_STATIC -static

linux: Hozho

android: Hozho.apk

windows: Hozho.exe

all: linux windows android

Hozho.apk: ../android/res/values/strings.xml ../android/build_android.sh ../android/jni/*
	./build_android.sh
	if [ -f "../android/bin/Hozho-debug.apk" ]; then mv ../android/bin/Hozho-debug.apk Hozho.apk; fi
	if [ -f "../android/bin/Hozho-release.apk" ]; then mv ../android/bin/Hozho-release.apk Hozho.apk; fi



Hozho: main_linux.o events_linux.o socket_linux.o debugging_linux.o button_linux.o menu_linux.o
	$l -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

main_linux.o: ../source/main.cpp
	$l -c -o $@ $^

events_linux.o: ../source/events.cpp
	$l -c -o $@ $^

debugging_linux.o: ../source/debugging.cpp
	$l -c -o $@ $^

button_linux.o: ../source/classes/button.cpp
	$l -c -o $@ $^

menu_linux.o: ../source/classes/menu.cpp
	$l -c -o $@ $^

socket_linux.o: ../socket/socket.cpp ../socket/socket_unix.cpp
	$l -c -o $@ ../socket/socket.cpp



Hozho.exe: main_windows.o events_windows.o socket_windows.o debugging_windows.o button_windows.o menu_windows.o
	$w -o $@ $^ -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg -lopenal32 -lvorbisenc -lvorbisfile -lvorbis -logg -lws2_32

main_windows.o: ../source/main.cpp
	$w -c -o $@ $^ -lsfml-system-s -lsfml-window-s -lsfml-graphics-s

events_windows.o: ../source/events.cpp
	$w -c -o $@ $^ -lsfml-system-s -lsfml-window-s -lsfml-graphics-s

debugging_windows.o: ../source/debugging.cpp
	$w -c -o $@ $^

button_windows.o: ../source/classes/button.cpp
	$w -c -o $@ $^

menu_windows.o: ../source/classes/menu.cpp
	$w -c -o $@ $^

socket_windows.o: ../socket/socket.cpp ../socket/socket_windows.cpp
	$w -c -o $@ ../socket/socket.cpp



clean:
	rm -f *.o
	rm -f Hozho
	rm -f Hozho.exe
	rm -f Hozho.apk