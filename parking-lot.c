#include <LiquidCrystal.h>
#include <Servo.h>
#define N 10
#define BarLow  200       
#define BarUp  90
const int IN = 8; //Pushbutton in pin 8 
const int OUT = 9; //Pushbutton in pin 9

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 6, 5, 4, 2);
int cars = 0;
int avail = 0;
int full = 0;
int buttonIN = 0; // variable for reading the pushbutton status
int buttonOUT = 0;
Servo myservo;

void setup() {
  myservo.attach(7); // attaches the servo on pin 7 to the servo object
  pinMode(IN,INPUT);
  pinMode(OUT,INPUT);
  myservo.write(BarLow);
  lcd.begin(16, 2);
  Serial.begin (9600);
}

void loop() {
  buttonIN = digitalRead(IN);
  buttonOUT = digitalRead(OUT);
 
  Serial.println(buttonIN);
  Serial.println(buttonOUT);
  
  
  
	if(buttonIN == HIGH )
	{  
		if(full < N)
		{	
 		               
			Serial.println("Cars:");
			cars = cars + 1;
			Serial.println(cars);
			Serial.println("Available:");
			avail = N - cars;
			Serial.println(avail);
			Serial.println("Full:");
			full = full + 1;
			Serial.println(full);
			myservo.write(BarUp);
			delay(2000);
			myservo.write(BarLow);
			
			lcd.clear();
			lcd.setCursor(0,0);
			lcd.print("Cars:");
			lcd.setCursor(5,0);
			lcd.print(cars);
			lcd.setCursor(0,1);
			lcd.print("Available:");
			lcd.setCursor(10,1);
			lcd.print(avail);
			lcd.setCursor(9,1);
			//lcd.print("Full:");
			//lcd.setCursor(14,1);
			//lcd.print(full);
			delay(500);
        
		}
    
		else
		{
			Serial.println("The parking is full !!");
			lcd.clear();
			lcd.setCursor(0,0);
			lcd.print("The parking is\n");
			lcd.setCursor(0,1);
			lcd.print("full !!");
		}
	
	}
	else if(buttonOUT == HIGH)
	{
		if(cars > 0)
        { 
		  Serial.println("Cars:");
		  cars = cars - 1;
		  Serial.println(cars);
		  Serial.println("Available:");
		  avail = avail + 1;
		  Serial.println(avail);
		  Serial.println("Full");
		  full = full - 1;
		  Serial.println(full);
		  myservo.write(BarUp);
		  delay(2000);
		  myservo.write(BarLow);
		   
		  lcd.clear();
		  lcd.setCursor(0,0);
		  lcd.print("Cars:");
		  lcd.setCursor(5,0);
		  lcd.print(cars);
		  lcd.setCursor(0,1);
		  lcd.print("Available:");
		  lcd.setCursor(10,1);
		  lcd.print(avail);
		  lcd.setCursor(9,1);
		  //lcd.print("Full:");
		  //lcd.setCursor(14,1);
		  //lcd.print(full);
		  delay(500);
        }
	}
}	