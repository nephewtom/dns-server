/* 
 * File:   application.h
 * Author: tomas
 *
 * Created on June 27, 2009, 11:20 AM
 */

#ifndef _DNS_APPLICATION_H
#define	_DNS_APPLICATION_H

#include <string>
#include "server.h"
#include "resolver.h"

namespace dns {

class Application {
public:
    Application() : m_server(m_resolver) { }
    void getCommandLine(int argc, char** argv) throw (std::exception);
    void run() throw();

private:
    int m_argPort;
    std::string m_argFile;

    Resolver m_resolver;
    Server m_server;

    void printUsage() throw();
};
}

#endif	/* _APPLICATION_H */

