cmake_minimum_required(VERSION 3.20)

project(HelloWorldConsole)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Specify custom Qt installation location ---
# Ensure CMake searches here first
list(PREPEND CMAKE_PREFIX_PATH "/opt/qt/6.8.2/lib/cmake")

# --- Find and configure Qt ---
find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

add_executable(${PROJECT_NAME} src/HelloWorldConsole.cpp)
target_link_libraries(${PROJECT_NAME} Qt::Core)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Qt.Core/HelloWorlds")

