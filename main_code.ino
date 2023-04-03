/* 
We have tried to remake a project from the website how to mechatronics.
https://howtomechatronics.com/projects/arduino-robot-arm-and-mecanum-wheels-platform-automatic-operation/
*/

#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;

int wheelspeed = 255;
int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos; // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos; // previous position
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50];

int speedDelay = 25;
char m='0';

int enA = 11;//lf
int in1 = 2;
int in2 = 3;

int enB = 9;//rf
int in3 = 4;
int in4 = 5;

int enA1 = 10;//lb
int in5 = 22;
int in6 = 24;

int enB1 = 8;//rb
int in7 = 32;
int in8 = 34;
 
void setup() {

  servo01.attach(36);
  servo02.attach(37);
  servo03.attach(38);
  servo04.attach(39);
  servo05.attach(40);
  
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(enA1,OUTPUT);
  pinMode(enB1,OUTPUT);
  pinMode(in1,OUTPUT);  
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(in5,OUTPUT);
  pinMode(in6,OUTPUT);
  pinMode(in7,OUTPUT);
  pinMode(in8,OUTPUT);
  
  // Stop all motor
  digitalWrite(in1,LOW);// lf motor
  digitalWrite(in2,LOW);// lf motor
  digitalWrite(in3,LOW);// rf motor 
  digitalWrite(in4,LOW);// rf motor
  digitalWrite(in5,LOW);// lb motor
  digitalWrite(in6,LOW);// lb motor
  digitalWrite(in7,LOW);// rb motor
  digitalWrite(in8,LOW);// rb motor
  
  // initialize all the servos 
  servo1PPos = 90;
  servo01.write(servo1PPos);
  servo2PPos = 100;
  servo02.write(servo2PPos);
  servo3PPos = 120;
  servo03.write(servo3PPos);
  servo4PPos = 95;
  servo04.write(servo4PPos);
  servo5PPos = 60;
  servo05.write(servo5PPos);  

  Serial.begin(9600);
}
// m is the variable in which the commands from the bluetooth app is stored.
void loop() {
if(Serial.available()){
  m = Bluetooth.read(); 
}
 while (m == 0){
  stopall();
  }
 while (m == 2){
  moveForward();
}
 while(m == 7){
  moveBackward();
  }
 while (m == 5){
  rotateRight();
  }
 while (m == 4){
  rotateLeft();
  } 
  // The code below controls the robotic arm's servo motors to either move in the positive direction or the negative direction.
  // Moves servo 1 in positive direction or the negative direction.
  while (m == 27) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo01.write(servo1PPos);
      servo1PPos++;
      delay(speedDelay);
    }
    // Move servo 1 in negative direction
    while (m == 26) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo01.write(servo1PPos);
      servo1PPos--;
      delay(speedDelay);
    }
    // Move servo 2
    while (m == 25) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo02.write(servo2PPos);
      servo2PPos++;
      delay(speedDelay);
    }
    while (m == 24) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo02.write(servo2PPos);
      servo2PPos--;
      delay(speedDelay);
    }
    // Move servo 3
    while (m == 23) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo03.write(servo3PPos);
      servo3PPos++;
      delay(speedDelay);
    }
    while (m == 22) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo03.write(servo3PPos);
      servo3PPos--;
      delay(speedDelay);
    }
    // Move servo 4
    while (m == 21) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo04.write(servo4PPos);
      servo4PPos++;
      delay(speedDelay);
    }
    while (m == 20) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo04.write(servo4PPos);
      servo4PPos--;
      delay(speedDelay);
    }
    // Move servo 5
    while (m == 19) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo05.write(servo5PPos);
      servo5PPos++;
      delay(speedDelay);
    }
    while (m == 18) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo05.write(servo5PPos);
      servo5PPos--;
      delay(speedDelay);
    }
}
void stopall(){
  digitalWrite(in1,LOW);// lf motor
  digitalWrite(in2,LOW);// lf motor
  digitalWrite(in3,LOW);// rf motor 
  digitalWrite(in4,LOW);// rf motor
  digitalWrite(in5,LOW);// lb motor
  digitalWrite(in6,LOW);// lb motor
  digitalWrite(in7,LOW);// rb motor
  digitalWrite(in8,LOW);// rb motor
  analogWrite(enA,0);//lf motor
  analogWrite(enB,0);//rf motor
  analogWrite(enA1,0);//lb motor
  analogWrite(enB1,0);//rb motor
  }
void moveForward(){
  digitalWrite(in1,HIGH);//lf motor
  digitalWrite(in2,LOW);//lf motor
  digitalWrite(in3,HIGH);//rf motor
  digitalWrite(in4,LOW);//rf motor
  digitalWrite(in5,HIGH);//lb motor
  digitalWrite(in6,LOW);//lb motor
  digitalWrite(in7,HIGH);//rb motor
  digitalWrite(in8,LOW);//rb motor
  analogWrite(enA,wheelspeed);//lf motor
  analogWrite(enB,wheelspeed);//rf motor
  analogWrite(enA1,wheelspeed);//lb motor
  analogWrite(enB1,wheelspeed);//rb motor
}
void moveBackward(){
  digitalWrite(in1,LOW);//lf motor
  digitalWrite(in2,HIGH);//lf motor
  digitalWrite(in3,LOW);//rf motor
  digitalWrite(in4,HIGH);//rf motor
  digitalWrite(in5,LOW);//lb motor
  digitalWrite(in6,HIGH);//lb motor
  digitalWrite(in7,LOW);//rb motor
  digitalWrite(in8,HIGH);//rb motor
  analogWrite(enA,wheelspeed);//lf motor
  analogWrite(enB,wheelspeed);//rf motor
  analogWrite(enA1,wheelspeed);//lb motor
  analogWrite(enB1,wheelspeed);//rb motor
}
void rotateRight(){
  digitalWrite(in1,LOW);//lf motor
  digitalWrite(in2,HIGH);//lf motor
  digitalWrite(in3,HIGH);//rf motor
  digitalWrite(in4,LOW);//rf motor
  digitalWrite(in5,LOW);//lb motor
  digitalWrite(in6,HIGH);//lb motor
  digitalWrite(in7,HIGH);//rb motor
  digitalWrite(in8,LOW);//rb motor
  analogWrite(enA,wheelspeed);//lf motor
  analogWrite(enB,wheelspeed);//rf motor
  analogWrite(enA1,wheelspeed);//lb motor
  analogWrite(enB1,wheelspeed);//rb moto
}
void rotateLeft(){
  digitalWrite(in1,HIGH);//lf motor
  digitalWrite(in2,LOW);//lf motor
  digitalWrite(in3,LOW);//rf motor
  digitalWrite(in4,HIGH);//rf motor
  digitalWrite(in5,HIGH);//lb motor
  digitalWrite(in6,LOW);//lb motor
  digitalWrite(in7,LOW);//rb motor
  digitalWrite(in8,HIGH);//rb motor
  analogWrite(enA,wheelspeed);//lf motor
  analogWrite(enB,wheelspeed);//rf motor
  analogWrite(enA1,wheelspeed);//lb motor
  analogWrite(enB1,wheelspeed);//rb moto
}
