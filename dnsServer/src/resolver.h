/* 
 * File:   resolver.h
 * Author: torti
 *
 * Created on 29 de junio de 2009, 3:47
 */

#ifndef _DNS_RESOLVER_H
#define	_DNS_RESOLVER_H

#include "exception.h"

namespace dns {

class Query;
class Response;

class Resolver {
public:

    Resolver() : m_record_list(0) { }
    virtual ~Resolver() { }

    void init(const std::string& filename) throw (Exception);
    void process(const Query& query, Response& response) throw ();

private:
    
    void store(const std::string& line) throw ();

    struct Record {
        Record(std::string& ip, std::string& domain) : ipAddress(ip),
               domainName(domain), next(0) { }
        
        Record() : next(0) { }

        std::string ipAddress;
        std::string domainName;
        Record* next;
    };
    Record* m_record_list;

    void add(Record* record) throw ();
    const std::string find(std::string& ipAddress) throw ();
    void print_records() throw ();
};
}
#endif	/* _RESOLVER_H */

