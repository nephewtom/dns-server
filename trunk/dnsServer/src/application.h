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

/**
 *  Application class is a terminal application that parses arguments from
 *  command line. It has a socket @ref Server to receive queries and answer
 *  responses to those queries, and a @ref Resolver that handles the query and
 *  resolves the domain names contained on it.
 */
class Application {
public:
    /**
     *  Constructor.
     *  Creates a Domain Server Application started from a terminal.
     */
    Application() : m_server(m_resolver) { }

    /**
     *  Destructor
     */
    virtual ~Application() { }

    /**
     *  Parse the port and hosts file from the arguments of main() function
     *  @param argc Number of arguments passed
     *  @param argv Array of arguments
     */
    void parse_arguments(int argc, char** argv) throw (Exception);

    /**
     *  Starts the application. Initialize the @ref Resolver and the @ref Server.
     */
    void run() throw(Exception);

private:
    int m_port;
    std::string m_filename;

    Resolver m_resolver;
    Server m_server;
};
}

#endif	/* _DNS_APPLICATION_H */

