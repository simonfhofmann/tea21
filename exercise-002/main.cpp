#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
void print_vector(const std::vector<int>& vec);
void binary_search(const std::vector<int>& vec,int num);
auto main(int argc, char **argv) -> int
{
    int count = 20;
    bool print = false;
    std::srand(std::time(nullptr));
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Set Count");
        app.add_option("-p,--print", print, "Do you want to print out the vectors");

        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    //print count 
    fmt::print("Count: {}\n", count);
    //create vector
    std::vector<int> vector;
    for(int i = 0; i < count; i++)
    {
        vector.push_back(rand() % 100 + 1);
    }
    //print vector  
    if(print)
    {
        print_vector(vector);
    }

    //sort vector
    auto start = std::chrono::system_clock::now();
    std::sort(vector.begin(), vector.end());
    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    //print sorted vector
    if(print)
    {
        print_vector(vector);
    }
    fmt::print("Time elapsed {} \n",elapsed);
    binary_search(vector, 17);
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf

     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
void print_vector(const std::vector<int>& vec) {
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
void binary_search(const std::vector<int>& vec, int num)
{
    int l = 0;
    int r = vec.size();
    while (l<=r)
    {   
        int mid = (r+l)/2;
        if(vec[mid] == num){
            fmt::print("{} is in vector",num);
            return;
        }
        else if(vec[mid] < num)
        {
            l = mid +1; 
        }
        else if(vec[mid] > num)
        {
            r = mid - 1; 
        }  
    }
    fmt::print("{} is not in vector",num);
}