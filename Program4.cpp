//
//  main.cpp
//  AuthoringAssistant
//
//  Created by Danny Webb-McClain on 9/23/21.
//

#include <iostream>
#include <string>
using namespace std;
char PrintMenu(){
    char userChoice;//user selection
    //printd menu
    cout << "MENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
    cin >> userChoice;
    return userChoice; //returns the user's choice as a character
}
unsigned int GetNumOfNonWSCharacters(string const userString){//gets number of non-whitespace characters in the string
    unsigned int count = 0;//the number of non-whitespace characters
    for(int i = 0; i < userString.length(); ++i){
        if (userString.at(i) != ' ') {
            ++count;
        }
    }
    return count;
}
unsigned int GetNumOfWords(string userString){
    unsigned int count = 0;
    for(int i = 0; i < userString.length(); ++i){
        if (userString.at(i) == ' ' || userString.at(i) == '\n' || userString.at(i) == '\t') {
            while (userString.at(i) == ' ') {//handles multiple spaces
                i++;
            }
            count++;
        }
    }
    count = count + 1; //handles last word
    return count;
}
unsigned int FindText(string seek, string userString){
    unsigned int instances = 0;//the number of times that a word occurs
    int pos;//tracks position as going through the user string
    pos = userString.find(seek);
    
    while (pos != string::npos) {
        pos = userString.find(seek, pos+1);
        instances++;
    }
    return instances;
}
string ReplaceExclamation(string userString){
    for (int i = 0; i < userString.length(); ++i) {//replace all ! with periods.
        if (userString.at(i) == '!') {
            userString.at(i) = '.';
        }
    }
    return userString;
}
string ShortenSpace(string userString){
    //go through the entire string, for any point that there are multiple spaces, skip over those spaces
    string editedString;
    editedString.resize(userString.length());
    int iterator = 0;
    for (int i = 0; i < userString.length(); iterator++) {
        editedString.at(iterator) += userString.at(i);
        /*if (userString.at(i) == ' ') {
            cout<< " you are insdie of the if statement!!!!!!!!" << endl;
            i++;
        }else{
            cout<< "skipped if statement"<<endl;
            i++;
        }
    }*/
        if (userString.at(i) == ' ') {
            while (userString.at(i) == ' ') {
                i++;
            }
        }else{
            i++;
        }
    
    }
    editedString.erase(editedString.find('\0')); //credit goes to this StackOverflow page https://stackoverflow.com/questions/49410500/how-to-resize-stdstring-to-remove-all-null-terminator-characters I was uncertain on how to remove extra null terminators.
    return editedString;
}
int main() {

   /* Type your code here. */
    string userString;//stores user's string
    //prompt user input
    char userChoice;//user menu choice
    unsigned int numberNWS; //number of nonwhite space characters
    unsigned int numberW; //number of words
    unsigned int instances; //then number of times that a word ocurs
    string editedString;//edited string from functions
    string seek;// the string to be found in the user string
    cout << "Enter a sample text:" << endl;
    getline(cin, userString); //capture user input
    cout << "\nYou entered: " << userString << endl;
    cout << endl;
    userChoice = PrintMenu();
    while(userChoice != 'q'){
        //cout << endl;
        if (userChoice == 'c') {
            numberNWS = GetNumOfNonWSCharacters(userString);
            cout << "Number of non-whitespace characters: " << numberNWS << endl;
            cout << endl;
        } else if(userChoice == 'w'){
            numberW = GetNumOfWords(userString);
            cout << "Number of words: " << numberW << endl;
            cout << endl;
        }else if (userChoice == 'f'){
            cout << "Enter a word or phrase to be found:" << endl;
            cin.ignore();
            getline(cin, seek);
            instances = FindText(seek, userString);
            cout << "\"" << seek << "\"" << " instances: " << instances << endl;
            cout << endl;
        } else if (userChoice == 'r'){//replace all ! with periods call
            editedString = ReplaceExclamation(userString);
            cout << "Edited text: " << editedString << endl;
            cout << endl;
            
        } else if (userChoice == 's'){
            //editedString = "";
            editedString = ShortenSpace(userString);
            cout << "Edited text: " << editedString << endl;
            cout << endl;
        }
        userChoice = PrintMenu();
    }
    

   return 0;
}
