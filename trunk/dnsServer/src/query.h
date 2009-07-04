/* 
 * File:   query.h
 * Author: tomas
 *
 * Created on 26 de junio de 2009, 13:01
 */

#ifndef _DNS_REQUEST_H
#define	_DNS_REQUEST_H

#include <string>

#include "message.h"

namespace dns {

/**
 *  Class that represents the DNS Query and is able to code itself in its
 *  corresponding message format.
 */
class Query : public Message {
public:
    /**
     *  Constructor.
     */
    Query() : Message(Message::Query) { }

    /**
     *  Destructor
     */
    virtual ~Query() { }

    /**
     *  Function that codes the query message in its format.
     *  @param buffer The buffer to code the query into.
     *  @return The size of the buffer coded
     */
    int code(char* buffer) throw();

    /**
     *  Function that decodes the query message in its format.
     *  @param buffer The buffer to decode the query into.
     *  @param size The size of the buffer to decode
     */
    void decode(const char* buffer, int size) throw();

    /**
     *  Returns the query message as a string text.
     *  @return The string text with the query information.
     */
    std::string asString() const throw();

    const std::string& getQName() const throw () { return m_qName; }
    const uint getQType() const throw () { return m_qType; }
    const uint getQClass() const throw () { return m_qClass; }
    
private:
    std::string m_qName;
    uint m_qType;
    uint m_qClass;

    void decode_qname(const char*& buffer) throw();
};
}
#endif	/* _DNS_REQUEST_H */

