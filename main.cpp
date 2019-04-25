#include <functional>
#include <iostream>
#include <spdlog/spdlog.h>
#include "lib.h"


int main ([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]){
    std::cout << "hello world" << std::endl;
    auto logger = spdlog::stdout_logger_mt("console");
    logger->info("version {} was started", version());

    return 0;
}
