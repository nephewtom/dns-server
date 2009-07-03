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

class Query : public Message {
public:
    Query() : Message(Message::Query) { }
    virtual ~Query() { }

    const std::string& getQName() const throw () { return m_qName; }
    const uint getQType() const throw () { return m_qType; }
    const uint getQClass() const throw () { return m_qClass; }
    std::string asString() const throw();

    void decode(const char* buffer, int size) throw();
    
private:
    std::string m_qName;
    uint m_qType;
    uint m_qClass;

    void decode_qname(const char*& buffer) throw();
};
}
#endif	/* _REQUEST_H */

