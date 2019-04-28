find_path(Crashpad_INCLUDE_DIR "client/crashpad_client.h")
find_library(Crashpad_CLIENT_LIBRARY "client")
find_library(Crashpad_UTIL_LIBRARY "util")
find_library(Crashpad_MINI_CHROMIUM_BASE_LIBRARY "base")
#find_program(Crashpad_HANDLER_EXECUTABLE "crashpad_handler")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Crashpad DEFAULT_MSG
    Crashpad_CLIENT_LIBRARY
    Crashpad_UTIL_LIBRARY
    Crashpad_MINI_CHROMIUM_BASE_LIBRARY
    Crashpad_INCLUDE_DIR
    #Crashpad_HANDLER_EXECUTABLE
)

if(Crashpad_FOUND AND NOT TARGET Crashpad)
    add_library(Crashpad INTERFACE)
	target_compile_options(Crashpad INTERFACE "/Oy-")
    target_compile_definitions(Crashpad INTERFACE HAVE_CRASHRPT)
    target_include_directories(Crashpad SYSTEM INTERFACE "${Crashpad_INCLUDE_DIR}" "${Crashpad_INCLUDE_DIR}/client" "${Crashpad_INCLUDE_DIR}/mini_chromium")
    target_link_libraries(Crashpad INTERFACE "${Crashpad_CLIENT_LIBRARY}" "${Crashpad_UTIL_LIBRARY}" "${Crashpad_MINI_CHROMIUM_BASE_LIBRARY}")
endif()
