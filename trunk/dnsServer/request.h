/* 
 * File:   request.h
 * Author: torti
 *
 * Created on 26 de junio de 2009, 13:01
 */

#ifndef _REQUEST_H
#define	_REQUEST_H

namespace dns {

class Request {
public:
    Request();
    Request(const Request& orig);
    virtual ~Request();
private:

};
}
#endif	/* _REQUEST_H */

