
#############
##  Build  ##
#############

#Declare C executable
add_executable(test_connecting
	connect.c)

##############
## Find k4a ##
##############

find_package(k4a 1.3.0 REQUIRED) 

target_link_libraries(test_connecting PRIVATE k4a)
