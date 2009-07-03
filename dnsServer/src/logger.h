/* 
 * File:   logger.h
 * Author: tomas
 *
 * Created on June 30, 2009, 5:18 PM
 */

#ifndef _DNS_LOGGER_H
#define	_DNS_LOGGER_H

#include <fstream>
#include <sstream>
#include <string>

namespace dns {

class Logger {
public:
    static Logger& instance() throw ();

    void trace(const char* text) throw();
    void trace(std::string& text) throw();
    void trace(std::ostringstream& text) throw();

protected:
    Logger() { }
    ~Logger() { _file.close(); }

private:
    static Logger* _instance;
    static std::ofstream _file;

};
}
#endif	/* _LOGGER_H */

