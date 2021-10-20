#ifdef _MSC_VER
#include <intrin.h>
#endif
#include <fast_square_root_ratio.h>
#include <stdint.h>



#ifdef _MSC_VER
#pragma intrinsic(_BitScanForward64)
static __inline __forceinline unsigned int FIND_FIRST_SET_BIT(unsigned __int64 m){
	unsigned long o;
	_BitScanForward64(&o,m);
	return o;
}
#else
#define FIND_FIRST_SET_BIT(m) (__builtin_ffsll((m))-1)
#endif



uint64_t fast_square_root_ratio(uint64_t n,uint8_t m,uint64_t* o){
	uint64_t a=n*(n+6)+1;
	uint64_t b=(n+1)<<2;
	uint8_t i=1;
	do{
		uint64_t t=((a*a)>>(i+1))+((n*b*b)>>(i+1));
		b=(a*b)>>i;
		a=t;
		i++;
	} while (i<m);
	uint64_t c=((n&15)==4?7:FIND_FIRST_SET_BIT(a));
	a>>=c;
	b>>=c;
	c=a;
	uint64_t d=b;
	do{
		uint64_t t=c%d;
		c=d;
		d=t;
	} while (d);
	*o=a/c;
	return b/c;
}
