/* 
 * File:   resolver.cpp
 * Author: torti
 * 
 * Created on 29 de junio de 2009, 3:47
 */

#include <string>
#include <iostream>
#include <fstream>

#include "resolver.h"
#include "response.h"
#include "query.h"
#include "resource.h"

using namespace std;
using namespace dns;

void Resolver::init(const std::string& filename) throw (Exception) {

    ifstream file(filename.data());

    if (!file) {

        string text("Could not open file: ");
        text += filename;
        Exception e(text);
        throw (e);
    }

    //m_record_list = new Record();

    string line;
    while (!file.eof()) {

        getline(file, line);
        store(line);
    }

    file.close();

    print_records();
}

void Resolver::store(const string& line) throw () {

    cout << "Resolver::store()" << endl;

    string::size_type ipAddresEndPos = line.find_first_of(" ");
    if (ipAddresEndPos == string::npos) return;

    string::size_type domainNameStartPos = line.find_last_of(" ");
    if (domainNameStartPos == string::npos) return;
    domainNameStartPos += 1;

    string ipAddress(line, 0, ipAddresEndPos);
    string domainName(line, domainNameStartPos, line.length());

    Record* record = new Record(ipAddress, domainName);
    add(record);
}

void Resolver::add(Record* newone) throw() {

    cout << "Resolver::add()" << endl;

    cout << "Adding Record: " << newone->ipAddress.data();
    cout << "-" << newone->domainName.data() << endl;

    Record* record = m_record_list;
    if (record == 0) {
        m_record_list = newone;
        return;
    }

    while (record->next != 0) {
        record = record->next;
    }
    record->next = newone;
}

void Resolver::print_records() throw() {

    cout << "PRINT RECORDS:" << endl;

    Record* record = m_record_list;
    if (record == 0) {
        cout << "No records on list." << endl;
        return;
    }

    while (record != 0) {
        cout << "Record: " << record->ipAddress.data();
        cout << " - " << record->domainName.data() << endl;
        record = record->next;
    }
}

const string Resolver::find(string& ipAddress) throw () {

    string domainName;

    Record* record = m_record_list;
    while (record != 0) {
        
        if (record->ipAddress == ipAddress) {

            domainName = record->domainName;
            break;
        }
        record = record->next;
    }

    return domainName;
}

void Resolver::process(const Query& query, Response& response) throw () {

    cout << "Resolver::process()" << endl;

    string ipAddress = query.getQName();
    string domainName = find( ipAddress );

    cout << "domainName:" << domainName << endl;

    response.setID( query.getID() );
    response.setAnCount(1);
    response.setType( query.getQType() );
    response.setClass( query.getQClass() );

    if (domainName.empty()) {
        response.setRCode(Response::NameError);
    }
    else {
        response.setRCode(Response::Ok);
        response.setName(domainName);
    }
}

