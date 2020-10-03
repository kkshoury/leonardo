set(PROJECT_NAME io)

cmake_minimum_required(VERSION 3.10)
set_property(GLOBAL PROPERTY USE_FOLDERS On)


project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.h)

source_group(	
				TREE ${PROJECT_SOURCE_DIR} 
				FILES 
					${SOURCE_FILES} 
					${HEADER_FILES}
			)

# add the executable
add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})


message(${CMAKE_CURRENT_BINARY_DIR})
message(${CMAKE_BINARY_DIR})
message(${CMAKE_SOURCE_DIR})

target_include_directories(
							${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}"
                           		"../../libs/glad/include/glad"
                           		"../../libs/glad/include/KHR"
                           		"../../libs/glfw/include/GLFW"
                           		"systems"
                           		"components"
                           		"include"
                           		${PROJECT_SOURCE_DIR}
                          )

target_link_libraries(${PROJECT_NAME} PUBLIC "C:/develop/leonardo/libs/glfw/lib-vc2015/glfw3.lib")

