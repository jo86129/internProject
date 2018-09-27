#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

const int button0Pin = 2;     // the number of the pushbutton pin
const int button1Pin = 3;
const int button2Pin = 4;
const int button3Pin = 5;
const int button4Pin = 6;
int buzzerPin=8;
int num=0; //bomb number
// variables will change:
int buttonState[5]={0,0,0,0,0}; //按鈕狀態
int beforeState[5]={0,0,0,0,0}; //前一刻的狀態
int sound[4]={500,700,900,1100};
int soundNum=0;

void printDetail(uint8_t type, int value);

void setup() {
  pinMode(button0Pin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(buzzerPin,OUTPUT);
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));

    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  myDFPlayer.playMp3Folder(6);
         delay(500);
         if (myDFPlayer.available()) {
            printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
        }

}

void loop() {
 button0();
 button1();
 button2();
 button3();
 button4();
  
}

void button0(){
   buttonState[0]=digitalRead(button0Pin);
  
   if(buttonState[0]==1 and beforeState[0]==0)
    {
      
      Serial.println("0");
      num=random(0,6);
      if(num==0)
      {
         Serial.println("bomb");
         soundNum=random(1,5);
         Serial.println(soundNum);
         myDFPlayer.playMp3Folder(soundNum);
         delay(500);
         if (myDFPlayer.available()) {
          printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
          }
      }
    }

 if(buttonState[0]!=beforeState[0])
   {
      delay(40);    
   }
   beforeState[0]=buttonState[0];

}
void button1(){
   buttonState[1]=digitalRead(button1Pin);
   if(buttonState[1]==1 and beforeState[1]==0)
    {
       Serial.println("1");
      num=random(0,6);
      if(num==1)
      {
         Serial.println("bomb");
         soundNum=random(1,5);
         Serial.println(soundNum);
         myDFPlayer.playMp3Folder(soundNum);
         delay(500);
         if (myDFPlayer.available()) {
              printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
         }
      }
    }

 if(buttonState[1]!=beforeState[1])
   {
      delay(40);    
   }
   beforeState[1]=buttonState[1];

}
void button2(){
   buttonState[2]=digitalRead(button2Pin);
   if(buttonState[2]==1 and beforeState[2]==0)
    {
       Serial.println("2");
      num=random(0,6);
      if(num==2)
      {
         Serial.println("bomb");
         soundNum=random(1,5);
         Serial.println(soundNum);
         myDFPlayer.playMp3Folder(soundNum);
         delay(500);
         if (myDFPlayer.available()) {
          printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
          }
      }
    }

 if(buttonState[2]!=beforeState[2])
   {
      delay(40);    
   }
   beforeState[2]=buttonState[2];

}
void button3(){
   buttonState[3]=digitalRead(button3Pin);
   if(buttonState[3]==1 and beforeState[3]==0)
    {
       Serial.println("3");
      num=random(0,6);
      if(num==3)
      {
         Serial.println("bomb");
         soundNum=random(1,5);
         Serial.println(soundNum);
         myDFPlayer.playMp3Folder(soundNum);
         delay(500);
         if (myDFPlayer.available()) {
           printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
          }
      }
    }

 if(buttonState[3]!=beforeState[3])
   {
      delay(40);    
   }
   beforeState[3]=buttonState[3];

}
void button4(){
   buttonState[4]=digitalRead(button4Pin);
   if(buttonState[4]==1 and beforeState[4]==0)
    {
       Serial.println("4");
      num=random(0,6);
      if(num==4)
      {
         Serial.println("bomb");
         soundNum=random(1,5);
         Serial.println(soundNum);
         myDFPlayer.playMp3Folder(soundNum);
         delay(500);
         if (myDFPlayer.available()) {
            printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
        }
      }
    }

 if(buttonState[4]!=beforeState[4])
   {
      delay(40);    
   }
   beforeState[4]=buttonState[4];

}
void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

