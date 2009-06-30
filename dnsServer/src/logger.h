/* 
 * File:   logger.h
 * Author: tomas
 *
 * Created on June 30, 2009, 5:18 PM
 */

#ifndef _DNS_LOGGER_H
#define	_DNS_LOGGER_H

namespace dns {

class Logger {
public:
    static Logger& instance() throw ();

protected:
    Logger() { }

private:
    static Logger* _instance;

};
}
#endif	/* _LOGGER_H */

