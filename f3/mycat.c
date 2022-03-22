#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64
int main(int argc, char* argv[]) {
    for(int i = 1; i < argc; i++){
        char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
        strcpy(p1, argv[i]);
        FILE *f;
        f = fopen(p1, "r");
        while(1) {
            char c = fgetc(f);
            if( feof(f) ) { 
                break ;
            }
            printf("%c", c);
        }
        fclose(f);

    }
    return EXIT_SUCCESS;
}