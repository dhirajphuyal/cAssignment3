//
// Created by dhiraj on 8/1/20.
//

#include <iostream>
#include <unistd.h>

#include "../HeaderFiles/CellPhone.h"
#include "../HeaderFiles/functions.h"

#define sleeptime 1
using namespace std;

void displayCellInfo(CellPhone &phone){
    bool callStatus = phone.getIsCalling();
    string callStatusMessage;

    if (callStatus)
        callStatusMessage = "Yes";
    else
        callStatusMessage = "No";

    cout << endl <<"*********Cell Phone Description**********" << endl;
    cout << "Cell Number: "  << phone.getCellNumber() << endl;
    cout << "Screen Size (in inches): " << phone.getScreenSize() << endl;
    cout << "Battery Percentage: " << phone.getBatteryPercentage() << endl;
    cout << "Is the cell phone calling?: " << callStatusMessage << endl;
    if (callStatus)
        cout << "In call with: " << phone.getCallingContactNumber();

    sleep(sleeptime);
}

CellPhone createNewCellPhone(){
    float screenSize;
    long int cellNumber;

    cout << endl << "What size do you want your screen to be?(inches): ";
    cin >> screenSize;

    cout << "What do you want you cell number to be?: ";
    cin >> cellNumber;

    CellPhone newPhone(cellNumber, screenSize);
    return  newPhone;
}

void displayMenu(int &choice){

        cout << endl << "######MENU######" << endl;
        cout << "0: Exit" << endl;
        cout << "1: Make a call" << endl;
        cout << "2: End Call" << endl;
        cout << "3: Charge your phone" << endl;
        cout << "4: Change your cell number" << endl;
        cout << "5: Play a game" << endl;
        cout << "6: Show remaining battery percentage" << endl;
        cout << "7: Show cell number" << endl;
        cout << "Enter: ";

        cin >> choice;
}


