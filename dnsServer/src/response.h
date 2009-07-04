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
/**
 *  Class that represents the DNS Response and is able to code itself in its
 *  corresponding message format.
 */
class Response : public Message {
public:
    /**
     *  Response Code
     */
    enum Code { Ok=0, FormatError, ServerFailure, NameError,
                NotImplemented, Refused };

    /**
     *  Constructor.
     */
    Response() : Message(Message::Response) { }

    /**
     *  Destructor
     */
    virtual ~Response() { }

    /**
     *  Function that codes the response message in its format.
     *  @param buffer The buffer to code the query into.
     *  @return The size of the buffer coded
     */
    int code(char* buffer) throw();

    /**
     *  Function that decodes the response message in its format.
     *  @param buffer The buffer to decode the response into.
     *  @param size The size of the buffer to decode
     */
    void decode(const char* buffer, int size) throw();

    /**
     *  Returns the response message as a string text
     *  @return The string text with the response information.
     */
    std::string asString() const throw();

    void setRCode(Code code) throw() { m_rcode = code; }
    void setName(const std::string& value) throw() { m_name = value; }
    void setType(const uint value) throw() { m_type = value; }
    void setClass(const uint value) throw() { m_class = value; }
    void setTtl(const uint value) throw() { m_ttl = value; }
    void setRdLength(const uint value) throw() { m_rdLength = value; }
    void setRdata(const std::string& value) throw() { m_rdata = value; }
    
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
#endif	/* _DNS_RESPONSE_H */

