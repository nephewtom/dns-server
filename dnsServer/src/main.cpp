/*
 * File:   main.cpp
 * Author: torti
 *
 * Created on 26 de junio de 2009, 15:37
 */

#include <iostream>

#include "application.h"
#include "exception.h"

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
    catch (Exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
