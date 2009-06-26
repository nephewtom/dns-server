/* 
 * File:   application.cpp
 * Author: tomas
 * 
 * Created on June 27, 2009, 11:20 AM
 */

#include "application.h"

using namespace dns;

Application::Application() {
}

Application::Application(const Application& orig) {
}

Application::~Application() {
}

void Application::run() throw() {

    server.init();
    server.run();
}
