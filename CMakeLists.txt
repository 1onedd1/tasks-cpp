﻿# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project (taskscpp)

# Включите подпроекты.
add_subdirectory (trucks)
add_subdirectory (sensor)
add_subdirectory (employeedb)
