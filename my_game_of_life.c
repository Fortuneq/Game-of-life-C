#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int Y_LEN = 27;
int X_WIT = 82;

void begin(int rows, int columns);
char * create1(int rows, int columns);
char * create2(int rows, int columns);
void display(int rows, int columns,char *simulation);
int countNeighbourhood(int rows, int columns ,int x, int y ,char *simulation);
char *step(int rows, int columns, char* prevSimulation);
int main(){
begin(Y_LEN, X_WIT);
return 0;
}
int countNeighbourhood(int rows, int columns ,int x, int y ,char *simulation){
    int count = 0;
    int pivot = y*columns+x;
    
    for(int i = -1; i <=1; i++){
        for(int j = -1; j<= 1; j++){
            char c = *(simulation +pivot + (i*columns)+j);

            if(c == '*') {count++;}
        }
    }
    return count;
}

char *step(int rows, int columns, char* prevSimulation){
    char * SteppedSimulation = calloc(rows*columns,sizeof(int));
    for (int y = 1; y<rows -1;y++){
        for (int x = 1; x < columns -1 ; x++){
            int live = countNeighbourhood(rows,columns,x,y,prevSimulation);
            char cell = *(prevSimulation+y*columns+x);
            if(cell=='*') live--;
            *(SteppedSimulation+y*columns+x)= cell;
            if(live<2) {
                *(SteppedSimulation+y*columns+x)=' ';
            }
            else if((live==2 || live == 3) && cell == '*') {
                *(SteppedSimulation+y*columns+x)='*';
            }
            else if(live > 3 && cell == '*'){
                *(SteppedSimulation+y*columns+x)=' ';
            }
             else if(live == 3 && cell == ' ')
            {
                *(SteppedSimulation+y*columns+x)='*';
            }
        }
    }
return SteppedSimulation;
}
void begin(int rows, int columns){
 char*simulation = create1(rows,columns);
 if(simulation == NULL){
     return ;}
display(rows,columns,simulation);
while(1){
    char *newSim = step(rows,columns,simulation);
    if(newSim == NULL) return;
    free(simulation);
    simulation = newSim;
    display(rows,columns,simulation);
   usleep(100000);
}

}
void display(int rows, int columns,char *simulation){
    printf("\033[0d\033[2J");
    for(int y = 1; y < rows-1; y++){
     for(int x = 1 ; x<columns-1; x++){
         printf("%c",*(simulation +y*columns +x));
     }
     printf("\n");
}
}

char * create1(int rows, int columns){
 char*simulation = (char*)calloc(rows*columns,sizeof(char));
    if(simulation == NULL) {
        return NULL;
    }
 for(int y = 0; y < rows; y++){
     for(int x = 0 ; x<columns; x++){
         if (y == 11 && x == 40)
         *(simulation +y*columns +x) = '*';
          else if (y == 12 && x == 39)
            *(simulation +y*columns +x) = '*';
                else if (y == 13 && (x == 39 || x == 40 || x == 41))
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
    return simulation;
}
