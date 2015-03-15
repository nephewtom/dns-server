**Ambigüedad en los requisitos planteados:**

**1)** En los requisitos se indica que se debe dar soporte de DNS Inverse Query únicamente.

En la RFC-1035, apartado "6.4. Inverse queries (Optional)", se describe su mecanismo y un ejemplo.

Según este apartado, la "Inverse Query" debe llevar el parametro OPCODE del Header a IQUERY=1, frente a una "Standard Query" que lo lleva a QUERY=0.

**2)** El problema surge al intentar generar un "Inverse Query" con dig, y es que no es posible.

La utilidad dig incluye la opción -x para hacer lo que llama "reverse lookups".

Textualmente del man de dig:

> Reverse lookups — mapping addresses to names — are simplified by the -x option.

Pero esta opción lo que genera es una "Standard Query" con una Question section en la que se indica en el QNAME, la dirección IP invertida añadiendole el sufijo .in-addr.arpa, un QTYPE de tipo PTR (Domain name pointer) y un QCLASS de tipo IN.

Por ejemplo, si se ejecuta:

> dig -x 198.182.196.56

se puede ver en la salida de dig, o mejor con un packet sniffer, que se genera una petición con OPCODE=0 (QUERY) y que en la "Question Section" se incluye:

> QNAME: 56.196.182.198.in-addr.arpa
> QTYPE: PTR
> QCLASS: IN

**3)** La [RFC-3425](http://tools.ietf.org/html/rfc3425): "Obsoleting IQUERY" actualiza la RFC-1035, y declara el uso del Inverse Query como obsoleto:

> The IQUERY method of performing inverse DNS lookups, specified in RFC-1035, has not been generally implemented and has usually been operationally disabled where it has been implemented.  Both reflect a general view in the community that the concept was unwise and that the widely-used alternate approach of using pointer (PTR) queries and reverse-mapping records is preferable.  Consequently, this document deprecates the IQUERY operation, declaring it entirely obsolete. This document updates RFC 1035.

Esto parece dar una explicación de porqué dig no permite este tipo de queries.

Para mapear direcciones IP a nombres de dominio se emplean las "Pointer Queries", que el procedimiento comentado en el punto 2), y que vienen descrito en el apartado "3.5. IN-ADDR.ARPA domain" de la RFC-1035.

<br>
<hr />

<b>Conclusión:</b>

Se ha implementado el servidor asumiendo como obsoleta la IQUERY tal y como se indica en la RFC-3425, y para que funcione con dig se ha implementado el procedimiento de <a href='http://en.wikipedia.org/wiki/Reverse_DNS_lookup'>Reverse lookups</a>, también conocido como <a href='http://www.uic.rsu.ru/doc/inet/tcp_stevens/dns_the.htm#14_5'>Pointer Queries</a> en el libro TCP/IP Illustrated, Volume 1 The Protocols by W. Richard Stevens.