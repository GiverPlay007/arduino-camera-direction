#include<Servo.h>

#define axisX 9
#define axisY 10

#define xDir1 0
#define xDir2 1
#define yDir1 2
#define yDir2 3

Servo servoX;
Servo servoY;

int angleX = 0;
int angleY = 0;

int lastX = 0;
int lastY = 0;

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

void loop()
{
    checkAxisX();
    checkAxisY();
}

void checkAxisX()
{
    if(digitalRead(xDir1))
    {
        ++angleX;

        if(angleX > 180)
        {
            angleX = 180;
        }
    }

    if(digitalRead(xDir2))
    {
        --angleX;

        if(angleX < 0)
        {
            angleX = 0;
        }
    }

    if(angleX != lastX)
    {
        servoX.write(angleX);
        lastX = angleX;
    }
}

void checkAxisY()
{
    if(digitalRead(yDir1))
    {
        ++angleY;

        if(angleY > 180)
        {
            angleY = 180;
        } 
    }

    if(digitalRead(yDir2))
    {
        --angleY;

        if(angleY < 0)
        {
            angleY = 0;
        }
    }

    if(angleY != lastY)
    {
        servoY.write(angleY);
        lastY = angleY;
    }
}