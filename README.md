# crow-template
Template to quickly get started with [Crow](https://github.com/ipkn/crow) C++ micro web framework.

## To Run on Docker
```
docker build -t crow-cpp .
docker run -p 8080:8080 crow-cpp
```

## Installation steps
* On Ubuntu
```sh
$ sudo apt-get install gcc
$ sudo apt-get install g++
$ sudo apt-get install build-essential libtcmalloc-minimal4 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so
$ sudo apt-get install libboost-all-dev
$ sudo apt-get install cmake
```
* On OS X
```sh
$ brew install cmake
$ brew install boost google-perftools
```

## Steps to get started
```sh
$ ./compile.sh
$ ./build/src/example
```

## Shortcut
Refer to `shortcut` directory. This does not require cmake. Simpler way to get started.

## Important files
* src/example.cpp - Your web app code.
* src/CMakeLists.txt - Edit this file if there is new source code or HTML template file.
