//
// Created by dhiraj on 8/1/20.
//

#include "../HeaderFiles/CellPhone.h"
#include <iostream>
#include <unistd.h>

#define sleeptime 2
using namespace std;

    CellPhone::CellPhone() : cellNumber(9812345678), isCalling(false), screenSize(5.5), batteryPercentage(50)
    {}                                                                        // The cell phone will be 50% charged when created
    CellPhone::CellPhone(long int number, float scSize):
            cellNumber(number), isCalling(false), screenSize(scSize), batteryPercentage(50)
    {}                         // When a phone is first created it is not calling
    CellPhone::~CellPhone() {
        cout << endl << this->cellNumber <<" is being destroyed. Be a responsible human being and reduce e-waste. ;) " << endl;
    }

    void CellPhone::setCellNumber(long int no){this->cellNumber = no;}
    long int CellPhone::getCellNumber(){return this->cellNumber;}

    void CellPhone::setCallingContactNumber(long int no){this->callingContactNumber = no;}
    long int CellPhone::getCallingContactNumber(){return callingContactNumber;}

    void CellPhone::call(){                         // Call and end call function instead of naming as setters
        int userCallTimeChoice;
        //TODO: Make 10 seconds count even when the user hasn't pressed 0

        if (this->batteryPercentage >= 10) {
            this->isCalling = true;
            this->batteryPercentage -= 10;

            cout << "The call will be automatically ended in 10 seconds. "
                    "Or press 0 if you want the call to be longer: " << endl;
            cin >> userCallTimeChoice;
            cout << "In call with: " << getCallingContactNumber() << endl;

            if (userCallTimeChoice != 0){
                sleep(10);
                cout << "Call Ended" << endl;
                endCall();
            }
        }
    }

    void CellPhone::endCall(){
        cout << endl << "Ending call with " << this->getCallingContactNumber();
        setCallingContactNumber(0);
        this->isCalling = false;
        sleep(sleeptime);
    }

    bool CellPhone::getIsCalling(){return this->isCalling;}

    void CellPhone::playGame(){
        if (this->batteryPercentage >= 20) {
            this->batteryPercentage -= 20;
            cout << "Playing game" << endl;
            sleep(sleeptime);
            cout << "Game Played" << endl;
            showRemainingBattery();
        }
        else
            cout << "Can't play game battery percentage too low. Please recharge" << endl;
    }

    void CellPhone::setScreenSize(float size){this->screenSize = size;}
    float CellPhone::getScreenSize(){return this->screenSize;}

    void CellPhone::charge(){
        cout << "Charging phone" << endl;
        sleep(sleeptime);
        this->batteryPercentage = 100;
        cout << "Phone Charged" << endl;
        sleep(1);
    }                 // named as Charge instead of a setter

    int CellPhone::getBatteryPercentage(){return this->batteryPercentage;}
    void CellPhone::showRemainingBattery(){
        cout << "Remaining Battery Percentage: " << getBatteryPercentage() << endl;
    }


