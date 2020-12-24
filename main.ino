#include<Servo.h>

#define AXIS_X 9
#define AXIS_Y 10

#define X_DIR_1 0
#define X_DIR_2 1
#define Y_DIR_1 2
#define Y_DIR_2 3

#define X_SPEED_INPUT A0
#define Y_SPEED_INPUT A1

Servo servoX;
Servo servoY;

int angleX = 0;
int angleY = 0;

int lastX = 0;
int lastY = 0;

int xSpeed = 1;
int ySpeed = 1;

void setup()
{
    pinMode(X_DIR_1, INPUT);
    pinMode(X_DIR_2, INPUT);
    pinMode(Y_DIR_1, INPUT);
    pinMode(Y_DIR_2, INPUT);
    pinMode(X_SPEED_INPUT, INPUT);
    pinMode(Y_SPEED_INPUT, INPUT);

    servoX.attach(AXIS_X);
    servoY.attach(AXIS_Y);

    servoX.write(0);
    servoY.write(0);
}

void loop()
{
    checkSpeedX();
    checkSpeedY();
    checkAxisX();
    checkAxisY();
}

void checkSpeedX()
{
    xSpeed = (int) (10 / 1024 * analogRead(X_SPEED_INPUT));
}

void checkSpeedY()
{
    ySpeed = (int) (10 / 1024 * analogRead(Y_SPEED_INPUT));
}

void checkAxisX()
{
    if(digitalRead(X_DIR_1))
    {
        angleX += xSpeed;

        if(angleX > 180)
        {
            angleX = 180;
        }
    }

    if(digitalRead(X_DIR_2))
    {
        angleX -= xSpeed;

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
    if(digitalRead(Y_DIR_1))
    {
        angleY += ySpeed;

        if(angleY > 180)
        {
            angleY = 180;
        } 
    }

    if(digitalRead(Y_DIR_2))
    {
        angleY -= ySpeed;

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