//
// Created by dhiraj on 8/1/20.
//

#ifndef ASSIGNMENT3_CELLPHONE_H
#define ASSIGNMENT3_CELLPHONE_H
class CellPhone{
private:
    long int cellNumber, callingContactNumber = 0;
    bool isCalling;
    float screenSize;
    int batteryPercentage;
public:
    CellPhone();

    CellPhone(long int, float );

    ~CellPhone();

    void setCellNumber(long int);
    long int getCellNumber();

    void setCallingContactNumber(long int);
    long int getCallingContactNumber();

    void call();
    void endCall();
    bool getIsCalling();

    void playGame();

    void setScreenSize(float);
    float getScreenSize();

    void charge();                // named as Charge instead of a setter
    int getBatteryPercentage();
    void showRemainingBattery();
};


#endif //ASSIGNMENT3_CELLPHONE_H
