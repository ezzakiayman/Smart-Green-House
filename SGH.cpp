 #include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'#','0','*'},
  {'9','8','7'},
  {'6','5','4'},
  {'3','2','1'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int x1=0, x2=0, x3=0, x4=0, x=0,xx=0,y=0,y1=0,y2=0;
int  a=0,b=0,c=0,d=0,z=0;
int u,t;
int v ;


//*******************************************keypad
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// ******************************************
// LCD variables declaration
// ******************************************
// creating lcd instance "lcd" from the LiquidCrystal_I2C class constructor
LiquidCrystal_I2C lcd(0x3F, 16, 2);   // I2C address and LCD Size  
// ******************************************
#include <dht11.h>
dht11 DHT;
#define DHT11_PIN 12
void setup()
{ 
// initialize LCD   
  lcd.init();
  lcd.backlight();
  passw();
  int chk;
  chk = DHT.read(DHT11_PIN);    // READ DATA
              
// initialize serial port
  Serial.begin(9600); 
 // DISPLAT DATA  
ayman();
  lcd.clear();
      
// the following function is used to find the LCD Contoller address
//scanForI2CAddress();
pinMode(9,OUTPUT); 
pinMode(10,OUTPUT); 
pinMode(11,OUTPUT);
pinMode(13,OUTPUT);
pinMode(A0, INPUT);
}
// ******************************************
void loop()
{
 u = analogRead(A0);
 t = map (u,0,1023,0,100);
 v=100-t;
char key=keypad.getKey();
 displaySerialPortOnLCD();
  int chk;
  chk = DHT.read(DHT11_PIN);
  lcd.setCursor(0, 0);                
  lcd.print("eau:"); 
  lcd.setCursor(14, 0);                
  lcd.print("%");
  lcd.setCursor(7, 0);                
  lcd.print(v);
  lcd.setCursor(0, 1); 
  lcd.print("temp:");
  lcd.setCursor(14, 1);                
  lcd.print("C");
  lcd.setCursor(7, 1);                
  lcd.print(DHT.temperature,1);
  if(key=='#'){
   passw();
   }
  if(key=='*'){
 
    }
  //pompe
  delay(100);
  if(v<=y)
  {
  digitalWrite(11,HIGH);
  delay(200);
    }
  if(v>y)
  {
  digitalWrite(11,LOW);
  delay(200);
    }
//ventilateur
  if(DHT.temperature>x)
  {
  digitalWrite(9,HIGH);
  delay(200);
    }
  if(DHT.temperature<=x)
  {
  digitalWrite(9 ,LOW);
  delay(200);
    }
  //resistance 
    if(DHT.temperature<=xx)
  {
  digitalWrite(10,HIGH);
  digitalWrite(13,HIGH);
  delay(200);
    }
  if(DHT.temperature>xx)
  {
  digitalWrite(10 ,LOW);
  digitalWrite(13,LOW);
  delay(200);
    }

  
    
  
}
// *****************************************
// LCD Functions 
// ******************************************
void scanForI2CAddress()
{
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;
  Wire.begin();
  for (byte i = 1; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);  
      } 
  }
   
 } 
// ******************************************
void displaySerialPortOnLCD()
{
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // read each charachter from the serial port and display it in the LCD
      lcd.write(Serial.read());
    }
  } 
}
void ayman()
{
  //temperature(refroidissment)" x "
  lcd.clear();
  lcd.setCursor(15, 0);                
  lcd.print("C");
    lcd.setCursor(0, 0);  
  lcd.print("Tmax:");
  while(x1==0){x1=keypad.getKey(); }
  x1= x1-48;
  lcd.setCursor(6,0);
  lcd.print(x1);
  while(x2==0){x2=keypad.getKey(); }
  x2= x2-48;
  lcd.setCursor(7,0);
  lcd.print(x2);
  x= x1*10+x2;
  delay(1000);
  
  //temperature (chaffage) "xx"
  lcd.setCursor(15, 1);                
  lcd.print("C");
  lcd.setCursor(0, 1);                
  lcd.print("Tmin:");
  while(x3==0){x3=keypad.getKey(); }
  x3= x3-48;
  lcd.setCursor(6,1);
  lcd.print(x3);
  while(x4==0){x4=keypad.getKey(); }
  x4= x4-48;
  lcd.setCursor(7,1);
  lcd.print(x4);
  xx= x3*10+x4;
  Serial.print(xx);
  delay(1000);
  lcd.clear();
    //eau (pompe)"y"
  lcd.setCursor(15,0 );                
  lcd.print("%");
  lcd.setCursor(0,0 );                
  lcd.print("Eau:");
  while(y2==0){y2=keypad.getKey(); }
  y2= y2-48;
  lcd.setCursor(6,0);
  lcd.print(y2);
  while(y1==0){y1=keypad.getKey(); }
  y1= y1-48;
  lcd.setCursor(7,0);
  lcd.print(y1);
  y= y2*10+y;
  Serial.print(y);
  delay(1000);
  lcd.clear();
}
void passw()
{ 

  alfa:
  int a=0,b=0,c=0,d=0,z=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter password:");
  while(a==0){a=keypad.getKey(); }
  a= a-48;
  lcd.setCursor(0,1);
  lcd.print("*");
  while(b==0){b=keypad.getKey(); }
  b= b-48;
  lcd.setCursor(1,1);
  lcd.print("*");
  while(c==0){c=keypad.getKey(); }
  c= c-48;
  lcd.setCursor(2,1);
  lcd.print("*");
  while(d==0){d=keypad.getKey(); }
  d= d-48;
  lcd.setCursor(3,1);
  lcd.print("*");
  z= a*1000+b*100+c*10+d;
  if(z==8579)
  {
    delay(300);
       lcd.clear();
  lcd.print("correcte");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   welcom to:");
   lcd.setCursor(0,1);
  lcd.print("  <SGH system>  ");
  delay(4000); 
  }
    if(z!=8579)
  {
       delay(300); 

  lcd.clear();
  lcd.print("incorrecte!");
  delay(2000);
  goto alfa; 
  }
  lcd.clear();
  
}