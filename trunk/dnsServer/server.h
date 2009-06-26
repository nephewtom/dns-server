/* 
 * File:   server.h
 * Author: tomas
 *
 * Created on June 27, 2009, 11:58 AM
 */

#ifndef _SERVER_H
#define	_SERVER_H

#include <sys/socket.h>

namespace dns {

class Server {
public:
    Server();
    Server(const Server& orig);
    virtual ~Server();

    void init() throw();
    void run() throw();
    
private:

};
}

#endif	/* _SERVER_H */

