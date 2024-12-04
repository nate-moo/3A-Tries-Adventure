# CMakeLists.txt for the hashtable project
cmake_minimum_required(VERSION 3.14)

# Ensure we can use gdb
set(CMAKE_BUILD_TYPE Debug)

project(project3a-liltrieadventure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

# Retrieve the wordlist used by the tests and copy to build directory
file(
  DOWNLOAD http://wiki.puzzlers.org/pub/wordlists/enable1.txt ./dictionary.txt 
  EXPECTED_HASH MD5=33f2b09e2d9dfb732fa16b5f05a5a8d1
)
file(COPY dictionary.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_compile_options(-pedantic -Wall -Wextra -Werror=vla)

add_executable(run-test trie.h trie.cpp liltrie.h liltrie.cpp bitwiseops.h random220.h 
		main-test.cpp random220.cpp
		mtrie.cpp
		mtrie.h)

add_executable(run-main trie.h trie.cpp liltrie.h liltrie.cpp bitwiseops.h random220.h 
		main.cpp random220.cpp
		mtrie.cpp
		mtrie.h)

