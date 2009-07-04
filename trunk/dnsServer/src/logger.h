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

/**
 *  Logger is a helper class that allows to trace text messages to a log file.
 *  It is a single instance class or also known as Singleton.
 */
class Logger {
public:
    /**
     *  Instanciates the one and only Logger object.
     *  @return A reference to the one and only Logger object.
     */
    static Logger& instance() throw ();

    /**
     *  Trace the message text to the log file.
     *  @param text Message text to log.
     */
    void trace(const char* text) throw();

    /**
     *  Trace the message text to the log file.
     *  @param text Message text to log.
     */
    void trace(std::string& text) throw();

    /**
     *  Trace the message text to the log file.
     *  @param text Message text to log.
     */
    void trace(std::ostringstream& text) throw();

    /**
     *  Trace the error message to the log file.
     *  @param text Error message to log.
     */
    void error(const char* text) throw();

    /**
     *  Trace the error message to the log file.
     *  @param text Error message to log.
     */
    void error(std::string& text) throw();

protected:
    /**
     *  Constructor.
     *  Creates the one and only Logger object.
     */
    Logger() { }

    /**
     *  Destructor
     */
    ~Logger() { _file.close(); }

private:
    static Logger* _instance;
    static std::ofstream _file;

};
}
#endif	/* _DNS_LOGGER_H */

