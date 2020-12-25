#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2);
Servo servoMotor2;

int trigPin2 = 6; 
int echoPin2 = 3;   //

int sensor0;
int sensor1;
int sensor2;
int sensor3;

long mesafe2;
long sure2;

int sensor0Pin = A0; // tcrt5000 kızılötesi sensör
int sensor1Pin = A1;
int sensor2Pin = A2;
int sensor3Pin = A3;

void setup(){
  
  lcd.begin();
  lcd.backlight();

  sensor0=0;
  sensor1=0;
  sensor2=0;
  sensor3=0;
  
  

  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2,INPUT); 
  Serial.begin(9600); 
  servoMotor2.attach(9);
}
void loop()
{
 
  //Çıkış
  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);   
  delayMicroseconds(10);
  sure2 = pulseIn(echoPin2, HIGH);
  mesafe2 = sure2/29.1/2; 
  

 


   sensor0 = analogRead(sensor0Pin); // Sensorlerden gelen degerler
   sensor1 = analogRead(sensor1Pin); // Sensorlerden gelen degerler
   sensor2 = analogRead(sensor2Pin); // Sensorlerden gelen degerler
   sensor3 = analogRead(sensor3Pin); // Sensorlerden gelen degerler
 
   if (sensor0 < 900 ) // AnalogRead 1024 farkli deger okur.Yarisi kadar hassasiyetle hesaba katarak 
   { // sensorden gelen bilgi alindi. 
      sensor0=1;
      
      lcd.setCursor(0, 0);
      lcd.print("1=DOLU");
      
   }else{ 
      sensor0=0;
      lcd.setCursor(0, 0);
      lcd.print("1=BOS"); 
   }


   if (sensor1 < 900 ) // AnalogRead 1024 farkli deger okur.Yarisi kadar hassasiyetle hesaba katarak 
   { // sensorden gelen bilgi alindi. 
      sensor1=1;
      lcd.setCursor(8, 0);
      lcd.print("2=DOLU");
      
   }else{ 
      sensor1=0;
      lcd.setCursor(8, 0);
      lcd.print("2=BOS"); 
   }


   if (sensor2 < 900 ) // AnalogRead 1024 farkli deger okur.Yarisi kadar hassasiyetle hesaba katarak 
   { // sensorden gelen bilgi alindi. 
      sensor2=1;
      lcd.setCursor(0, 1);
      lcd.print("3=DOLU");
      
    }else{ 
      sensor2=0;
      lcd.setCursor(0, 1);
      lcd.print("3=BOS");    
    }

   if (sensor3 < 900 ) // AnalogRead 1024 farkli deger okur.Yarisi kadar hassasiyetle hesaba katarak 
   { // sensorden gelen bilgi alindi. 
      sensor3=1;
      lcd.setCursor(8, 1);
      lcd.print("4=DOLU");
      
   }else{ 
      sensor3=0;
      lcd.setCursor(8, 1);
      lcd.print("4=BOS"); 
   }
  delay(500);
  if(mesafe2 <= 8){
    servoMotor2.write(0);
    delay(2500); 
  }else{
    servoMotor2.write(90);
    delay(500); 
  }
    lcd.clear();
}
