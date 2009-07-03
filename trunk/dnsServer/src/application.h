/* 
 * File:   application.h
 * Author: tomas
 *
 * Created on June 27, 2009, 16:20 AM
 */

#ifndef _DNS_APPLICATION_H
#define	_DNS_APPLICATION_H

#include "exception.h"
#include "server.h"
#include "resolver.h"

namespace dns {

class Application {
public:
    Application() : m_server(m_resolver) { }
    void parse_arguments(int argc, char** argv) throw (Exception);
    void run() throw(Exception);

private:
    int m_port;
    std::string m_filename;

    Resolver m_resolver;
    Server m_server;
};
}

#endif	/* _APPLICATION_H */

