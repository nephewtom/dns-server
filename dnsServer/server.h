/* 
 * File:   server.h
 * Author: tomas
 *
 * Created on June 27, 2009, 11:58 AM
 */

#ifndef _SERVER_H
#define	_SERVER_H

#include <netinet/in.h>

namespace dns {

class Server {
public:
    Server();
    Server(const Server& orig);
    virtual ~Server();

    void init() throw();
    void run() throw();
    
private:
    static const int m_port = 53;
    struct sockaddr_in m_address;
    int sockfd;

    static const int MAX_BUFFER_SIZE = 1024;
};
}

#endif	/* _SERVER_H */

