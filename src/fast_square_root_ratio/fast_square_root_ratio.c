#ifdef _MSC_VER
#include <intrin.h>
#endif
#include <fast_square_root_ratio.h>
#include <stdint.h>



#ifdef _MSC_VER
#pragma intrinsic(_BitScanForward64)
static __inline __forceinline unsigned int FIND_FIRST_SET_BIT(unsigned __int64 m){
	unsigned long out;
	_BitScanForward64(&out,m);
	return out;
}
#else
#define FIND_FIRST_SET_BIT(m) (__builtin_ffsll(m)-1)
#endif



uint64_t fast_square_root_ratio(uint64_t number,uint8_t iterations,uint64_t* numerator){
	uint64_t a=number*(number+6)+1;
	uint64_t b=(number+1)<<2;
	uint8_t i=1;
	do{
		uint64_t t=(a*a+number*b*b)>>(i+1);
		b=(a*b)>>i;
		a=t;
		i++;
	} while (i<iterations);
	if ((number&15)==4){
		*numerator=a>>7;
		return b>>7;
	}
	uint64_t c=FIND_FIRST_SET_BIT(a);
	a>>=c;
	b>>=c;
	if ((number&3)==3){
		c=a;
		uint64_t d=b;
		do{
			uint64_t t=c%d;
			c=d;
			d=t;
		} while (d);
		a/=c;
		b/=c;
	}
	*numerator=a;
	return b;
}
