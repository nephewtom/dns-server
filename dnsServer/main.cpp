/*
 * File:   main.cpp
 * Author: torti
 *
 * Created on 22 de junio de 2009, 15:37
 */

#include <iostream>
#include <sys/socket.h>
using namespace std;
/*
 *
 */
int main(int argc, char** argv) {

    cout << "Hello Cpp!" << endl;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    cout << "sockfd=" << sockfd << endl;
    return 0;
}
