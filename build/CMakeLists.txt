cmake_minimum_required(VERSION 2.6)

#Configuration du projet
project(Exe)

# detect the OS
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(WINDOWS 1)

    # detect the architecture (note: this test won't work for cross-compilation)
    include(CheckTypeSize)
    check_type_size(void* SIZEOF_VOID_PTR)
    if(${SIZEOF_VOID_PTR} EQUAL "4")
        set(ARCH_32BITS 1)
    elseif(${SIZEOF_VOID_PTR} EQUAL "8")
        set(ARCH_64BITS 1)
    else()
        message(FATAL_ERROR "Unsupported architecture")
        return()
    endif()
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(LINUX 1)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
    # FreeBSD compile path is the same as Linux
    set(LINUX 1)
else()
    message(FATAL_ERROR "Unsupported operating system (" ${CMAKE_SYSTEM_NAME} ")" )
    return()
endif()

SET(CMAKE_BUILD_TYPE Release)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../bin/${CMAKE_BUILD_TYPE})

if ( LINUX )
	set(LIBRARY_EXTLIBS_OS "lib-linux" )
endif()
if ( WINDOWS )
	set(LIBRARY_EXTLIBS_OS "lib-mingw" )
endif()

if ( WINDOWS )
	add_definitions(-DWIN32)
endif()
#add_definitions(-DSFML_EXPORTS)
#add_definitions(-DSFML_STATIC)
add_definitions(-DSFML_DYNAMIC)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../sources)

#Inclusion des bibliotheques
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../sources/includes)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../sources/framework/includes)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libs/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libs/headers)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../.)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libs/${LIBRARY_EXTLIBS_OS})


if ( WINDOWS )
add_library( sndfile STATIC IMPORTED)
set_property(TARGET sndfile PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../libs/${LIBRARY_EXTLIBS_OS}/libsndfile.a)
add_library(openal STATIC IMPORTED)
set_property(TARGET openal PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../libs/${LIBRARY_EXTLIBS_OS}/libopenal32.a)

endif()

#Configuration de l'exécutable
file(
	GLOB#_RECURSE
	source_files
	../sources/framework/*
	../sources/*.cpp
)
#list(REMOVE_ITEM source_files "../sources/engine")

add_executable(
	Exe
	${source_files}
)

#Configuration de l'édition de liens
target_link_libraries( Exe sfml-audio )
target_link_libraries( Exe sfml-network )
target_link_libraries( Exe sfml-window )
target_link_libraries( Exe sfml-graphics )
target_link_libraries( Exe sfml-system )
target_link_libraries( Exe sndfile )
target_link_libraries( Exe openal )


if ( LINUX )
   target_link_libraries( Exe GLU )
   target_link_libraries( Exe GL )
endif()

if ( WINDOWS )
set_target_properties( Exe PROPERTIES LINK_FLAGS "-static-libgcc")
   target_link_libraries( Exe glu32 )
   target_link_libraries( Exe opengl32 )
endif()

