cmake_minimum_required(VERSION 2.8)
project (crow_template)

add_executable(example example.cpp)
target_link_libraries(example ${Boost_LIBRARIES})
target_link_libraries(example ${CMAKE_THREAD_LIBS_INIT})

#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -pg" )
#SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -g -pg" )
