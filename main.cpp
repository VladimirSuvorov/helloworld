#include "lib.h"


#include <iostream>
#include <spdlog/spdlog.h>

#define UNUSED(VAR) (void)VAR

int main (int argc, char *argv[]){
    UNUSED(argc);UNUSED(argv);
    std::cout << "hello world" << std::endl;
    auto logger = spdlog::stdout_logger_mt("console");
    logger->info("version {} was started", version());

    return 0;
}
