#include <Arduino.h>
class MotorDriver {
private:
    int enA; // Enable pin for Motor A
    int in1;
    int in2; 
    int enB; // Enable pin for Motor B
    int in3; 
    int in4; 
    int speed;

public:
    MotorDriver(int enA, int in1, int in2, int enB, int in3, int in4) {
        this->enA = enA;
        this->in1 = in1;
        this->in2 = in2;
        this->enB = enB;
        this->in3 = in3;
        this->in4 = in4;
        this->speed = 255;
        pinMode(enA, OUTPUT);
        pinMode(in1, OUTPUT);
        pinMode(in2, OUTPUT);
        pinMode(enB, OUTPUT);
        pinMode(in3, OUTPUT);
        pinMode(in4, OUTPUT);
    }


    void setSpeed(int speed) {
        this->speed = speed;
    }


    void forward() {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enA, speed);
        analogWrite(enB, speed);
    }


    void backward() {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(enA, speed);
        analogWrite(enB, speed);
    }


    void left() {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enA, speed);
        analogWrite(enB, speed);
    }


    void right() {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(enA, speed);
        analogWrite(enB, speed);
    }


    void stop() {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
    }
};