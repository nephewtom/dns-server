/* 
 * File:   server.h
 * Author: tomas
 *
 * Created on June 27, 2009, 11:58 AM
 */

#ifndef _DNS_SERVER_H
#define	_DNS_SERVER_H

#include <netinet/in.h>
#include "request.h"
#include "response.h"

namespace dns {

class Resolver;

class Server {
public:
    Server(Resolver& resolver) : m_resolver(resolver) { }
    virtual ~Server() { }

    void init() throw();
    void run() throw();
    
private:
    static const int m_defaul_port = 53;
    static const int MAX_BUFFER_SIZE = 1024;

    struct sockaddr_in m_address;
    int sockfd;

    Request m_request;
    Response m_response;

    Resolver& m_resolver;
};
}

#endif	/* _SERVER_H */

