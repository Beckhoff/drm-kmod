#ifndef _GPLV2_LINUX_PAGE_H_
#define	_GPLV2_LINUX_PAGE_H_

#include_next <linux/page.h>

#if defined(__i386__) || defined(__amd64__)
#include <machine/md_var.h>

#ifndef clflush
#define	clflush(addr)	clflush((unsigned long)(addr))
#endif

static inline void
__clflush_cache_range(void *vaddr, unsigned int size)
{
	void *p;

	mb();
	for (p = (void *)((unsigned long)vaddr & ~(cpu_clflush_line_size - 1));
	     p < vaddr + size;
	     p += cpu_clflush_line_size)
		clflushopt(p);
	mb();
}
#define	clflush_cache_range(vaddr, size) __clflush_cache_range(vaddr, size)
#endif

#endif	/* _GPLV2_LINUX_PAGE_H_ */
