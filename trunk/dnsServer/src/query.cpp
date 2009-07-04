/* 
 * File:   query.cpp
 * Author: tomas
 * 
 * Created on 26 de junio de 2009, 13:01
 */
#include <iostream>
#include <sstream>

#include "logger.h"
#include "query.h"

using namespace std;
using namespace dns;

string Query::asString() const throw() {

    ostringstream text;
    text << endl << "QUERY { ";
    text << Message::asString();
    text << "\tQname: " << m_qName << endl;
    text << "\tQtype: " << m_qType << endl;
    text << "\tQclass: " << m_qClass;
    text << " }" << dec;

    return text.str();
}

int Query::code(char* buffer) throw() {

    // Only needed for the DNS client
    return 0;
}

void Query::decode(const char* buffer, int size) throw() {

    Logger& logger = Logger::instance();
    logger.trace("Query::decode()");
    log_buffer(buffer, size);

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