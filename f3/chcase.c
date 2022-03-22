#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64
int main(int argc, char* argv[]) {
    if(argc == 2){
        char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
        strcpy(p1, argv[1]);
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
    else if(argc == 3){
        char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
        strcpy(p1, argv[2]);
        FILE *f;
        f = fopen(p1, "r");
        while(1) {
            char c = fgetc(f);
            if( feof(f) ) { 
                break ;
            }
            if(strcmp(argv[1],"-u") == 0){
                c = toupper(c);
            }
            else if(strcmp(argv[1] ,"-l") == 0){
                c = tolower(c);
            }
            
            printf("%c", c);
        }
        fclose(f);

    }
    
    return EXIT_SUCCESS;
}