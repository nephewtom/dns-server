/* 
 * File:   request.cpp
 * Author: torti
 * 
 * Created on 26 de junio de 2009, 13:01
 */
#include <iostream>

#include "query.h"

using namespace std;
using namespace dns;

string Query::asString() const throw() {

    Message::asString();

    cout << "From Query::asString()" << endl;

    cout << "Qname: " << m_qName << endl;
    cout << "Qtype: " << m_qType << endl;
    cout << "Qclass: " << m_qClass << endl << noshowbase << dec;

    return string();
}

void Query::decode(const char* buffer, int size) throw() {

    print_buffer(buffer, size);

    decode_hdr(buffer);
    buffer += HDR_OFFSET;
    
    decode_qname(buffer);

    m_qType = get16bits(buffer);
    m_qClass = get16bits(buffer);
}

void Query::decode_qname(const char*& buffer) throw() {

    m_qName.clear();

    int length = *buffer++;
    while (length != 0) {
        for (int i = 0; i < length; i++) {
            char c = *buffer++;
            m_qName.append(1, c);
        }
        length = *buffer++;
        if (length != 0) m_qName.append(1,'.');
    }
}