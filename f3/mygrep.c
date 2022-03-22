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
    char* word = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    strcpy(p1, argv[2]);
    strcpy(word, argv[1]);
    FILE *f1;
    f1 = fopen(p1, "r");
    int j = 0; int line = 1, col = 1;
    while(1) {
        char c = fgetc(f1);
        
        if( feof(f1) ) { 
            break ;
        }
        if(c == '\n'){
            line += 1;
            col = 1;
        }
        else{
            col += 1;
        }
        if(c == word[j]){
            j+=1;
        }
        else{
            j = 0;
        }
        if(j == strlen(word)){
            j = 0;
            printf("[%d:%ld]\n", line, col - strlen(word));
        }
        
    }
    fclose(f1);
    return EXIT_SUCCESS;
}