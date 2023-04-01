#include <stdio.h>
/* define low level data structures of unix inter networking */

/* 

	s = socket(family, type, protocol) 
*/
struct sockaddr {
	short sa_family; /* address family */
	char sa_data[14]; /* up to 13 octets of address */
};

struct sockaddr_in {
	short sin_family; /* address family */
	short sin_port; /* 2 octet port number */
	long sin_addr; /* 4 octet IP address */
	char sin_data[8]; /* unused */
};
/*

	hostent = gethostbyname(name)
*/
struct hostent {
	char *h_name; /* official name of host */
	char **h_alias; /* list of aliases */
	int h_addrtype; /* address type */
	int h_length;	/* length of address */
	char **h_addr_list; /* list of addresses */
};
/*
	servent = getservbyname(family, service)
*/
struct servent {
	char *s_name;	/* official name of service */
	char **s_aliases; /* list of aliases */
	int s_port; /* 16 bit port number */
	char *s_proto; /* protocol family */
};

