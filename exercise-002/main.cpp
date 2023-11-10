#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    int count = 20;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Set Count");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    //print count 
    printf("Count: %d\n", count);
    std::vector<int> vector;
    for (int i = 0; i < count; i++)
    {
        vector.push_back(rand() % 100 + 1);
    }
    //print vector  
    printf("Vector: ");
    vector.push_back(0);
    for (int i = 0; vector[i]; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf

     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
