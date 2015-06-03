# Sources:-
# https://github.com/ipkn/crow/wiki/Installation
# http://forums.macrumors.com/threads/boost-thread-hpp-macos-x-c-linker.1750956/

# On Ubuntu
#g++ -O3 -std=c++11 example.cpp -o example -lboost_thread -lboost_system -pthread

# On OS X
g++ -O3 -std=c++14 example.cpp -o example -lboost_thread-mt -lboost_system-mt -pthread
