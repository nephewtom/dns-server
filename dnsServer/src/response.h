/* 
 * File:   response.h
 * Author: tomas
 *
 * Created on 29 de junio de 2009, 4:45
 */

#ifndef _DNS_RESPONSE_H
#define	_DNS_RESPONSE_H

#include "message.h"

namespace dns {

class Response : public Message {
public:
    enum Code { Ok=0, FormatError, ServerFailure, NameError,
                NotImplemented, Refused };

    Response() : Message(Message::Response) { }
    virtual ~Response() { }

    void setRCode(Code code) throw() { m_rcode = code; }
    void setName(const std::string& value) throw() { m_name = value; }
    void setType(const uint value) throw() { m_type = value; }
    void setClass(const uint value) throw() { m_class = value; }
    void setTtl(const uint value) throw() { m_ttl = value; }
    void setRdLength(const uint value) throw() { m_rdLength = value; }
    void setRdata(const std::string& value) throw() { m_rdata = value; }

    std::string asString() const throw();

    int code(char* buffer) throw();
    
private:
    std::string m_name;
    uint m_type;
    uint m_class;
    ulong m_ttl;
    uint m_rdLength;
    std::string m_rdata;

    void code_domain(char*& buffer, const std::string& domain) throw();
};
}
#endif	/* _RESPONSE_H */

