/* 
 * File:   request.h
 * Author: torti
 *
 * Created on 26 de junio de 2009, 13:01
 */

#ifndef _DNS_REQUEST_H
#define	_DNS_REQUEST_H

#include <string>
#include "message.h"

namespace dns {

class Request : public Message {
public:
    Request();
    virtual ~Request();

    void decode(const char* buffer, int nbytes) throw();
    
private:
    std::string m_qName;
    int m_qType;
    int m_qClass;
};
}
#endif	/* _REQUEST_H */

