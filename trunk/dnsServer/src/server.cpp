/* 
 * File:   server.cpp
 * Author: tomas
 * 
 * Created on June 26, 2009, 11:58 AM
 */

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <errno.h>

#include "server.h"
#include "resolver.h"

using namespace std;
using namespace dns;

void Server::init(int port) throw (Exception) {

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    cout << "sockfd=" << sockfd << endl;

    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons(port);

    int rbind = bind(sockfd, (struct sockaddr *) & m_address, sizeof (struct sockaddr_in));
    
    if (rbind != 0) {
        string text("Could not bind: ");
        text += strerror(errno);
        Exception e(text);
        throw(e);
    }

}

void Server::run() throw () {

    cout << "DNS Server running..." << endl;

    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in clientAddress;
    socklen_t addrLen = sizeof (struct sockaddr_in);

    while (true) {
        int nbytes = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *) &clientAddress, &addrLen);

        m_request.decode(buffer, nbytes);
        m_resolver.process(m_request, m_response);

    }
}
