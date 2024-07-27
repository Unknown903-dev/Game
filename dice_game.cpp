#include <iostream>

int main(){
    //starting the game
    int user;
    std::cout << "\n\nDepending on the number you roll you win or lose money.";
    std::cout << "\nNow press 1 to roll the dice: ";

    //make the code short repeatable
    std::string keep_playing = "\n\npress 1 to continue or 2 to quit : ";

    //points/money earned
    int money = 0;

    //loop to keep playing continuosly
    while (true){
        //user input
        std::cin >> user;
        //chooses a random number each time it runs
        srand(time(0));
        // chooses a number from 1-10 but it chooses the same output each run 
        //above is needed for randomization
        int num = rand()%10+1;

        if (user == 2){
            if (money < 0){
                std::cout << "your in debt :( $" << money;
            }
            else{
                std::cout << "Thanks for playing.\n\nyou earned $" << money;
            }
            break;
        } else if (num == 10){
            money-=100000;
            std::cout << "\n\nhaha you lost money 100,000.\n\n$" << money << keep_playing;
        }else if (num == 1){
            money+=10000;
            std::cout << "\n\nWoah you rolled a 1 you're very lucky here's a wad of cash.\n\n$" << money << keep_playing;
        } else if (num <= 5 && num >= 2){
            money-=3000;
            std::cout << "\n\nno luck you rolled" << "\n" << num << "\n\n$" << money << keep_playing;
        } else if (num >= 5 && num <= 9){
            money+=5000;
            std::cout << "\n\nnice luck you rolled a" << "\n" << num << "\n\n$" << money << keep_playing;
        }
    }
    return 0;
}