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
        int num = 0;
        while(1) {
            char c = fgetc(f);
            if( feof(f) ) { 
                break ;
            }
            num++;
        }
        printf("%d", num);
        
        fclose(f);
        return EXIT_SUCCESS;
    
    }
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    strcpy(p1, argv[2]);
    FILE *f;
    f = fopen(p1, "r");
    if(argc == 3){
        if(strcmp(argv[1], "-c") == 0){
            int num = 0;
            while(1) {
                char c = fgetc(f);
                if( feof(f) ) { 
                    break ;
                }
                num += 1;
            }
            printf("%d", num);
        }
        else if(strcmp(argv[1], "-w") == 0){
            int num = 0;
            int inWord = 0;
            while(1) {
                char c = fgetc(f);
                if( feof(f) ) { 
                    break ;
                }
                if((c != ' ' && c != '\n' && c != '\t') && inWord == 0){
                    inWord = 1;
                    num++;
                }
                else if(c == ' ' || c == '\n' || c == '\t'){
                    inWord = 0;
                }
            }
            printf("%d", num);
        }
        else if(strcmp(argv[1], "-l") == 0){
            int num = 1;
            while(1) {
                char c = fgetc(f);
                if( feof(f) ) { 
                    break ;
                }
                if(c == '\n'){
                    num++;
                }
                
            }
            printf("%d", num);
        }
    }
    fclose(f);
    return EXIT_SUCCESS;
}