 #ifndef MENU_H
#define MENU_H
#include "func.h"
#include <limits>
    //got help from internet told professor and said i can use it
    //cin.get() function to read a single character from the input stream.
void PressEnter(){
    char c;
    while(true){
    //takes care input bug got it online
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //takes in input like spaces \n
        cin.get(c);
        if(c=='\n'){
            system("clear");
            break;
        }
        else{
            system("clear");
            std::cout << "Press Enter: ";
        }
    }
}
// finds win percentage
void WinsPercent(){
    float sum=0;
    float played = TimesPlayed("TimesPlayed.txt");
    ifstream file;
    file.open("wins.txt", ios::in);
    if(file.is_open()){
        float result;
        int num;
        while (file >> num){
            sum+=num;
        }
        if (played == 0 || sum < 0 ){
            std::cout << "0.0";
        }
        else{
            //equation for wins percent
            result=(float(sum)/played)*100.0;
            std::cout << setprecision(4) << result;
        }
    }
    file.close();
}
//finds the current streak
int Currentstreak(){
    int sum=0;
    ifstream file;
    file.open("wins.txt", ios::in);
    if(file.is_open()){
        int num;
        while(file >> num){
            sum+=num;
            if(num==0){
                sum=0;
            }
        }
        return sum;
    }
    file.close();
}
//finds the longest streak
int longestStreak(){
    int longest=0;
    int current=0;
    ifstream file;
    file.open("wins.txt", ios::in);
    if(file.is_open()){
        int num;
        while(file >> num){
            if(num==1){
                current++;
            }
            else if(num==0){
                if(current > longest){
                    longest = current;
                }
                current = 0;
            }
        }
        if(current > longest){
            longest=current;
        }
        file.close();
    }
    return longest;
}
//This reads all 3 files at the same time and prints each line at a time
std::string wordsStats(){
    std::string result;
    ifstream file;
    ifstream file2;
    ifstream file3;
    file.open("RandWord.txt", ios::in);
    file2.open("AverageTries.txt", ios::in);
    file3.open("wins.txt", ios::in);
    if(file.is_open()){
        std::string word;
        if(file2.is_open()){
            std::string tries;
            if(file3.is_open()){
                std::string wins;
                while(getline(file, word)){     
                    getline(file2, tries);
                    getline(file3, wins);
                    if(wins=="1"){
                        wins="yes";
                    }
                    else if(wins == "0"){
                        wins = "no";
                    }
                    else{
                        wins = "no";
                    }
                    result += " ";
                    result += word;
                    result += " ";
                    result += tries;
                    result += " ";
                    result += wins;
                    result += "\n\n";
                }
                return result;
            }
        }
    }
    file.close();
    file2.close();
    file3.close();
}
//clear wins.txt TimesPlayed.txt AverageTries.txt.
// do this by writing a empty string on all the files
void clearData(){
    ofstream file;
    ofstream file2;
    ofstream file3;
    ofstream file4;
    file.open("RandWord.txt", ios::out);
    file2.open("AverageTries.txt", ios::out);
    file3.open("wins.txt", ios::out);
    file4.open("TimesPlayed.txt", ios::out);
    if(file.is_open()){
        file << "";
        if(file2.is_open()){
            file2 << "";
            if(file3.is_open()){
                file3 << "";
                if(file4.is_open()){
                    file4 << "";
                }
            }
        }
    }
    else{
        std::cout << "Files refuse to open";
    }
    file.close();
    file2.close();
    file3.close();
    file4.close();
}
//menu build
void Menu(){
    std::cout << Cyan << "\n\n..............................\n WELCOME TO WORDLE \n..............................\n\n\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. How to Play\n";
    std::cout << "3. Statistics Summary\n";
    std::cout << "4. Reset Stats\n";
    std::cout << "5. Exit";
    std::cout << RED << "\n\n\nSelect a number option: \n" << RESET;
}
//instruction on how to play the game
void Instructions(){
    std::cout << ".............................................\n HOW TO PLAY \n.............................................";
    std::cout << "\nGuess the word in 6 tries.\n\n\n";
    sleep(1);
    std::cout << "HOW TO PLAY:\n* Each guess must be a valid 5 letter word.\n";
    std::cout << "* The color of the tiles will change to show\n you how close your guess was to the word.\n\n\n\n";
    sleep(1);
    std::cout << match("flare", "xxaxx");
    std::cout << "\nA is in the word and in the correct spot.\n\n";
    sleep(1);
    std::cout << match("train", "nxxxx") << "\nN is in the word but in the wrong spot.\n\n";
    sleep(1);
    std::cout << match("plane", "xxxxx") << "\nAll the letters turned grey they are not in the word.";
    std::cout << "\n" << blink::start;
}
//stats for the game
void StatSummary(){
//setw(15) std::right
//numbers played
    std::cout << Cyan << blink::StatsTitle;
    std::cout << "\nTime Played:" << setw(32) << std::right <<
    TimesPlayed("TimesPlayed.txt") << "\n";
    std::cout << "Average Attempts:" << setw(27) << std::right;
    average("AverageTries.txt");
    std::cout << "\nWins Percentage:" << setw(27) << std::right;
    WinsPercent();
    std::cout << "%\nCurrent Streak:" << setw(29) << std::right <<
    Currentstreak() << "\n";
    std::cout << "Longest Streak:" << setw(29) << std::right << longestStreak() << "\n";
    sleep(1);
    std::cout << blink::WordStats;
    std::cout << wordsStats();
    std::cout << RED << blink::start << RESET;
}
//clears stats
void clearStats(){
    clearData();
    std::cout << Cyan << blink::StatsTitle;
    std::cout << "\nTime Played:" << setw(32) << std::right <<
    TimesPlayed("TimesPlayed.txt") << "\n";
    std::cout << "Average Attempts:" << setw(27) << std::right;
    average("AverageTries.txt");
    std::cout << "\nWins Percentage:" << setw(27) << std::right;
    WinsPercent();
    std::cout << "%\nCurrent Streak:" << setw(29) << std::right <<
    Currentstreak() << "\n";
    std::cout << "Longest Streak:" << setw(29) << std::right << longestStreak() << "\n";
    std::cout << blink::WordStats;
    std::cout << wordsStats();
    std::cout << RED << blink::start << RESET;
}
#endif

