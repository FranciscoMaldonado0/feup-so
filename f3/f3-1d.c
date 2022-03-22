#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64
int main(int argc, char* argv[]) {
    if(argc != 3){
        printf("Wrong parameter number\n");
        return EXIT_FAILURE;
    }
    
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    strcpy(p1, argv[1]);
    strcpy(p2, argv[2]);
    int j = 0; int num = 0;
    for(int i = 0; i < strlen(p2); i++){
        if(p2[i] == p1[j]){
            j += 1;
        }
        else{
            j = 0;
        }
        if(j == strlen(p1)){
            num += 1;
            j = 0;
        }
    }
    printf("%s occurs %d times in %s", p1, num, p2);
    return EXIT_SUCCESS;
}