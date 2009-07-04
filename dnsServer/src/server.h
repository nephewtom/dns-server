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

/**
 *  Server class is a socket server that receive queries and answer responses to
 *  those queries. It has a @ref Query and a @ref Response class attributtes to
 *  code and decode the messages received on the socket buffer.
 */
class Server {
public:
    /**
     *  Constructor.
     *  Creates a socket Server.
     *  @param resolver The object @ref Resolver from the application.
     */
    Server(Resolver& resolver) : m_resolver(resolver)
        { }

    /**
     *  Destructor
     */
    virtual ~Server() { }

    /**
     *  Initializes the server creating a UDP datagram socket and binding it to
     *  the INADDR_ANY address and the port passed.
     *  @param port Port number where the socket is binded.
     */
    void init(int port) throw(Exception);

    /**
     *  The socket server runs in an infinite loop, waiting for queries and
     *  handling them through the @ref Resolver and sending back the responses.
     */
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

#endif	/* _DNS_SERVER_H */

