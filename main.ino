#include<Servo.h>

#define axisX 9
#define axisY 10

#define xDir1 0
#define xDir2 1
#define yDir1 2
#define yDir2 3

Servo servoX;
Servo servoY;

void setup()
{
    Serial.begin(9600);

    pinMode(xDir1, INPUT);
    pinMode(xDir2, INPUT);
    pinMode(yDir1, INPUT);
    pinMode(yDir2, INPUT);

    servoX.attach(axisX);
    servoY.attach(axisY);
    
    servoX.write(0);
    servoY.write(0);
}

void update()
{

}