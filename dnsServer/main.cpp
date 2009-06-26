/*
 * File:   main.cpp
 * Author: torti
 *
 * Created on 22 de junio de 2009, 15:37
 */

#include "application.h"

#include <iostream>

using namespace std;
using namespace dns;
/*
 *
 */
int main(int argc, char** argv) {

    cout << "DNS Server started." << endl;

    Application* application = new Application();
    application->run();

    return 0;
}
