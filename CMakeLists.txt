cmake_minimum_required(VERSION 3.5)
if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif()

project(ForTheRecord)

enable_testing()
find_package (GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


ADD_EXECUTABLE( 
    ftr 
    main.cpp

	console.hpp
	console.cpp

	program.hpp
	program.cpp
    
) 

ADD_EXECUTABLE( 
    ftr.test 
    
	console.hpp
	console.cpp

	program.hpp
	program.cpp

	program.test.cpp
	
)

target_link_libraries(
    ftr.test 
	${GTEST_BOTH_LIBRARIES} 
)


