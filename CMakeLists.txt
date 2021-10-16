# cmake_minimum_required(VERSION <specify CMake version here>)
project(Pcode C)

set(CMAKE_C_STANDARD 99)

add_executable(Pcode main.c main.c pc_stack.h pc_code.h pc_var.h pc_screen.c pc_stack.c pc_screen.h pcode.h pc_func_table.h pc_lable_table.h pc_lexer.c pc_lexer.h)