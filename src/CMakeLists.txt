cmake_minimum_required (VERSION 3.17)

add_executable("29_Homework_Task_1" main.cpp ${MY_INCLUDE_DIR})
target_include_directories("29_Homework_Task_1" PUBLIC ${MY_INCLUDE_DIR})