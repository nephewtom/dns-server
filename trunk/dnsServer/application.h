/* 
 * File:   application.h
 * Author: tomas
 *
 * Created on June 27, 2009, 11:20 AM
 */

#ifndef _APPLICATION_H
#define	_APPLICATION_H

#include "server.h"

namespace dns {

class Application {
public:
    Application();
    Application(const Application& orig);
    virtual ~Application();

    void run() throw();

private:
    Server server;

};
}

#endif	/* _APPLICATION_H */

