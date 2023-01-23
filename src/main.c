#include <fast_square_root_ratio.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>



int main(int argc,const char** argv){
	for (uint64_t i=1;i<20;i++){
		uint64_t numerator;
		uint64_t denominator=fast_square_root_ratio(i,4,&numerator);
		printf("sqrt(%"PRIu64") = %"PRIu64" / %"PRIu64" = %lf (Err: %lg)\n",i,numerator,denominator,((double)numerator)/denominator,((double)numerator)/denominator-sqrt((double)i));
	}
	return 0;
}
