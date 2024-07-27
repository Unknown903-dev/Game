#include <iostream>
#include <limits>
#include "func.h"
#include "menu.h"

int main(int argc, char* argv[]) {
    system("clear");
    std::string option;
    while(true){
        //displays menu
        Menu();
        cin >> option;
        //leaves game
        if(option == "5"){
            break;
        }
        //plays the game
        else if(option=="1"){
            //keeps track of amount played
            TimesPlayed("TimesPlayed.txt", 1);
            system("clear");
            std::cout << cyan("Type a 5 letter word: ");
            Playgame();
            std::cout << cyan("\nPress enter to continue");
            PressEnter();
        }
        //Explains how to play the game
        else if(option=="2"){
            system("clear");
            Instructions();
            PressEnter();
        }
        //show the stats of the word game
        else if(option=="3"){
            system("clear");
            StatSummary();
            PressEnter();
        }
        //erases all content in stats
        else if(option=="4"){
            system("clear");
            clearStats();
            PressEnter();
        }
        else{
            system("clear");
            std::cout << YELLOW_BG << "Type in a number option: " << RESET;
        }
    }
    return 0;
}
