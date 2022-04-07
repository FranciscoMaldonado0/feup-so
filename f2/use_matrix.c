#include "matrix.h"
#include <stdio.h>

int main(int argc, char** argv){
	matrix* m1 = matrix_new_random(3,3,0.0,10.0);
	matrix* m2 = matrix_new_random(3,3,0.0,10.0);
	matrix_print(m1);
	
	double value1 = matrix_get(1,1,m1);
	printf("%f \n", value1);
	
	matrix_set(1,1,4.0,m1);
	value1 = matrix_get(1,1,m1);
	printf("%f \n", value1);
	
	matrix* m3 = matrix_add(m1,m2);
	matrix_print(m3);
	matrix* m4 = matrix_sub(m1,m2);
	matrix_print(m4);
	matrix* m5 = matrix_trans(m1);
	matrix_print(m5);
}
