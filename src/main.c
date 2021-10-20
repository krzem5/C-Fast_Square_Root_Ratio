#include <fast_square_root_ratio.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>



int main(int argc,const char** argv){
	for (uint64_t i=1;i<20;i++){
		uint64_t n;
		uint64_t dn=fast_square_root_ratio(i,4,&n);
		printf("sqrt(%"PRIu64") = %"PRIu64" / %"PRIu64" = %lf (Err: %lg)\n",i,n,dn,((double)n)/dn,((double)n)/dn-sqrt((double)i));
	}
	return 0;
}
