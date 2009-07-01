/* 
 * File:   server.h
 * Author: tomas
 *
 * Created on June 27, 2009, 11:58 AM
 */

#ifndef _DNS_SERVER_H
#define	_DNS_SERVER_H

#include <netinet/in.h>
#include "exception.h"
#include "query.h"
#include "response.h"

namespace dns {

class Resolver;

class Server {
public:
    Server(Resolver& resolver) : m_resolver(resolver)
        { }

    virtual ~Server() { }

    void init(int port) throw(Exception);
    void run() throw();
    
private:
    static const int BUFFER_SIZE = 1024;

    struct sockaddr_in m_address;
    int m_sockfd;

    Query m_query;
    Response m_response;

    Resolver& m_resolver;
};
}

#endif	/* _SERVER_H */

