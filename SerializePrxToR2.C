#include <stdio.h>
#include "SerializePrxToR2.h"
#include "NidNames.h"

static const char *getNameForNid(unsigned int nid)
{
	int count = getNidListCount();

	for(int i=0; i < count; i++) {
		if(nid_list[i].id == nid)
			return nid_list[i].name;
	}
	
	return NULL;
}

CSerializePrxToR2::CSerializePrxToR2(FILE *out)
{
	m_fpOut = out;	
}

CSerializePrxToR2::~CSerializePrxToR2()
{
	fflush(m_fpOut);
}

bool CSerializePrxToR2::StartImports()
{
	fprintf(m_fpOut, "fs symbols\n");

	return true;
}

bool CSerializePrxToR2::SerializeImport(int num, const PspLibImport *imp)
{
	
	for(int i=0; i < imp->f_count; i++) {
		PspEntry entry = imp->funcs[i];
		const char *name = getNameForNid(entry.nid);
		
		if(name == NULL)
			name = entry.name;
		
		fprintf(m_fpOut, "f sym.%s @ 0x%08x\n", name, entry.addr);
	}
	
	return true;
}
