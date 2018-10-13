cmake_minimum_required(VERSION 3.9)
project(assignment4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)


#The places to look for the mpir folders
set(FIND_MPIR_PATHS
        /usr/local/opt/mpir        #On Mac, this is where my mpir
        folder is
        )

#The location of the include folder (and thus the header files)
#find_path uses the paths we defined above as places to look
#Saves the location of the header files in a variable called MPIR_INCLUDE_DIR
find_path(MPIR_INCLUDE_DIR mpir.h   #The variable to store the path in and the name of the header files
        PATH_SUFFIXES include               #The folder name containing the header files
        PATHS ${FIND_MPIR_PATHS})       #Where to look (defined above)

#The location of the lib folder (and thus the .a file)
#find_library uses the paths we defined above as places to look
#Saves the location of the .a file in a variable called MPIR_LIBRARY
find_library(MPIR_LIBRARY               #The variable to store where it found the .a files
        NAMES mpir                      #The name of the .a file (without the extension and without the 'lib')
        PATH_SUFFIXES lib                   #The folder the .a file is in
        PATHS ${FIND_MPIR_PATHS})       #Where to look (defined above)


add_executable(assignment4 ${SOURCE_FILES})

include_directories(${MPIR_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} ${MPIR_LIBRARY})

