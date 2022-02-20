cmake_minimum_required(VERSION 3.0)
project(
	ktree 
	VERSION 1.0 
	DESCRIPTION "LIST array library"
	HOMEPAGE_URL ""
	LANGUAGES C
)


set (CMAKE_C_STANDARD 11)

add_library(ktree STATIC ktree.c)

add_subdirectory(klist)

add_executable(ktree_test test.c)
target_link_libraries(ktree_test ktree klist)
