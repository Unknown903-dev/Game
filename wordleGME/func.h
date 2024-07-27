#ifndef FUNC_H
#define FUNC_H
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <unistd.h>
#define YELLOW_BG "\033[43;30m"
#define GREEN_BG "\033[42;30m"
#define GREY_BG "\033[47;30m"
#define RED "\033[31m"
#define Cyan "\033[96m"
#define magenta "\033[35m"
#define RESET "\033[0m"

using namespace std;

namespace blink{
    std::string start = "\n\n\n---------------------------\n| press enter to continue |\n---------------------------\n";
    std::string StatsTitle = ".............................................\n STATISTICS SUMMARY\n.............................................";
    std::string WordStats = ".............................................\n Words Attempts Wins\n.............................................\n";
}
//color function for words
std::string cyan(std::string design){
    std::string result = Cyan;
    result += design;
    result += RESET;
    return result;
}
std::string green(char letter){
    std::string result = GREEN_BG;
    result+=letter;
    result+=RESET;
    return result;
}
std::string yellow(char letter){
    std::string result = YELLOW_BG;
    result+=letter;
    result+=RESET;
    return result;
}
std::string Grey(char letter){
    std::string result=GREY_BG;
    result+=letter;
    result+=RESET;
    return result;
}
std::string lowercase(std::string user){
    std::string result = "";
    for(int i=0; i<user.size(); i++){
        result+=tolower(user[i]);
    }
    return result;
}
//randomizes the words
std::string randomWord(){
//random number each time it runs
    srand(time(NULL));
//picks number from 1-2315
    int randLine = (rand()%2315+1);
    std::ifstream file;
    file.open("words.txt", ios::in);
    if(file.is_open()){
        std::string word;
        int count = 1;
        while(std::getline(file, word)){
            if(count == randLine){
                return word;
                break;
            }
            count++;
        }
    }
    file.close();
}
//checks in allowed.txt to see if the user input is a word
// allowed 10657 word 2315
bool wordInAllowedfile(std::string user){
    std::ifstream file;
    file.open("allowed.txt", ios::in);
    if(file.is_open()){
        int count = 0;
        std::string word;
        while(std::getline(file, word)){
            if(count<=10657 && word == user){
                return true;
            }
            else{
                count++;
            }
        }
    }
    file.close();
}
//checks in word.txt file to see if the user input is a word
bool wordInWordsfile(std::string user){
    std::ifstream file;
    file.open("words.txt", ios::in);
    if(file.is_open()){
        std::string word;
        int count = 0;
        while(std::getline(file, word)){
            if(count<=2315 && word == user){
                return true;;
            }
            else{
                count++;
            }
        }
    }
    file.close();
}
//finds where the letter is located
int letterInWord(std::string randword, char letter){
    for(int i=0; i<randword.length(); i++){
        if(randword[i]==letter){
            return i;
        }
    }
    return -1;
}
// check if the letter is in the vector
bool letterInVector(std::vector<int> nums, int n){
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==n){
            return true;
        }
    }
return false;
}
//color codes the input
std::string match(std::string user, std::string randword){
    string coloredWord = "";
    vector<int> greenpos;
    vector<int> yellowpos;
    //this is used for test case
    if(user.length()!=randword.length()){
        coloredWord+="Invalid Input";
    }
    else{
    //green for when the word matches randword
        coloredWord+=cyan("\n*.*.*.*.*.*.*.*.*.*.*\n| ");
        for(int i=0; i<user.length(); i++){
            if (user[i] == randword[i]){
                randword[i]='-';
                greenpos.push_back(i);
            }
        }
    //yellow for when it is in the wrong position
        for(int i=0; i<user.length(); i++){
            int letter = letterInWord(randword, user[i]);
            if(letter != -1){
                yellowpos.push_back(i);
            }
        }
        for(int i=0; i<user.length(); i++){
            if (letterInVector(greenpos, i)){
                coloredWord += green(user[i]);
            }
            else if (letterInVector(yellowpos, i)){
                coloredWord += yellow(user[i]);
            }
            else{
                coloredWord += Grey(user[i]);
            }
            if(i<user.length()-1){
                coloredWord += " | ";
            }
        }
        coloredWord+=cyan(" |\n*.*.*.*.*.*.*.*.*.*.*");
    }
    return coloredWord;
}
//score message depending on amount of attempts
void Game(int lives){
    switch(lives){
        case 2:
            std::cout << Cyan << "WHAT NO WAY you got it on your second try\n\n"<< RESET;
            break;
        case 3:
            std::cout << Cyan << "OMG you got it on your 3rd try Great Job!\n\n"<< RESET;
            break;
        case 4:
            std::cout << Cyan << "Congrats! You got it on your 4th try not bad\n\n" << RESET;
            break;
        case 5:
            std::cout << Cyan << "Wow you got it on your 5th try that was a close one.\n\n" << RESET;
            break;
        case 6:
            std::cout << Cyan <<"Game over you used up all your tries.\n\n" << RESET;
            break;
        default:
            std::cout << Cyan << "HOlY S@#T are you hacking \n \nType: yes or no ? " << RESET;
            break;
        }
}
//extra: prints message for when player gets the word first try
void Message(std::string question){
    while(true){
        if(question=="yes"){
            std::cout << Cyan << "you" << RED << " @#!$$% " << Cyan << "I knew it now leave\n\n" << RESET;
            break;
        }
        else if(question=="no"){
            std::cout << Cyan << "Wow well excuse my language congrats you got a 100%\n\n" << RESET;
            break;
        }
        else{
            std::cout << Cyan << "it was a simple yes or no yea get outta here\n\n" << RESET;
            break;
        }
    }
}
//gets the amount of int lives and appends to new file
int averageApp(std::string Afile, int lives=0){
    bool diff;
    std::ofstream file;
    file.open(Afile, ios::app);
    if(file.is_open()) {
        file << lives << "\n";
        file.close();
        diff =true;
    }
    else{
        diff=false;
    }
}   
//reads file and see if the user got the word correct if so it appends 1 or 0 to a file
void wins(std::string randword){
    ifstream file;
    file.open("UserInput.txt", ios::in);
    if(file.is_open()){
        std::string user;
        file >> user;
        if(randword == user){
    //reused the func it appends the number 1 to a file
            averageApp("wins.txt", 1);
        }
        else if(randword!=user){
            //reused the func it appends the number 0 to a file
            averageApp("wins.txt");
        }
    }      
    file.close();
}
//reads file and gets avg
void average(std::string Afile){
    std::vector<int> S;
    float subtotal;
    float sum=0;
    ifstream file;
    file.open(Afile, ios::in);
    if(file.is_open()){
        float line;
        while(file >> line){
            S.push_back(line);
            sum+=line;
        }
    //total amount of tries/timesplayed
        subtotal = sum/S.size();
        if(sum <= 0){
            std::cout << "0";
        }
        else if(subtotal > 0){
            std::cout << setprecision(1) << subtotal;
        }
    }
    file.close();
}
int TimesPlayed(std::string Afile, int add=0){
    //this is used to see if file is opened or not
    bool diff;
    //reads file and adds the number
    std::ifstream file (Afile);
    if(!file){
        diff=false;
    }
    int num=0;
    file >> num;
    file.close();
    num+=add;
    //erase data on file and writes the new number
    std::ofstream file2(Afile);
    if(!file2){
        diff=false;
    }
    file2 << num;
    file2.close();
    diff=true;
    if(diff==true){
        return num;
    }
}
//stores the users words in a file but erases the data
void storeWord(std::string Afile, std::string user){
    ofstream file;
    file.open(Afile, ios::out);
    if(file.is_open()) {
        file << user;
    }
    else{
        std::cout << "file did not open";
    }
    file.close();
}
//Appends the randword in a file for stats
void AppendsWord(std::string Afile, std::string randword){
    ofstream file;
    file.open(Afile, ios::app);
    if(file.is_open()){
        file << randword << "\n";
    }
    else{
        std::cout << "file did not open";
    }
    file.close();
}
// iterates through a vector and prints the users past attempts
void past_words(std::vector<std::string> words, std::string randword){
    for(int i=0; i<words.size(); i++){
        cout << match(words[i], randword);
        sleep(1);
    }
}
//provides a hint for the user
void Hint(std::vector<std::string> words, std::string randword, int lives){
    int num;
    system("clear");
    past_words(words, randword);
    cout << magenta << "\nwhat number position do you want to reveal | 0 | 1 | 2 | 3 | 4 |\n" << RESET;
    cin >> num;
    while(num >= 5 || num <= -1){
        cout << magenta << "\npick a number from 0-4 | 0 | 1 | 2 | 3 | 4 |\n" << RESET;
        cin >> num;
    }
    cout << "postion " << num << " has the letter " << green(randword[num]) << ": ";
}
// runs the whole game
void Playgame(){
    std::vector<std::string> user_input;
    int lives = 1;
    std::string randword = randomWord();
    //appends randomword to file
    AppendsWord("RandWord.txt", randword);
    std::string UserInput;
    cin >> UserInput;
    std::string user = lowercase(UserInput);
    while(lives < 6 && user!=randword){
        storeWord("UserInput.txt", user);
        //checks if word is in allowed.txt
        if(user.length()==randword.length() && wordInAllowedfile(user)==true){
            user_input.push_back(user);
            std::cout << match(user, randword) << endl;
            std::cout << Cyan << "\nyou have " << RESET << YELLOW_BG << 6 - lives << RESET << Cyan << " lives left: " << RESET;
            //code for user to receive a hint
            if(lives >= 3){
                cout << magenta << "\n\npress h for a hint\n" << RESET;
                cin >> UserInput;
                if(UserInput == "h"){
                    Hint(user_input, randword, lives);
                    cin >> UserInput;
                }
            }
            else{
                cin >> UserInput;
            }
            lives++;
            user = lowercase(UserInput);
        }
        //checks if word is in words.txt
        else if( user.length()==randword.length() &&
            wordInWordsfile(user)==true){
            user_input.push_back(user);
            std::cout << match(user, randword) << endl;
            std::cout << Cyan << "\nyou have " << RESET << YELLOW_BG << 6 - lives << RESET << Cyan << " lives left: " << RESET;
            if(lives >= 3){
                cout << magenta << "\n\npress h for a hint\n" << RESET;
                cin >> UserInput;
                if(UserInput == "h"){
                    Hint(user_input, randword, lives);
                    cin >> UserInput;
                }
            }
            else{
                cin >> UserInput;
            }
            lives++;
            user = lowercase(UserInput);
        }
        else{
            std::cout << RED << "you entered something that is not a word or it is not a 5 letter word." << RESET;
            cin >> UserInput;
            user = lowercase(UserInput);
        }
    }
    //stores a word in a file *
    storeWord("UserInput.txt", user);
    //appends the amount of tries
    averageApp("AverageTries.txt", lives);
    //checks if the user got the word correct if so then inputs 0 or 1
    wins(randword);
    system("clear");
    std::cout << match(user, randword) << endl;
    //displays a message
    Game(lives);
    if(lives == 1){
        std::string question;
        cin >> question;
        system("clear");
        Message(question);
    }
    else if(lives == 6 && randword!=user){
        std::cout << "The correct word is : \n\n" << match(randword, randword) << RESET << endl;
    }
    else if(lives == 6){
        std::cout << Cyan << "OMG you got it right!!!!!" << RESET;
    }
}
#endif