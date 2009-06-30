/* 
 * File:   response.h
 * Author: torti
 *
 * Created on 29 de junio de 2009, 3:45
 */

#ifndef _DNS_RESPONSE_H
#define	_DNS_RESPONSE_H

#include "message.h"

namespace dns {

class Response : public Message {
public:
    Response();
    virtual ~Response();
private:

};
}
#endif	/* _RESPONSE_H */

