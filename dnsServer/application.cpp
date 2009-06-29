/* 
 * File:   application.cpp
 * Author: tomas
 * 
 * Created on June 27, 2009, 11:20 AM
 */

#include <iostream>
#include "application.h"

using namespace dns;
using namespace std;

void Application::run() throw() {

    cout << "DNS Server started." << endl;

    m_server.init();
    m_server.run();
}
