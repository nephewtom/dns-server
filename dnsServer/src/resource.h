/* 
 * File:   resource.h
 * Author: tomas
 *
 * Created on June 4, 2009, 1:55 AM
 */

#ifndef _DNS_RR_H
#define	_DNS_RR_H

namespace dns {

struct RR {

    struct Type {

        enum Value { A=1, NS, MD, MF, CNAME, SOA, MB, MG, MR,
                     NUL, WKS, PTR, HINFO, MINFO, MX, TXT };
    };

    struct Class {

        enum Value { IN=1, CS, CH, HS };
    };
};
}

#endif	/* _RR_H */

