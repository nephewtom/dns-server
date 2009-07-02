/* 
 * File:   response.cpp
 * Author: torti
 * 
 * Created on 29 de junio de 2009, 3:45
 */
#include <iostream>

#include "message.h"
#include "response.h"

using namespace std;
using namespace dns;

string Response::asString() const throw() {

    Message::asString();

    cout << "name: " << m_name << endl;
    cout << "type: " << m_type << endl;
    cout << "class: " << m_class << endl;
    cout << "ttl: " << m_ttl << endl;
    cout << "rdLength: " << m_rdLength << endl;
    cout << "rdata: " << m_rdata << endl << noshowbase << dec;

    return string();
}

int Response::code(char* buffer) throw() {

    char* bufferBegin = buffer;

    code_hdr(buffer);
    buffer += HDR_OFFSET;

    code_name(buffer);

    put16bits(buffer, m_type);
    put16bits(buffer, m_class);
    put32bits(buffer, m_ttl);
    put16bits(buffer, m_rdLength);
    
    int size = buffer - bufferBegin;
    print_buffer(bufferBegin, size);

    return size;
}

void Response::code_name(char*& buffer) throw() {

    int start, end; // indexes

    while ((end = m_name.find('.', start)) != string::npos) {

        *buffer++ = end - start; // label length octet
        for (int i=start; i<end; i++) {

            *buffer++ = m_name[i]; // label octets
        }
        start = end + 1; // Skip '.'
    }

    *buffer++ = m_name.size() - start; // last label length octet
    for (int i=start; i<m_name.size(); i++) {

        *buffer++ = m_name[i]; // last label octets
    }

    *buffer++ = 0;
}