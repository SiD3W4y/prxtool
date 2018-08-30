#include <stdio.h>
#include "SerializePrxToR2.h"
#include "NidNames.h"


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
		fprintf(m_fpOut, "f sym.%s @ 0x%08x\n", entry.name, entry.addr);
	}
	
	return true;
}
