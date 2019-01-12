#include <iostream>

#include "lib.h"


//#include <spdlog/spdlog.h>

int main(int argc, char *argv[])
{
   // auto logger = spdlog::stdout_logger_mt("console");
    //logger->info("version {} was started",version());
    std::cout<<"Hello, world!"<<std::endl;
    std::cout<<"version "<<version()<<std::endl;

    return 0;
}
