#include <stdio.h>  //The Standard Input Output header file
#include <stdlib.h> //The Standard Library header file - Useful utilities
#include <time.h>
#include <stdbool.h>

#define MAXROW 5  //The max the grid can be in height is 5 rows.
#define MAXCOL 5  //The max the grid can be in width is 5 columns.

#define FPS 1
#define FRAME_LENGTH (1000.0/FPS) //1000.0 milliseconds divided by 60 FPS = 16.66 milliseconds

bool running = true;

//Notes:
//This is how the grid is going to work.
//We will be using a 2D arrary, where each cell can be DEAD or ALIVE
//.....     [0,0][0,1][0,2][0,3][0,4]  
//.***.     [1,0][1,1][1,2][1,3][1,4]
//.***. --> [2,0][2,1][2,2][2,3][2,4]
//.***.     [3,0][3,1][3,2][3,3][3,4]
//.....     [4,0][4,1][4,2][4,3][4,4]
//"The typedef keyword lets you create a new name (an alias) for an existing type." (w3school)
//enum also called enumeration represents "a group of constants (unchangeable values)" (w3school)



//We are creating a type called "Cell" that is a enum which can be DEAD or ALIVE
typedef enum cell{
  DEAD,
  ALIVE
} Cell;

//We are creating a type called Grid which is a 2D array of Cells.
typedef Cell Grid[MAXROW][MAXCOL];



//Here are the functions that we will use throughout this project.

void copy_this_grid_to_that_grid(Grid this_grid, Grid that_grid){

  for(int row = 0; row < MAXROW; row++){
    for(int col = 0; col < MAXCOL; col++){
      that_grid[row][col] = this_grid[row][col];
    }//end of column for loop
  }//end of row for loop

}//end of copy_this_grid_to_that_grid function

void make_grid_blank(Grid grid){
  //Create a blank grid (DEAD cells)
  for(int row = 0; row < MAXROW; row++){
    for(int col = 0; col < MAXCOL; col++){
      grid[row][col] = DEAD;
    }//end of column for loop
  }//end of row for loop
}//end of make_grid_blank function


//Our test grid would just be this, since this will loop on forever.
//.....     .....
//..... --> ..*..
//.***.     ..*..
//..... <-- ..*..
//.....     .....
void make_grid_test(Grid grid){
  grid[2][1] = ALIVE;
  grid[2][2] = ALIVE;
  grid[2][3] = ALIVE;
}//end of make_grid_test

void print_grid(Grid grid){
  for(int row = 0; row < MAXROW; row++){
    for(int col = 0; col < MAXCOL; col++){
      //Is the cell Dead?
      if(grid[row][col] == DEAD){
        //If it is, then display a period.
        printf(".");
      }
      else{
        //If it is not, them display an asterisk.
        printf("*");
      }
    }//end of column for loop
    //When we move to the next row, print the new line character.
    printf("\n");
  }//end of row for loop
}//end of print_grid function

void clear_screen(){
  system("clear");  
}//end of clear_screen function

//Here are the rules we will be checking
//Underpopulation - Any alive cells will die if there are fewer than two neighbouring alive cells.
bool check_for_underpopulation(int neighbour_num){
  if(neighbour_num < 2){
    return true;
  }
  return false;
}

//Survival - Any alive cells will live if there are two or three neighbouring alive cells.
bool check_for_survival(int neighbour_num){
  if(neighbour_num == 2 || neighbour_num == 3){
    return true;
  }
  return false;
}

//Overpopulation - Any alive cells will die if there are more than three neighbouring alive cells.
bool check_for_overpopulation(int neighbour_num){
  if(neighbour_num > 3){
    return true;
  }
  return false;
}

//Reproduction - Any dead cells will turn into an alive cell if there are exactly three neighbouring alive cells.
bool check_for_reproduction(int neighbour_num){
  if(neighbour_num == 3){
    return true;
  }
  return false;
}

int get_neighouring_alive_cell_num(Grid grid, int current_row, int current_col){
  int count = 0;

  for(int temp_row = current_row - 1; temp_row <= current_row + 1; temp_row++){
    for(int temp_col = current_col - 1; temp_col <= current_col + 1; temp_col++){
      
      bool does_cell_exist = (temp_row >= 0 && temp_row < MAXROW) && (temp_col >= 0 && temp_col < MAXCOL);
      bool is_cell_the_current_cell = (temp_row == current_row)&&(temp_col == current_col);

      if(does_cell_exist && !(is_cell_the_current_cell) && grid[temp_row][temp_col] == ALIVE){
        count++;
      }

    }//end of column for loop
  }//end of row for loop
  
  return count;
}//end of get_neighouring_alive_cell_num function

void check_for_rules(Grid grid, Grid clone_grid){
  int alive = 0;
  for(int row = 0; row < MAXROW; row++){
    for(int col = 0; col < MAXCOL; col++){
      if(grid[row][col] == ALIVE){
        alive++;
      }

      int neighbour_num = get_neighouring_alive_cell_num(grid, row, col);

      if(grid[row][col] == DEAD){
        if(check_for_reproduction(neighbour_num)){
          clone_grid[row][col] = ALIVE;
        }
      }
      else{
        //Current cell is ALIVE
        if(check_for_underpopulation(neighbour_num)||check_for_overpopulation(neighbour_num)){
          clone_grid[row][col] = DEAD;
        }
        else if(check_for_survival(neighbour_num)){
          clone_grid[row][col] = ALIVE;
        }
      }//end of else statement

    }//end of column for loop
  }//end of row for loop
  
  if(alive == 0){
    running = false;
  }
  
  copy_this_grid_to_that_grid(clone_grid, grid);
  make_grid_blank(clone_grid);
}//end of check_for_rules function


void initialize(Grid grid, Grid clone){
  //This initialize our grid by making it blank
  make_grid_blank(grid);
  make_grid_test(grid);

  make_grid_blank(clone);
}

void update(Grid grid, Grid clone){
  check_for_rules(grid, clone);
  //This function will allow us to clear the screen for our next frame.  
  clear_screen();
}

void render(Grid grid){
  //Display our current grid
  print_grid(grid);
}

//This is where our program starts


int main(){
  float delta = 0;
  float start_ticks = clock();
  float end_ticks = 0;

  Grid grid;
  Grid clone_grid;
  initialize(grid, clone_grid);

  while(running){
    end_ticks = clock();
    //Delta the time between the start and end tick in miliseconds
    //delta = 1000 miliseconds * (clock tick length)/Clock ticks per second
    delta = 1000 * (end_ticks - start_ticks)/CLOCKS_PER_SEC;

    if(delta >= FRAME_LENGTH){
      //restart delta
      delta = 0;
      start_ticks = clock();

      update(grid, clone_grid);
      render(grid);
    }
  }//end of game while loop


  return 0;//If everything went well, it will return zero
}//end of main function
