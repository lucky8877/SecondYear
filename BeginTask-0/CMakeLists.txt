cmake_minimum_required(VERSION 3.2)

project(BeginTask-0)
add_executable(main main.cpp tests.cpp)
set_property(GLOBAL PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON)
target_compile_options(main PRIVATE
  -Ofast 
  -march=native      
  -DNDEBUG     
  -funroll-loops 
  -fno-stack-protector
  -fno-exceptions  
  -fno-rtti   
  -fomit-frame-pointer
)
target_link_libraries(main gtest gmock pthread) 
