cmake_minimum_required(VERSION 3.22)
project(FFMPEG)

find_package(PkgConfig REQUIRED)
pkg_check_modules(AVCODEC REQUIRED IMPORTED_TARGET
libavcodec
libavformat
libavfilter
libavdevice
libavutil
libswresample
libswscale
)
