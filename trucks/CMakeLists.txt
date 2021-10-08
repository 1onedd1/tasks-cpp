# CMakeList.txt: проект CMake для taskscpp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project(trucks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES 
    src/main.cpp
    src/util.cpp
    src/DateTime.cpp
    src/DataCar.cpp
    
)

# Добавьте источник в исполняемый файл этого проекта.
add_executable(${PROJECT_NAME} ${SOURCES})

# Директория заголовочных файлов
target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)
