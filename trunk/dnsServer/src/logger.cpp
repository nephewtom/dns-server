/* 
 * File:   logger.cpp
 * Author: tomas
 * 
 * Created on June 30, 2009, 5:18 PM
 */

#include "logger.h"

using namespace dns;

// static
Logger* Logger::_instance = 0;

Logger& Logger::instance() throw () {

    if (_instance == 0) {
        _instance == new Logger();
    }

    return *_instance;
}
