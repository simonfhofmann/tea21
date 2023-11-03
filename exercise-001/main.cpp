#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"
// .bss segment
int foo;
// .data segment
int data = 4711;

// .rodata segment
int const rodata = 69;


auto main(int argc, char **argv) -> int
{
   
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", "hello i am under water please help me");

    fmt::print("Value of foo {} adress of foo{}\n",foo,fmt::ptr(&foo));
    fmt::print("Value of dta {} adress of data{}\n",data,fmt::ptr(&data));
    fmt::print("Value of rodata {} adress of rodata{}\n",rodata,fmt::ptr(&rodata));

    return 0; /* exit gracefully*/
}
