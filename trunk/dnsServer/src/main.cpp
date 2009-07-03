/*
 * File:   main.cpp
 * Author: tomas
 *
 * Created on 26 de junio de 2009, 15:37
 */

#include <iostream>

#include "application.h"
#include "exception.h"

using namespace std;
/*
 *
 */
int main(int argc, char** argv) {

    try {
        dns::Application* application = new dns::Application();
        application->parse_arguments(argc, argv);
        application->run();
    }
    catch (dns::Exception& e) {
        cout << e.what() << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
