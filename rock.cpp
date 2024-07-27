#include <iostream>

int main(){
    using str = std::string;
    str instr = "rock, paper, scissors";
    str player_one;
    str player_two;
    
    std::cout << "hello welcome to my game rock, paper, scissors.\n\n";

    while(true){
        std::cout << "\n\nplayer one enter " << instr << " or enter q to quit  : ";
        std::cin >> player_one;
        std::cout << "\n\n\n\n\n\nplayer two enter " << instr << " or enter q to quit  : ";
        std::cin >> player_two;
         
        // quit option 
        if (player_one == "q" || player_two == "q"){
            std::cout << "Thanks for playing";
            break;
        } else if (player_one == player_two){
            std::cout << "it's a tie, go again";
        //scissors beats paper
        } else if (player_one == "scissors" && player_two == "paper"){
            std::cout << "player one you win!";
        } else if (player_two == "scissors" && player_one == "paper"){
            std::cout << "player two you win";
        //paper beats rock
        } else if (player_one == "paper" && player_two == "rock"){
            std::cout << "player one you win";
        } else if (player_two == "paper" && player_one == "rock"){
            std::cout << "player two you win";
        // rock beats scissors
        } else if (player_one == "rock" && player_two == "scissors"){
            std::cout << "player one you win";
        } else if (player_two == "rock" && player_one == "scissors"){
            std::cout << "player two you win";
        }
    }

    return 0;
}
