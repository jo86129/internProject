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

void setup() {
  pinMode(button0Pin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(9600);

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
         tone(buzzerPin,1000);
          delay(500);
         noTone(buzzerPin);
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
         tone(buzzerPin,1000);
         delay(500);
         noTone(buzzerPin);
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
         tone(buzzerPin,1000);
         delay(500);
         noTone(buzzerPin);
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
         tone(buzzerPin,1000);
         delay(500);
         noTone(buzzerPin);
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
         tone(buzzerPin,1000);
         delay(500);
         noTone(buzzerPin);
      }
    }

 if(buttonState[4]!=beforeState[4])
   {
      delay(40);    
   }
   beforeState[4]=buttonState[4];

}


