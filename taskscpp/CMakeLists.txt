# CMakeList.txt: проект CMake для taskscpp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (taskscpp "taskscpp.cpp" "taskscpp.h" "file_reader.cpp" "datacar.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
