/* The following program demonstrates the use of class and objects in C++
 * The class in this case is a Cell Phone with multiple properties and functionalities baked in.
 * When the program starts it creates a default cell phone with some default properties.
 * Then it allows the user to create a new cell phone with custom specifications.
 * After the user customized cell phone has been created, it will allow some behaviours of the cell phone to be changed.
 * Namely, Calling a contact and Charging the phone.
 * At last, with the implementation of a custom destructor, it gives a beautiful message.
 *
 * Author: Dhiraj Phuyal
 * Date: July 31, 2020
 *
 * Update (August 1, 2020):
 * New Features added:
 *      PlayGame() added,
 *      And sleep timers are also added throughout the program.
 * */

#include <iostream>

#include "../HeaderFiles/CellPhone.h"
#include "../HeaderFiles/functions.h"
using namespace std;

int main(){
    long int cellNumber;
    int userChoice;
    static CellPhone defaultCellphone;      // Creating a cell phone with default constructors

    cout << "Default Cell Phone: " << endl;
    displayCellInfo(defaultCellphone);   // Displaying the properties of default Cell Phone

    //Making new cell phone with user specifications
    CellPhone userCellPhone = createNewCellPhone();

    cout << endl << "Congratulations your new cell phone has been created with following specifications: " << endl;
    displayCellInfo(userCellPhone);

    do {
        if(userCellPhone.getBatteryPercentage() >= 20){
            displayMenu(userChoice);
            switch (userChoice) {
                case 0:
                    return 0;
                case 1:
                    long int callingNumber;

                    cout << "Enter the number you want to call: ";
                    cin >> callingNumber;

                    userCellPhone.setCallingContactNumber(callingNumber);
                    userCellPhone.call();
                    break;
                case 2:
                    userCellPhone.endCall();
                    break;
                case 3:
                    userCellPhone.charge();
                    break;
                case 4:
                    cout << "Enter new cell number: ";
                    cin >> cellNumber;

                    if (cellNumber == userCellPhone.getCellNumber())
                        cout << "New number can't be same as your previous number." << endl;
                    else
                        userCellPhone.setCellNumber(cellNumber);
                    break;
                case 5:
                    userCellPhone.playGame();
                    break;
                case 6:
                    cout << "Remaining Battery Percentage: " << userCellPhone.getBatteryPercentage() << endl;
                    break;
                case 7:
                    cout << "Your Cell Number is " << userCellPhone.getCellNumber() << endl;
                    break;
                default:
                    cout << "Invalid Input!!!" << endl;
            }

            cout << "Press 0 to exit or 1 to show menu: ";
            cin >> userChoice;
        }
        else {
            int temp;
            cout << "Your battery percentage is too low. You need to recharge." << endl;
            cout << "Press 1 to recharge: ";
            cin >> temp;

            while (temp != 1){
                cout << "Invalid input! Press 1 to recharge: ";
                cin >> temp;
            }

            userCellPhone.charge();
        }
    } while (userChoice != 0);     //Repeatedly provide choices to the user until the user presses 0

}

