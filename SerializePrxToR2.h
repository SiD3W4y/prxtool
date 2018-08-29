#ifndef __SERIALIZEPRXTOR2__
#define __SERIALIZEPRXTOR2__

#include <stdio.h>
#include "SerializePrx.h"

// Important note: This will only serialize the imports because this is all I needed
// Feel free to implement the other functions if you need to

class CSerializePrxToR2: public CSerializePrx
{
	FILE *m_fpOut;

	virtual bool StartFile() { return true; };
	virtual bool EndFile() { return true; };
	virtual bool StartPrx(const char *szFilename, const PspModule *mod, u32 iSMask) { return true; };
	virtual bool EndPrx() { return true; };
	virtual bool StartSects() { return true; };
	virtual bool SerializeSect(int num, ElfSection &sect) { return true; };
	virtual bool EndSects() { return true; };
	virtual bool StartImports();
	virtual bool SerializeImport(int num, const PspLibImport *imp);
	virtual bool EndImports() { return true; };
	virtual bool StartExports() { return true; };
	virtual bool SerializeExport(int num, const PspLibExport *exp) { return true; };
	virtual bool EndExports() { return true; };
	virtual bool StartRelocs() { return true; };
	virtual bool SerializeReloc(int count, const ElfReloc *rel) { return true; };
	virtual bool EndRelocs() { return true; };

	public:
	CSerializePrxToR2(FILE *out);
	~CSerializePrxToR2();
};

#endif
