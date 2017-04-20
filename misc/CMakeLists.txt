project(std)

add_definitions("-std=c++11")

add_executable(bigintegerplus BigIntegerPlus.cpp)
add_executable(quicksortexampler QuickSortExampler.cpp)
add_executable(stackexampler StackExampler.cpp)
add_executable(queueexampler QueueExampler.cpp)



# include_directories(${FFMPEG_INCLUDE_DIR})
# add_definitions(-D__STDC_CONSTANT_MACROS)
# link_directories(${FFMPEG_LIB_DIR})
# add_executable(input input.cpp)
# # file(GLOB LIBAVFORMAT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*)
# target_link_libraries(input avdevice avfilter avformat avcodec swresample swscale avutil postproc)
# add_executable(input_dshow input_dshow.cpp)
# target_link_libraries(input_dshow avdevice avfilter avformat avcodec swresample swscale avutil postproc)
