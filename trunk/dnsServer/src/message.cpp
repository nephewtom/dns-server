/* 
 * File:   message.cpp
 * Author: torti
 * 
 * Created on 29 de junio de 2009, 17:39
 */

#include <iostream>
#include <iomanip>
#include <netinet/in.h>
#include "message.h"

using namespace dns;
using namespace std;

void Message::decode_hdr(const char* buffer) throw () {

    m_ID = get16bits(buffer);
    cout << "ID: " << showbase << hex << m_ID << endl;
    buffer += 2;

    int parameters = get16bits(buffer);
    m_QR = parameters & 0x80;
    m_opcode = parameters & 0x78;
    cout << "parameters: " << parameters;
    cout << " [ QR: " << m_QR << " opCode: " << m_opcode << " ]" << endl;
    buffer += 2;

    m_qdCount = get16bits(buffer);
    cout << "QDcount: " << m_qdCount << endl;
    buffer += 2;

    m_anCount = get16bits(buffer);
    cout << "ANcount: " << m_anCount << endl;
    buffer += 2;

    m_nsCount = get16bits(buffer);
    cout << "NScount: " << m_nsCount << endl;
    buffer += 2;

    m_arCount = get16bits(buffer);
    cout << "ARcount: " << m_arCount << endl;
}

void Message::print_buffer(const char* buffer, int size) throw () {

    cout << endl << "Buffer: " << dec << size << " bytes read" << endl;
    cout << "---------------------------------" << setfill('0');

    for (int i = 0; i < size; i++) {
        if ((i % 10) == 0) {
            cout << endl << setw(2) << i << ": ";
        }
        unsigned char c = buffer[i];
        cout << hex << setw(2) << int(c) << " " << dec;
    }
    cout << endl << setfill(' ');
    cout << "---------------------------------" << endl;
}

int Message::get16bits(const char* buffer) throw () {

    int value = static_cast<unsigned char> (buffer[0]);
    value = value << 8;
    value += static_cast<unsigned char> (buffer[1]);
    //value = ntohs(value);
    return value;
}
