//
//  main.cpp
//  Drawing a half arrow
//
//  Created by Danny Webb-McClain on 9/23/21.
//

#include <iostream>

#include <iostream>
using namespace std;

int main() {
   int arrowBaseHeight;
   int arrowBaseWidth;
   int arrowHeadWidth;
    
   
   cout << "Enter arrow base height:" << endl;
   cin >> arrowBaseHeight;
   
   cout << "Enter arrow base width:" << endl;
   cin >> arrowBaseWidth;
   
   cout << "Enter arrow head width:" << endl;
   cin >> arrowHeadWidth;
   
    while (arrowHeadWidth <= arrowBaseWidth) {
        cout << "Enter arrow head width:" << endl;
        cin >> arrowHeadWidth;
    }
    cout << endl;
   
   // Draw arrow base
    for (int i = 0; i < arrowBaseHeight; ++i){
        for (int j = 0; j < arrowBaseWidth; ++j){
            cout<< "*";
        }
        cout<< endl;
    }
    // Draw arrow head
    for(int i = arrowHeadWidth; i > 0; --i){
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    
   
   
   return 0;
}
