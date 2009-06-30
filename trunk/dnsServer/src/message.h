/* 
 * File:   message.h
 * Author: torti
 *
 * Created on 29 de junio de 2009, 17:39
 */

#ifndef _DNS_MESSAGE_H
#define	_DNS_MESSAGE_H

namespace dns {

typedef unsigned int uint;

class Message {
public:
    Message() { }
    virtual ~Message() { }

    void print_buffer(const char* buffer, int size) throw();

protected:
    void decode_hdr(const char* buffer) throw ();
    int get16bits(const char* buffer) throw();
    static const int HDR_OFFSET = 12;

    uint m_ID;
    uint m_QR;
    uint m_opcode;
    //...
    
    uint m_qdCount;
    uint m_anCount;
    uint m_nsCount;
    uint m_arCount;
    
};
}
#endif	/* _MESSAGE_H */

