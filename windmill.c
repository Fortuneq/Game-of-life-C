#include <stdio.h>
#include <stdlib.h>
int Y_LEN = 25;
int X_WIT = 80;

void begin(int rows, int columns);
int main(){
begin(Y_LEN, X_WIT);
return 0;
}

void begin(int rows, int columns){
 char*simulation = (char*)calloc(rows*columns,sizeof(char));
 for(int y = 0; y < rows; y++){
     for(int x = 0 ; x<columns; x++){
         if (y == 11 && x == 40)
             *(simulation +y*columns +x) = '*';
              else if (y == 12 && (x == 39 || x == 40 || x == 41))
                *(simulation +y*columns +x) = '*';
                    else if (y == 13 && x == 40)
                    *(simulation +y*columns +x) = '*';
         else *(simulation +y*columns +x) = ' ';
     }
 }

  for(int y = 0; y < rows; y++){
     for(int x = 0 ; x<columns; x++){
         printf("%c",*(simulation +y*columns +x));
     }
     printf("\n");
 }
}
