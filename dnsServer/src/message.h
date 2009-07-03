/* 
 * File:   message.h
 * Author: tomas
 *
 * Created on 29 de junio de 2009, 17:39
 */

#ifndef _DNS_MESSAGE_H
#define	_DNS_MESSAGE_H

#include <string>

namespace dns {

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

class Message {
public:
    enum Type { Query=0, Response };

    uint getID() const throw() { return m_id; }
    uint getQdCount() const throw() { return m_qdCount; }
    uint getAnCount() const throw() { return m_anCount; }
    uint getNsCount() const throw() { return m_nsCount; }
    uint getArCount() const throw() { return m_arCount; }

    void setID(uint id) throw() { m_id = id; }
    void setQdCount(uint count) throw() { m_qdCount = count; }
    void setAnCount(uint count) throw() { m_anCount = count; }
    void setNsCount(uint count) throw() { m_nsCount = count; }
    void setArCount(uint count) throw() { m_arCount = count; }

protected:
    static const uint HDR_OFFSET = 12;

    uint m_id;
    uint m_qr;
    uint m_opcode;
    uint m_aa;
    uint m_tc;
    uint m_rd;
    uint m_ra;
    uint m_rcode;
    
    uint m_qdCount;
    uint m_anCount;
    uint m_nsCount;
    uint m_arCount;


    Message(Type type) : m_qr(type) { }
    virtual ~Message() { }
    virtual std::string asString() const throw();

    void decode_hdr(const char* buffer) throw ();
    void code_hdr(char* buffer) throw ();

    int get16bits(const char*& buffer) throw();
    void put16bits(char*& buffer, uint value) throw ();
    void put32bits(char*& buffer, ulong value) throw ();

    void print_buffer(const char* buffer, int size) throw();
    
private:
    static const uint QR_MASK = 0x8000;
    static const uint OPCODE_MASK = 0x7800;
    static const uint AA_MASK = 0x0400;
    static const uint TC_MASK = 0x0200;
    static const uint RD_MASK = 0x0100;
    static const uint RA_MASK = 0x8000;
    static const uint RCODE_MASK = 0x000F;
};
}
#endif	/* _MESSAGE_H */

