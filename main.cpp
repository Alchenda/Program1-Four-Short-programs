//
//  main.cpp
//  TextMessageExpander
//
//  Created by Danny Webb-McClain on 9/23/21.
//

#include <iostream>
#include <string>
// FIXME include string library
using namespace std;

int main() {
    string userText; // user input
    string expandedText; // expands user text
    int posFound; // position of found abberviation
   /* Type your code here. */
    //prompt user to ender their text
    cout << "Enter text:";
    //captures user input
    getline(cin, userText);
    //print user text
    cout << "\nYou entered: " << userText << endl;
    //check for BFF
    posFound = userText.find("BFF");
    if(posFound >= 0){
        userText.replace(posFound, 3, "best friend forever");//replace first abbreviation
    }
    posFound = userText.find("IDK");//search for IDK
    if (posFound >= 0 ) {
        
        userText.replace(posFound, 3, "I don't know");//Repalce first abbreviation
    }
    posFound = userText.find("JK");
    if (posFound >= 0 ) {
        
        userText.replace(posFound, 2, "just kidding");//Repalce first abbreviation
    }
    posFound = userText.find("TMI");
    if (posFound >= 0 ) {
        
        userText.replace(posFound, 3, "too much information");//Repalce first abbreviation
    }
    posFound = userText.find("TTYL");
    if (posFound >= 0 ) {
        
        userText.replace(posFound, 4, "talk to you later");//Repalce first abbreviation
    }
    cout << "Expanded: " << userText << endl;

   return 0;
}
