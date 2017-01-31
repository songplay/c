#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void *
amalloc(int size){
    void    *p;
    void    *pp;
    uint32_t    *h;
    
    p = malloc(size + 8);
//	printf("p=0x%p\n", p);
    
    // the header 
    if (((uint32_t) p & 0x3) == 0x0)
	h = (uint32_t *) p;
    else
	h = (uint32_t *) (((uint32_t) p & 0xfffffffc) + 4);

    *h = (uint32_t) p & 3;

	// printf("h=0x%p (%d)\n", h, *h);
    pp = (void *)(h + 1);
    return  pp;
}

void 
afree(void *ptr)
{
    char    *q;
    uint32_t *h;
    
    if (ptr == NULL)
        return;
        
    h = (uint32_t *) (ptr - 4);
    // printf("h=0x%p\n", h);
    q = ((void *)h) - *h;
    free(q);
}

main()
{
	void	*p;

	p = amalloc(11);
	// printf("p=0x%p\n", p);

	afree(p);
	
}

