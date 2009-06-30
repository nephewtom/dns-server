/* 
 * File:   resolver.h
 * Author: torti
 *
 * Created on 29 de junio de 2009, 3:47
 */

#ifndef _DNS_RESOLVER_H
#define	_DNS_RESOLVER_H

namespace dns {

class Request;
class Response;

class Resolver {
public:
    Resolver() { }
    virtual ~Resolver() { }

    void process(const Request& request, Response& response) throw();
private:

};
}
#endif	/* _RESOLVER_H */

