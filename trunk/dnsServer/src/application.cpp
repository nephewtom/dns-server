/* 
 * File:   application.cpp
 * Author: tomas
 * 
 * Created on June 27, 2009, 11:20 AM
 */

#include <iostream>
#include <stdlib.h>
#include "application.h"

using namespace dns;
using namespace std;

void Application::getCommandLine(int argc, char** argv) throw (exception) {

    cout << "argc=" << argc << endl;

    if (argc != 3) {
        printUsage();
        exception e;
        throw (e);
    }

    for (int i = 0; i < argc; i++) {
        cout << "Parsing arg " << i << ": " << argv[i] << endl;
    }

    int port = atoi(argv[1]);
    if (port < 0 || port > 65535) {
        exception e;
        throw(e);
    }

    m_argFile.assign(argv[2]);
    cout << " m_argFile: " << m_argFile << endl;
    
    //
    //        if (param == ARG_PORT) {
    //            m_argPort = atoi(argv[i++]);
    //        }
    //        else if (param == ARG_FILE) {
    //            m_argFile = argv[i++];
    //        }
    //        else {
    //            cout << " invalid param!"    << endl;
    //        }
    //    }
}

void Application::run() throw () {

    cout << "DNS Server started." << endl;

    m_server.init();
    m_server.run();
}

void Application::printUsage() throw () {

    cout << "Usage: dnsServer <port> <hostsFile>" << endl;
    cout << "Example: dnsServer 9000 hosts.txt" << endl;
}