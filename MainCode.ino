#include <Wire.h>                                                                         
#include <LCD.h>                                                                         
#include <LiquidCrystal_I2C.h>                                                            
#include <Wtv020sd16p.h>                                                                  
#define I2C_ADDR 0x3F                                                                
#define Rs_pin 0                                                              
#define Rw_pin 1                                                            
#define En_pin 2                                                              
#define BACKLIGHT_PIN 3                                                             
#define D4_pin 4                                                              
#define D5_pin 5                                                              
#define D6_pin 6                                                            
#define D7_pin 7                                                              
const int s0 = 8;                                                                   
const int s1 = 9;                                                                   
const int s2 = 12;                                                                 
const int s3 = 11;                                                                    
const int out = 10;                                                                    
int red = 0;                                                                              
int green = 0;                                                                            
int blue = 0;                                                                               
int resetPin = 2;                                                               
int clockPin = 3;                                                             
int dataPin = 4;                                                                
int busyPin = 5;                                                                
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);   
Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);                      
void setup()                                                                              
{  
  lcd.begin (20,2);                                                               
  Serial.begin(9600);                                                     
  pinMode(s0, OUTPUT);                                                                 
  pinMode(s1, OUTPUT);                                                                 
  pinMode(s2, OUTPUT);                                                               
  pinMode(s3, OUTPUT);                                                                 
  pinMode(out, INPUT);                                                                 
  digitalWrite(s0, HIGH);                                                           
  digitalWrite(s1, HIGH);  
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);                                    
  lcd.setBacklight(HIGH);                                                         
  lcd.home ();                                                                    
  wtv020sd16p.reset();                                                                 
 }  
    
void loop() 
{  
  
  color();                                                                           
  Serial.print("R Intensity:");                                                           
  Serial.print(red, DEC);                                                                 
  Serial.print(" G Intensity: ");                                                           
  Serial.print(green, DEC);                                                         
  Serial.print(" B Intensity : ");                                                        
  Serial.print(blue, DEC);                                                                

     if (red==20 || red==18 || red==29 && green==28 || green==27 || green==27 && blue==27 || blue==28 || blue==26)      
  {                                                                                                                     
   wtv020sd16p.playVoice(2);                                                                                           
   lcd.print("Brown");                                                                                                 
   delay (5000);                                                                                                        
   lcd.clear ();                                                                                                        
  }
  if (red==8 || red==9 || red==10 && green==7 || green==8 || green==9 && blue==13 || blue==14 || blue==15)             
  {                                                                                                                     
   wtv020sd16p.playVoice(4);                                                                                            
   lcd.print("Green");                                                                                                 
   delay (5000);                                                                                                        
   lcd.clear ();                                                                                                        
  }
  
   
  
if (red==19 || red==20 || red==21 && green==17 || green==18 || green==19 && blue==10 || blue==11 || blue==12)           
  {                                                                                                                     
   wtv020sd16p.playVoice(3);                                                                                            
   lcd.print("Blue");                                                                                                  
   delay (5000);                                                                                                        
   lcd.clear ();                                                                                                        
  }
  
  
 if (red==6 || red==5 || red==7 && green==20 || green==19 || green==21 && blue==17 || blue==18 || blue==16)           
  {                                                                                                                     
   wtv020sd16p.playVoice(0);                                                                                           
   lcd.print("Red");                                                                                                   
   delay (5000);                                                                                                        
   lcd.clear ();                                                                                                        
  }

  
 if (red==3 || red==4 || red==5 && green==6 || green==7 || green==8 && blue==9 || blue==10 || blue==11)                
  {                                                                                                                     
   wtv020sd16p.playVoice(1);                                                                                            
   lcd.print("Yellow");                                                                                                
   delay (5000);                                                                                                        
   lcd.clear ();                                                                                                        
  }
  
  
  else{                                                                                                                 
  Serial.println();                                                                                                  
  }                                                                                                                     
  delay(300);                                                                                                           
 
 }  
    
void color() 
{                                                                                                          
  digitalWrite(s2, LOW);                                                                                                
  digitalWrite(s3, LOW);                                                                                                
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);                                                            
  digitalWrite(s3, HIGH);                                                                                              
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);                                                           
  digitalWrite(s2, HIGH);                                                                                               
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);                                                          
}
