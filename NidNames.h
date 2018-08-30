#ifndef __NIDNAMES__
#define __NIDNAMES__

typedef struct nidname_t {
	unsigned int id;
	const char *name;
} NidName;

const char *nidGetName(unsigned int nid);

#endif
