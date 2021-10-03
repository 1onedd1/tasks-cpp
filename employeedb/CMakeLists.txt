# CMakeList.txt: проект CMake для taskscpp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project(employeedb)

# Добавьте источник в исполняемый файл этого проекта.
add_executable(${PROJECT_NAME} "src/main.cpp")

target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# Директория заголовочных файлов
