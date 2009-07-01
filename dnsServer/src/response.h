/* 
 * File:   response.h
 * Author: torti
 *
 * Created on 29 de junio de 2009, 3:45
 */

#ifndef _DNS_RESPONSE_H
#define	_DNS_RESPONSE_H

#include <string>
#include "message.h"

namespace dns {

class Response : public Message {
public:
    enum Code { Ok=0, FormatError, ServerFailure, NameError,
                NotImplemented, Refused };

    Response() : Message(Message::Response) { }
    virtual ~Response() { }

    void setRCode(Code code) throw() { m_rcode = code; }
    void setName(const std::string& name) throw() { m_name = name; }

    int code(char* buffer) throw();
    
private:
    std::string m_name;
    uint m_type;
    uint m_class;
    ulong m_ttl;
    uint m_rdLength;

    void code_name(char*& buffer) throw();
};
}
#endif	/* _RESPONSE_H */

