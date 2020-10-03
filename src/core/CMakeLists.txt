set(PROJECT_NAME core)

cmake_minimum_required(VERSION 3.10)
set_property(GLOBAL PROPERTY USE_FOLDERS On)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(${PROJECT_NAME})

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.h)

file(GLOB_RECURSE IO_HEADERS_DIR CONFIGURE_DEPENDS ../io/include)
file(GLOB_RECURSE GRAPHICS_HEADERS_DIR CONFIGURE_DEPENDS ../graphics/include)


source_group(	
				TREE ${PROJECT_SOURCE_DIR} 
				FILES 
					${SOURCE_FILES} 
					${HEADER_FILES}
			)

# add the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/" )

target_include_directories(
							${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}"
                           		"../../libs/glad/include/glad"
                           		"../../libs/glad/include/KHR"
                           		"../../libs/glfw/include/GLFW"
                           		"systems"
                           		"components"
                           		"include"
                           		${PROJECT_SOURCE_DIR}
                           		"../io/include"
                           		"../io/"
                           		"../graphics/include"
                           		"../graphics/src"
                          )

target_link_libraries(
	${PROJECT_NAME} 
		PUBLIC 
			"C:/develop/leonardo/libs/glfw/lib-vc2015/glfw3.lib"
			graphics
			io
	)

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)