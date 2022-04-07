#include <stdio.h>

int g(int* x){
	printf("%d\n", *x);
	return 0;
}

int main(){
	int x = 2;
	g(&x);
	return 0;
}
