/* 
 * File:   server.cpp
 * Author: tomas
 * 
 * Created on June 27, 2009, 11:58 AM
 */

#include <iostream>

#include "server.h"

using namespace std;
using namespace dns;

Server::Server() {
}

Server::Server(const Server& orig) {
}

Server::~Server() {
}

void Server::init() throw() {
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    cout << "sockfd=" << sockfd << endl;
}

void Server::run() throw() {

}