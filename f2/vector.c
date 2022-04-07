#include "vector.h"

vector* vector_new(double x, double y, double z){
	vector* v = (vector*) malloc(sizeof(vector));
	v->x = x; v->y = y; v->z = z;
	return v;	
}

vector* vector_add(vector* a, vector* b){
	return vector_new(a->x + b->x, a->y + b->y, a->z + b->z);
}

vector* vector_sub(vector* a, vector* b){
	return vector_new(a->x - b->x, a->y - b->y, a->z - b->z);
}

vector* vector_scale(double k, vector* a){
	return vector_new(a->x * k, a->y * k, a->z * k);
}

vector* vector_vprod(vector* a, vector* b){
	return vector_new(a->y * b->z - a->z * b->y, a->z * b->x - a->x * b->z, a->x * b->y - a->y * b->x);
}

//(a2 * b3 – a3 * b2) * i 
//+ (a3 * b1 – a1 * b3) * j 
//+ (a1 * b2 – a2 * b1) * k

double vector_sprod(vector* a, vector* b){
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

double vector_mod(vector* a){
	return sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
}
