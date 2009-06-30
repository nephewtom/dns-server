/*
 * File:   main.cpp
 * Author: torti
 *
 * Created on 26 de junio de 2009, 15:37
 */

#include <exception>
#include <iostream>
#include "application.h"
#include "logger.h"

using namespace std;
using namespace dns;
/*
 *
 */
int main(int argc, char** argv) {

    try {
        Application* application = new Application();
        application->getCommandLine(argc, argv);
        application->run();
    }
    catch (exception& e) {
        e.what();
    }

    return 0;
}
