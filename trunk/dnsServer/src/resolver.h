/* 
 * File:   resolver.h
 * Author: tomas
 *
 * Created on 29 de junio de 2009, 3:47
 */

#ifndef _DNS_RESOLVER_H
#define	_DNS_RESOLVER_H

#include "exception.h"

namespace dns {

class Query;
class Response;

/**
 *  Resolver is the class that handles the @ref Query and resolves the domain
 *  names contained on it. It processes the @ref Query and set the appropiate
 *  values in the @ref Response.
 */
class Resolver {
public:

    /**
     *  Constructor.
     *  Creates the Resolver.
     */
    Resolver() : m_record_list(0) { }

    /**
     *  Destructor
     */
    virtual ~Resolver() { deleteList(); }

    /**
     *  Open the hosts file and read it to stores the ipAddress-hostname pairs.
     *  @param filename Name of the file containing the pairs.
     */
    void init(const std::string& filename) throw (Exception);

    /**
     *  Process the query and sets the response to that query. @ref Record
     *  @param query @ref Query that will be processed.
     *  @param response @ref Response that will be answered.
     */
    void process(const Query& query, Response& response) throw ();

// Es raro que se quiera heredar de Resolver, pero de esta forma,
// la documentación aparece en doxygen.
protected:
    /**
     *  Extracts the ipAddress-hostname pair from a string line and adds it to
     *  the list of records.
     *  @param line Line read from the hosts file containing the ipAddress-hostname info
     */
    void store(const std::string& line) throw ();

    /**
     *  Structure to hold the ipAddress-hostname pairs.
     */
    struct Record {
        /**
         *  Constructor.
         *  @param ip String holding the IP address in dot notation.
         *  @param domain String holding the domain name.
         */
        Record(std::string& ip, std::string& domain) : ipAddress(ip),
               domainName(domain), next(0) { }

        /**
         *  Constructor
         */
        Record() : next(0) { }

        /**
         *  IP address in dot notation.
         */
        std::string ipAddress;


        /**
         *  Domain name.
         */
        std::string domainName;

        /**
         *  Pointer to next record on the list
         */
        Record* next;
    };
    /**
     *  Pointer to the start of the list of records.
     */
    Record* m_record_list;

    /**
     *  Adds new record to the list
     *  @param record Pointer to the record to add
     */
    void add(Record* record) throw ();

    /**
     *  Deletes all records from the list. Used in destructor
     */
    void deleteList() throw();


    /**
     *  Prints all records from the list.
     */
    void print_records() throw ();

    /**
     *  Covert IN-ADDR.ARPA domain to an IP addrress in dot notation
     *  @param domain The domain name
     *  @return The IP addrress formatted in dot notation.
     */
    std::string convert(const std::string& domain) throw();

    /**
     *  Finds in the list the domanin corresponding to the ipAddress
     *  @param ipAddress IP addrress in dot notation
     *  @return The domain name found. An empty string if no domain was found.
     */
    const std::string find(const std::string& ipAddress) throw ();
};
}
#endif	/* _DNS_RESOLVER_H */

