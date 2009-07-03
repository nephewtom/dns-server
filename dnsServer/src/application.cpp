/* 
 * File:   application.cpp
 * Author: tomas
 * 
 * Created on June 27, 2009, 16:20 AM
 */

#include <iostream>
#include <stdlib.h> //atoi

#include "application.h"
#include "logger.h"
#include "exception.h"

using namespace dns;
using namespace std;

void Application::parse_arguments(int argc, char** argv) throw (Exception) {

    if (argc != 3) {

        string text("Usage: dnsServer <port> <hostsFile>\n");
        text += "Example: dnsServer 9000 hosts\n";
        Exception e(text);
        throw (e);
    }

    m_port = atoi(argv[1]);
    if (m_port < 1 || m_port > 65535) {
        
        string text("Error: Invalid port number.\n");
        Exception e(text);
        throw (e);
    }

    m_filename.assign(argv[2]);
}

void Application::run() throw (Exception) {

    Logger& logger = Logger::instance();
    logger.trace("Application::run()");

    m_resolver.init(m_filename);
    m_server.init(m_port);
    m_server.run();
}
