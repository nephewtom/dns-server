/* 
 * File:   response.cpp
 * Author: torti
 * 
 * Created on 29 de junio de 2009, 3:45
 */

#include "message.h"
#include "response.h"

using namespace std;
using namespace dns;

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
}

void Response::code_name(char*& buffer) throw() {

    int start, end; // indexes

    while ((end = m_name.find('.', start)) != string::npos) {

        *buffer = end - start; // Write size
        for (int i=start; i<end; i++) {

            *buffer++ = m_name[i];
        }
        start = end + 1; // Skip '.'
    }

    for (int i=start; i<m_name.size(); i++) {

        *buffer++ = m_name[i];
    }

    *buffer++ = 0;
}