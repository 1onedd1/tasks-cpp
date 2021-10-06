# CMakeList.txt: проект CMake для taskscpp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project(employeedb)

set(CMAKE_CXX_FLAGS_RELEASE_INIT)
# Добавьте источник в исполняемый файл этого проекта.
add_executable(${PROJECT_NAME} "src/main.cpp" )

target_link_libraries(
    ${PROJECT_NAME} 
    "${PROJECT_SOURCE_DIR}/lib"
    "${PROJECT_SOURCE_DIR}/lib/vs14"
)

set(-DWITH_JDBC=true)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include/jdbc
    PRIVATE ${PROJECT_SOURCE_DIR}/include/jdbc/cppconn
    PRIVATE ${PROJECT_SOURCE_DIR}/include/mysql
    PRIVATE ${PROJECT_SOURCE_DIR}/include/mysqlx
    PRIVATE ${PROJECT_SOURCE_DIR}/include/mysqlx/common
    PRIVATE ${PROJECT_SOURCE_DIR}/include/mysqlx/devapi
    PRIVATE ${PROJECT_SOURCE_DIR}/include/mysqlx/devapi/detail
)

# Директория заголовочных файлов
