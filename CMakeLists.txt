cmake_minimum_required(VERSION 2.7)
project(sfml-game)

# Enable debug settings by default
if(CMAKE_BUILD_TYPE STREQUAL "")
	set(CMAKE_BUILD_TYPE Debug)
endif()
# On the command line you could set: -DCMAKE_BUILD_TYPE=Release

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 0)
set(myproject_VERSION_MINOR 3)
# configure_file(
#	"${PROJECT_SOURCE_DIR}/config.h.in"
#	"${PROJECT_BINARY_DIR}/config.h")

# Define sources and executable
set(EXECUTABLE_NAME "sfml-game")
include_directories("${PROJECT_SOURCE_DIR}/include")
add_executable(${EXECUTABLE_NAME} 
                src/main.cpp
                src/Game.cpp
                src/InputHandler.cpp
                src/RenderingMonitor.cpp
                src/SceneNode.cpp
                src/State.cpp
                src/StateManager.cpp
                src/TitleState.cpp
                src/GameplayState.cpp
                src/PausedState.cpp
                src/Utility.cpp
)

#Set compiler flags
if(APPLE)
    SET(CMAKE_CXX_COMPILER "g++-4.8.1")
elseif(UNIX)
    SET(CMAKE_CXX_COMPILER "g++")
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Detect and add SFML
set(CMAKE_FIND_FRAMEWORK NEVER)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)
