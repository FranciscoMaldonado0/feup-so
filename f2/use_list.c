#include "list.h"
#include <stdio.h>

int main(int argc, char** argv){
	list* l1 = list_new_random(5, 10);
	list_print(l1);
	printf("\n");
	list_add_first(11, l1);
	list_print(l1);
	printf("\n");
	int first = list_get_first(l1);
	printf("%d", first);
	printf("\n");
	list_add_last(12,l1);
	list_print(l1);
	printf("\n");
	int last = list_get_last(l1);
	printf("%d\n", last);
	list_remove_first(l1);
	list_remove_last(l1);
	int size = list_size(l1);
	list_print(l1);
	printf("%d",size);
}
