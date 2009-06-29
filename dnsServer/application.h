/* 
 * File:   application.h
 * Author: tomas
 *
 * Created on June 27, 2009, 11:20 AM
 */

#ifndef _DNS_APPLICATION_H
#define	_DNS_APPLICATION_H

#include "server.h"
#include "resolver.h"

namespace dns {

class Application {
public:
    Application() : m_server(m_resolver) { }
    void run() throw();

protected:

    Resolver m_resolver;
    Server m_server;
};
}

#endif	/* _APPLICATION_H */

