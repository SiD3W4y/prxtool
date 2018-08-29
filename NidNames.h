#ifndef __NIDNAMES__
#define __NIDNAMES__


typedef struct nidname_t {
	unsigned int id;
	const char *name;
} NidName;

extern NidName nid_list[];
int getNidListCount(); // Get number of Nids

#endif
