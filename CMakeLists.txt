cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ffmpegProject VERSION 1.0)

add_subdirectory(libs/FFMPEG)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
libavcodec
libavformat
libavfilter
libavdevice
libavutil
libswresample
libswscale
)
