cmake_minimum_required (VERSION 3.10.2)

include_directories("${PROJECT_SOURCE_DIR}/boost_di/include/")
include_directories("${PROJECT_SOURCE_DIR}/boost_di/extension/include/")

file(GLOB source_files "*.cpp")

add_executable (Main ${source_files})
