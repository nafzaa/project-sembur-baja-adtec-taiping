#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(10, 11); // RX | TX 
int flag = 0; 
int MOTOR1 = 14;
int MOTOR2 = 15;
int MOTOR3 = 16;
int MOTOR4 = 17;

int MOTOR9 = 4;
int MOTOR10 = 6;

int state = 0;

int levelwatersensor1 = 2;
int levelwatersensor2 = 3;

int valuesensor1 = 0;
int valuesensor2 = 0;

int relayred1 = 30;
int relaygreen1 = 31;

int relayred2 = 32;
int relaygreen2 = 33;

void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 pinMode(MOTOR1, OUTPUT);
 pinMode(MOTOR2, OUTPUT);
 pinMode(MOTOR3, OUTPUT);
 pinMode(MOTOR4, OUTPUT);

 pinMode(MOTOR9, OUTPUT);
 pinMode(MOTOR10, OUTPUT);

 pinMode (levelwatersensor1, INPUT);
 pinMode (levelwatersensor2, INPUT);

 pinMode (relayred1, OUTPUT);
 pinMode (relaygreen1, OUTPUT);
 pinMode (relayred2, OUTPUT);
 pinMode (relaygreen2, OUTPUT);

 digitalWrite (relayred1, HIGH);
 digitalWrite (relaygreen1, HIGH);
 digitalWrite (relayred2, HIGH);
 digitalWrite (relaygreen2, HIGH);
 
  
} 
void loop() 
{ 
  valuesensor1 = digitalRead (levelwatersensor1);
  valuesensor2 = digitalRead (levelwatersensor2);

  if (valuesensor1 == HIGH){
    digitalWrite (relayred1, HIGH);
    digitalWrite (relaygreen1, LOW);
    }

  else {
    digitalWrite (relayred1, LOW);
    digitalWrite (relaygreen1, HIGH);
    }

  if (valuesensor2 == HIGH){
    digitalWrite (relayred2, HIGH);
    digitalWrite (relaygreen2, LOW);
    }

  else {
    digitalWrite (relayred2, LOW);
    digitalWrite (relaygreen2, HIGH);
    }
  

  
 if (MyBlue.available()) 
   flag = MyBlue.read(); 

   if (flag == 'Z') 
 { 
    Stop();
 } 
 else if (flag == 'A') 
 { 
    Depan();
 }
 else if (flag == 'B') 
 { 
    Belakang();
 }
 else if (flag == 'C') 
 { 
    Kanan();
 }
 else if (flag == 'D') 
 { 
    Kiri();
 }

 else if (flag == 'E')
 {
    state = 1;
 }

 else if (flag == 'F')
 {
    state = 0;
 }

 if (state == 1)
 {
   digitalWrite (MOTOR9, HIGH);
   digitalWrite (MOTOR10, HIGH);
   Serial.println ("on");
 }

 else if (state == 0)
 {
   digitalWrite (MOTOR9, LOW);
   digitalWrite (MOTOR10, LOW);
   Serial.println ("off");
 }

}  

void Stop(){
  digitalWrite (MOTOR1, LOW);
  digitalWrite (MOTOR2, LOW);
  digitalWrite (MOTOR3, LOW);
  digitalWrite (MOTOR4, LOW);

  }

void Depan(){
  digitalWrite (MOTOR1, HIGH);
  digitalWrite (MOTOR2, LOW);
  digitalWrite (MOTOR3, LOW);
  digitalWrite (MOTOR4, HIGH);

  
  }

void Belakang(){
  digitalWrite (MOTOR1, LOW);
  digitalWrite (MOTOR2, HIGH);
  digitalWrite (MOTOR3, HIGH);
  digitalWrite (MOTOR4, LOW);

  }

void Kanan(){
  digitalWrite (MOTOR1, HIGH);
  digitalWrite (MOTOR2, LOW);
  digitalWrite (MOTOR3, HIGH);
  digitalWrite (MOTOR4, LOW);

  }

void Kiri(){
  digitalWrite (MOTOR1, LOW);
  digitalWrite (MOTOR2, HIGH);
  digitalWrite (MOTOR3, LOW);
  digitalWrite (MOTOR4, HIGH);
 
  }
