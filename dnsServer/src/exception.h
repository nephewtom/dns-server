/* 
 * File:   exception.h
 * Author: tomas
 *
 * Created on July 1, 2009, 4:15 AM
 */

#ifndef _DNS_EXCEPTION_H
#define	_DNS_EXCEPTION_H

#include <exception>
#include <string>

namespace dns {

class Exception : public std::exception {
public:
    Exception(std::string& text) : m_text(text) { }
    virtual ~Exception() throw() { }

    const char* what() const throw() {
        
        return m_text.data();
    }

private:
    std::string m_text;
};
}
#endif	/* _EXCEPTION_H */

