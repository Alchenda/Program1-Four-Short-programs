//
//  main.cpp
//  Program1
//
//  Created by Danny Webb-McClain on 9/22/21.
//

#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    double height, width; //variables for height and width of the wall
    double area; //the results of height and width being multiplied
    double paintNeeded;//the amount of paint needed for the wall
    unsigned int cansNeeded; //number of cans that will be needed for painting
    //prompt user to enter wall height
    cout << "Enter wall height (feet) :" << endl;
    cin >> height;
    cout << "\nEnter wall width (feet) :" << endl;
    cin >> width;
    area = height * width;
    //outputs the wall's area, with a decimal limit of 2
    cout << "Wall area: " << setprecision(2)<< fixed <<area << " square feet" << endl;
    
    //calculation for paint needed for the wall
    paintNeeded = area / 350;
    cout << "Paint needed: " << setprecision(2) << fixed << paintNeeded << " gallons" << endl;
    cansNeeded = round(paintNeeded);
    cout << "Cans needed: " << cansNeeded << " can (s)" << endl;
    
    
    return 0;
}
