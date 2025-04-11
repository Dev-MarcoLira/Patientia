cmake_minimum_required(VERSION 3.10)
project(Patientia)

set(CMAKE_CXX_STANDARD 17)

# Ajuste este caminho para onde você extraiu o SFML
set(SFML_DIR "C:/SFML/SFML-2.5.0/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(Patientia ${SOURCES})
target_link_libraries(Patientia sfml-graphics sfml-window sfml-system)