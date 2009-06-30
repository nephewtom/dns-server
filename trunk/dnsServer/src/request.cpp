/* 
 * File:   request.cpp
 * Author: torti
 * 
 * Created on 26 de junio de 2009, 13:01
 */

#include <iostream>
#include "request.h"

using namespace std;
using namespace dns;

Request::Request() {
}

Request::~Request() {
}

void Request::decode(const char* buffer, int nbytes) throw() {

    print_buffer(buffer, nbytes);
    decode_hdr(buffer);
    buffer += HDR_OFFSET;
    
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
    cout << "Qname: " << m_qName << endl;

    m_qType = get16bits(buffer);
    cout << "Qtype: " << m_qType << endl;

    buffer += 2;
    m_qClass = get16bits(buffer);
    cout << "Qclass: " << m_qClass << endl << noshowbase ;
}



