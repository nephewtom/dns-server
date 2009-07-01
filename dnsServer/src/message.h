/* 
 * File:   message.h
 * Author: torti
 *
 * Created on 29 de junio de 2009, 17:39
 */

#ifndef _DNS_MESSAGE_H
#define	_DNS_MESSAGE_H

namespace dns {

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

class Message {
public:
    enum Type { Query=0, Response };

    uint getID() const throw() { return m_id; }
    uint getQdCount() const throw() { return m_qdCount; }
    //...

    void setID(uint id) throw() { m_id = id; }
    void setAnCount(uint count) throw() { m_anCount = count; }
    //...

protected:
    uint m_id;
    uint m_qr;
    uint m_opcode;
    //...
    uint m_rcode;
    
    uint m_qdCount;
    uint m_anCount;
    uint m_nsCount;
    uint m_arCount;

    static const uint HDR_OFFSET = 12;

    Message(Type type) : m_qr(type) { }
    virtual ~Message() { }

    void decode_hdr(const char* buffer) throw ();
    void code_hdr(char* buffer) throw ();

    int get16bits(const char*& buffer) throw();
    void put16bits(char*& buffer, uint value) throw ();
    void put32bits(char*& buffer, ulong value) throw ();

    void print_buffer(const char* buffer, int size) throw();
    
private:
    static const uint QR_MASK = 0x80;
    static const uint OPCODE_MASK = 0x78;
    //...
    static const uint RCODE_MASK = 0x0F;
};
}
#endif	/* _MESSAGE_H */

