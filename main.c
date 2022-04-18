#include <stdio.h>
#include <stdlib.h>
#define ROWS 25
#define COLUMNS 80
double getRandomdouble(int min, int max);
void create()
int main(){
    char * simulation = (char*)calloc(ROWS*COLUMNS, sizeof(char));
    for(int y = 0 ; y < ROWS; y++){
        for(int x = 0; x < COLUMNS; x++){
            *(simulation +y*COLUMNS + x) = ".";
        }
    }

for(int y = 0 ; y < ROWS; y++){
        for(int x = 0; x < COLUMNS; x++){
            printf("%c", *(simulation +y*COLUMNS + x));
        }
        printf("\n");
    }
double getRandomdouble(int min, int max){
    return((double)rand()/RAND_MAX)*(max-min)+min;
}
    return 0;
}