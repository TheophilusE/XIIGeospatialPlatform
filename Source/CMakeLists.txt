cmake_minimum_required(VERSION 3.21)

project (GeospatialPlatform VERSION 1.0 LANGUAGES C CXX)

if(PROJECT_IS_TOP_LEVEL)

	set (XII_SDK_DIR "" CACHE PATH "The xiiEngine SDK root directory.")

	message(STATUS "XII_SDK_DIR is set to '${XII_SDK_DIR}'")

	# Set output directory to the engine binary location
	set (XII_OUTPUT_DIRECTORY_LIB "${XII_SDK_DIR}/Output/Lib" CACHE PATH "Where to store the compiled .lib files." FORCE)
	set (XII_OUTPUT_DIRECTORY_DLL "${XII_SDK_DIR}/Output/Bin" CACHE PATH "Where to store the compiled .dll files." FORCE)

	include("${XII_SDK_DIR}/xiiCMakeConfig.cmake")
	get_property(XII_CMAKE_RELPATH GLOBAL PROPERTY XII_CMAKE_RELPATH)
	get_property(XII_CMAKE_RELPATH_CODE GLOBAL PROPERTY XII_CMAKE_RELPATH_CODE)

	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${XII_SDK_DIR}/${XII_CMAKE_RELPATH}")

	include("xiiUtils")
	include("xiiPlatformVars")

	xii_include_xiiExport()

	xii_configure_external_project()

endif()

# Include all projects in the sub-folders
xii_add_all_subdirs()
