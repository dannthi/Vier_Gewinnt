#include <stdio.h>
#include <iostream>

const int WIDTH = 7;
const int HEIGHT = 6;
char board[HEIGHT][WIDTH];

//Spaces in every index
void define_board(){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            board[i][j] = ' ';
        }
    }
}

void print_board(){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            printf("| %c", board[i][j]);
        }
        printf("|\n");
    }  
    printf("______________________\n");
    printf("|1 |2 |3 |4 |5 |6 |7 |\n");
}

//asks for an input, input have to be between 0 and 8, check if spot is "full", loop till input is valid
int get_move(int player){
    int position;
    int valid = 1;
    do{
    std::cout << "Player " << player << " enter a position: ";
    scanf("%d", &position);
    std::cout << std::endl;
        if((position < 8 && position > 0) && (board[0][position-1] == ' ')){
            valid = 0;
            return position-1;
        }
        else{
            std::cout << "Invalid try again..." << std::endl;
        }
    } while (valid == 1);
}

//if on set location no symbol is stored, place symbol depending on players turn
//for loop to start on the bottom of the board and check if space, place symbol on lowest location
void set_move(int position, int player){
    for(int i = HEIGHT-1; i > -1; i--){
        if(board[HEIGHT-1][position] == ' '){
            if(player == 1) board[HEIGHT-1][position] = 'O';
            else board[HEIGHT-1][position] = 'X';
            return;
        }

        else if(board[i][position] == ' '){
            
            if(player == 1) board[i][position] = 'O';
            else board[i][position] = 'X';
            return;
        }
    }
}

//checks if board[0][i] are all not ' '
bool draw(int i){
    i++;
    if(i-1 == WIDTH){
        return true;
    }
    else if(i != ' '){
        draw(i);
    }
    else{
        return false;
    }
}

//look for similars of every index, to the right, top, righttop, leftbottom
bool check(){
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){

            if(draw(0)){
                std::cout << "Draw!" << std::endl;
                exit(0);
            }
            else if((board[i][j] == board [i+1][j]) && (board[i][j] == board [i+2][j]) && (board[i][j] == board [i+3][j]) && (board[i][j] != ' ')){
                return true;
            } 
            else if((board [i][j] == board[i][j+1]) && (board[i][j] == board[i][j+2]) && (board[i][j] == board[i][j+3]) && (board[i][j] != ' ')){
                return true;
            }
            else if((board[i][j] == board[i+1][j+1]) && (board[i][j] == board[i+2][j+2]) && (board[i][j] == board[i+3][j+3]) && (board[i][j] != ' ')){
                return true;
            } 
            else if((board[i][j] == board[i-1][j-1]) && (board[i][j] == board[i-2][j-2]) && (board[i][j] == board[i-3][j-3]) && (board[i][j] != ' ')){
                return true;
            }
            else return false;
        }   
    }
}
