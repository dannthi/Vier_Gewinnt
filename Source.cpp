#include <stdio.h>
#include <iostream>
#include "Header.h"


int main(){
    define_board();
    int player = 1;
    int turn = 1;

    while(true){
        std::cout << "Turn " << turn << std::endl;

        print_board();
        
        set_move(get_move(player), player);

        if(check()){
            std::cout << "Player " << player << " wins!" << std::endl;
            return 0;
        }
        

        turn++;
        if(turn % 2 == 0){
            player = 2;
        }
        else{
            player = 1;
        }
    }
}
