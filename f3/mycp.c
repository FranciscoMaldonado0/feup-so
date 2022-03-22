#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64
int main(int argc, char* argv[]) {
    if(argc != 3){
        printf("Wrong argument number\n");
        return EXIT_FAILURE;
    }
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    strcpy(p1, argv[1]);
    strcpy(p2, argv[2]);
    FILE *f1, *f2;
    f1 = fopen(p1, "r");
    f2 = fopen(p2, "w");
    char *text;
    strcpy(text, "");
    while(1) {
        char c = fgetc(f1);
        if( feof(f1) ) { 
            break ;
        }
        strncat(text, &c, 1);
        
    }
    fprintf(f2, text);
    fclose(f1);
    fclose(f2);
    return EXIT_SUCCESS;
}