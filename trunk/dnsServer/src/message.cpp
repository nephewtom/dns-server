/* 
 * File:   message.cpp
 * Author: tomas
 * 
 * Created on 29 de junio de 2009, 17:39
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <netinet/in.h>

#include "logger.h"
#include "message.h"

using namespace dns;
using namespace std;

string Message::asString() const throw() {

    ostringstream text;
    text << "ID: " << showbase << hex << m_id << endl << noshowbase;
    text << "\tfields: [ QR: " << m_qr << " opCode: " << m_opcode << " ]" << endl;
    text << "\tQDcount: " << m_qdCount << endl;
    text << "\tANcount: " << m_anCount << endl;
    text << "\tNScount: " << m_nsCount << endl;
    text << "\tARcount: " << m_arCount << endl;

    return text.str();
}

void Message::decode_hdr(const char* buffer) throw () {

    m_id = get16bits(buffer);

    uint fields = get16bits(buffer);
    m_qr = fields & QR_MASK;
    m_opcode = fields & OPCODE_MASK;
    m_aa = fields & AA_MASK;
    m_tc = fields & TC_MASK;
    m_rd = fields & RD_MASK;
    m_ra = fields & RA_MASK;

    m_qdCount = get16bits(buffer);
    m_anCount = get16bits(buffer);
    m_nsCount = get16bits(buffer);
    m_arCount = get16bits(buffer);
}

void Message::code_hdr(char* buffer) throw () {

    put16bits(buffer, m_id);

    int fields = (m_qr << 15);
    fields += (m_opcode << 14);
    //...
    fields += m_rcode;
    put16bits(buffer, fields);

    put16bits(buffer, m_qdCount);
    put16bits(buffer, m_anCount);
    put16bits(buffer, m_nsCount);
    put16bits(buffer, m_arCount);
}

void Message::log_buffer(const char* buffer, int size) throw () {

    ostringstream text;

    text << "Message::log_buffer()" << endl;
    text << "size: " << size << " bytes" << endl;
    text << "---------------------------------" << setfill('0');

    for (int i = 0; i < size; i++) {
        if ((i % 10) == 0) {
            text << endl << setw(2) << i << ": ";
        }
        uchar c = buffer[i];
        text << hex << setw(2) << int(c) << " " << dec;
    }
    text << endl << setfill(' ');
    text << "---------------------------------";

    Logger& logger = Logger::instance();
    logger.trace(text);
}

int Message::get16bits(const char*& buffer) throw () {

    int value = static_cast<uchar> (buffer[0]);
    value = value << 8;
    value += static_cast<uchar> (buffer[1]);
    buffer += 2;

    return value;
}

void Message::put16bits(char*& buffer, uint value) throw () {

    buffer[0] = (value & 0xFF00) >> 8;
    buffer[1] = value & 0xFF;
    buffer += 2;
}

void Message::put32bits(char*& buffer, ulong value) throw () {

    buffer[0] = (value & 0xFF000000) >> 24;
    buffer[1] = (value & 0xFF0000) >> 16;
    buffer[2] = (value & 0xFF00) >> 16;
    buffer[3] = (value & 0xFF) >> 16;
    buffer += 4;
}
