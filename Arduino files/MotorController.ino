//Arduino Serial DC motors
//A program to control dc motors using H bridge (l293d) using Serial Communication with a PC.
//Author:Balakumar Sundarlingam
#include <SoftPWM_timer.h>
#include <SoftPWM.h>
#include <SoftwareSerial.h>
#define RXD 6
#define TXD 7
int motorLeftP=8;
int motorLeftG=9;
int motorRightP=10;
int motorRightG=11;
//char inputData;
SoftwareSerial blueToothSerial(RXD,TXD);
void setup()
{
pinMode(motorLeftP,OUTPUT);
pinMode(motorLeftG,OUTPUT);
pinMode(motorRightP,OUTPUT);
pinMode(motorRightG,OUTPUT);

//Software pwm
SoftPWMBegin();
SoftPWMSet(motorLeftP,0);
SoftPWMSet(motorLeftG,0);
SoftPWMSet(motorRightP,0);
SoftPWMSet(motorRightG,0);

SoftPWMSetFadeTime(ALL,2000,2000);

//Serial communication initialization
Serial.begin(9600);
blueToothSerial.begin(9600);
//blueToothSerial.println("The slave bluetooth is inquirable!");
//blueToothSerial.flush();
//void setupBlueToothConnection();
}
void loop()
{
  if(blueToothSerial.available()>0)
  {  
     char inputData=blueToothSerial.read();
     blueToothSerial.write(inputData);
     if(inputData=='w')
     {
       SoftPWMSetPercent(motorLeftP,65);
       SoftPWMSetPercent(motorLeftG,0);
       SoftPWMSetPercent(motorRightP,80);
       SoftPWMSetPercent(motorRightG,0);
     }
     if(inputData=='s')
     {
       SoftPWMSetPercent(motorLeftP,0);
       SoftPWMSetPercent(motorLeftG,65);
       SoftPWMSetPercent(motorRightP,0);
       SoftPWMSetPercent(motorRightG,80);
     }
     if(inputData=='a')
     {
       SoftPWMSetPercent(motorLeftP,0);
       SoftPWMSetPercent(motorLeftG,65);
       SoftPWMSetPercent(motorRightP,100);
       SoftPWMSetPercent(motorRightG,0);
     }
     if(inputData=='d')
     {
       SoftPWMSetPercent(motorLeftP,65);
       SoftPWMSetPercent(motorLeftG,0);
       SoftPWMSetPercent(motorRightP,0);
       SoftPWMSetPercent(motorRightG,100);
     }
     if(inputData=='t')
     {
       SoftPWMSetPercent(motorLeftP,0);
       SoftPWMSetPercent(motorLeftG,0);
       SoftPWMSetPercent(motorRightP,0);
       SoftPWMSetPercent(motorRightG,0);
     }
     if(inputData=='W')
     {
       SoftPWMSetPercent(motorLeftP,85);
       SoftPWMSetPercent(motorLeftG,0);
       SoftPWMSetPercent(motorRightP,100);
       SoftPWMSetPercent(motorRightG,0);
     }
     if(inputData=='S')
     {
       SoftPWMSetPercent(motorLeftP,0);
       SoftPWMSetPercent(motorLeftG,85);
       SoftPWMSetPercent(motorRightP,0);
       SoftPWMSetPercent(motorRightG,100);
     }
     if(inputData=='A')
     {
       SoftPWMSetPercent(motorLeftP,0);
       SoftPWMSetPercent(motorLeftG,85);
       SoftPWMSetPercent(motorRightP,100);
       SoftPWMSetPercent(motorRightG,0);
     }
     if(inputData=='D')
     {
       SoftPWMSetPercent(motorLeftP,85);
       SoftPWMSetPercent(motorLeftG,0);
       SoftPWMSetPercent(motorRightP,0);
       SoftPWMSetPercent(motorRightG,100);
     }
     if(inputData=='T')
     {
       SoftPWMSetPercent(motorLeftP,0);
       SoftPWMSetPercent(motorLeftG,0);
       SoftPWMSetPercent(motorRightP,0);
       SoftPWMSetPercent(motorRightG,0);
     }
     
  }
  
}     

