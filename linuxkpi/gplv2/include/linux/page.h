#include_next <linux/page.h>
#ifndef clflush
#define	clflush(addr)	clflush((unsigned long)(addr))
#endif
