#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "lab2.h"
#include "valid_board.txt"


int** read_board_from_file(char* filename){
    FILE *fp = NULL;
    int** board = NULL;
    FILE *f = fopen(filename, "r");

    int ROW_SIZE = 9;
    int COL_SIZE = ROW_SIZE;
    int NUM_OF_SUBGRIDS = ROW_SIZE;
    int NUM_OF_THREADS = ROW_SIZE+COL_SIZE+NUM_OF_SUBGRIDS;
    int** sudoku_board = (int**)malloc(sizeof(int*)*ROW_SIZE);
for(int row = 0; row < ROW_SIZE; row++){
	sudoku_board[row] = (int*)malloc(sizeof(int)*COL_SIZE);
} 
   for (int i = 0; i < ROW_SIZE; i++)
      {
         for (int j = 0; j < COL_SIZE; j++)
            fscanf("%d ",f, sudoku_board[i][j]);
         printf("\n");
       }
  

    return board;
}



int is_board_valid(){
    pthread_t* tid;  /* the thread identifiers */
    pthread_attr_t attr;
    param_struct* parameter;

    typedef struct {
    int id;
    int starting_row;
    int starting_col;
    int ending_row;
    int ending_col;
} param_struct;
thread_t* tid = (thread_t*)malloc(sizeof(int)*NUM_OF_THREADS);
param_struct* params = (param_struct*)malloc(sizeof(param_struct)*NUM_OF_THREADS); 
params[0].id = 0; // id of first thread
params[0].starting_row = 0;
params[0].starting_col = 0;
params[0].starting_row = 3;
params[0].starting_row = 3;
/* Now create the thread passing it params[0] as a parameter */
pthread_create(&(tid[0]), &attr, validate, &(params[0]));

int main(void) {
  
  
}
