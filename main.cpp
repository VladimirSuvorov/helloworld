#include "lib.h"

#include <iostream>
#include <functional> //see https://github.com/gabime/spdlog/issues/940
#include <spdlog/spdlog.h>

int main (int argc, char *argv[]){
    std::cout << "hello world" << std::endl;
    auto logger = spdlog::stdout_logger_mt("console");
    logger->info("version {} was started", version());

    return 0;
}
