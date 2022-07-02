#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


Servo servoA; //Hand (open/close)
Servo servoB; // forward Backward 
Servo servoC; //up down
Servo servoD; // Rotate (left-right)

int JoysiticA = A0; 
int JoysiticB = A1; 
int JoysiticC = A2; 
int JoysiticD = A3; 

// The kepad
const byte ROWS = 4; 
const byte COLS = 4;
char keys[ROWS][COLS] = {
    
    {'1','2','3','A'}, 
    {'4','5','6','B'}, 
    {'7','8','9','C'},
    {'*','0','#','D'}};

byte rowPins[ROWS] = { 6,7,8,9 };
byte colPins[COLS] = { 10,11,12,13 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 
String command;


char leter ='A'; // (Leter) servo to perform the command 
int angle = 0;  // (angle) Initial command

void setup()
{
// initialize the lcd  
lcd.init();                      
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("Enter command"); 
// Pins for the servos
servoA.attach(2);
servoB.attach(3);
servoC.attach(4);
servoD.attach(5);

//Starting point 
servoA.write(80);
servoB.write(30);
servoC.write(120);
servoD.write(90);




}

void loop(){

 int s =5; // How fast you want the arm to go ???

JoysiticA= analogRead(A0);
JoysiticB= analogRead(A1);
JoysiticC= analogRead(A2);
JoysiticD= analogRead(A3);
// Joysitics

 // the servos have  arange of motion defined ServoA 120 to 50 ServoB 110 to 10  ServoC 110

 
  if (JoysiticA > 600) {
     int i = servoA.read();
     if (i<120) {
      i=i+1;
          servoA.write(i);
          lcd.init();
          lcd.setCursor(0,0);
          lcd.print(String("Servo A")  + i); 
          delay(s); };                            
    
  }; 
    if (JoysiticA < 400) {
     int i = servoA.read();
     if (i>50) {
      i=i-1;
          servoA.write(i);
          lcd.init();
          lcd.setCursor(0,0);
          lcd.print(String("Servo A")  + i); 
          delay(s); };                            
    
  }; 
  
  if (JoysiticB < 400) {
     int i = servoB.read();
     if (i<110) {
      i=i+1;
          servoB.write(i);
          delay(s); };                            
    
  }; 
    if (JoysiticB > 600) {
     int i = servoB.read();
     if (i>10) {
      i=i-1;
          servoB.write(i);
          delay(s); };                            
    
  }; 
    if (JoysiticC < 400) {
     int i = servoC.read();
     if (i<180) {
      i=i+1;
          servoC.write(i);
          delay(s); };                            
    
  }; 
    if (JoysiticC > 600) {
     int i = servoC.read();
     if (i>50) {
      i=i-1;
          servoC.write(i);
          delay(s); };                            
    
  };
    if (JoysiticD > 600) {
     int i = servoD.read();
     if (i<180) {
      i=i+1;
          servoD.write(i);
          delay(s+10); };                            
    
  }; 
    if (JoysiticD <400) {
     int i = servoD.read();
     if (i>1) {
      i=i-1;
          servoD.write(i);
          delay(s+10); };                            
    
  };
  






char key = keypad.getKey();


  if (key){
            lcd.init();
            lcd.setCursor(0,0);
            lcd.print(String("Servo ")  + String(leter));
            lcd.setCursor(0,1); 
            lcd.print(String("Command  ")+String(command + key));

// * on the keyapd will reset the command
              if(key == '*') {
                      command = ""; 
                      lcd.init();
                      lcd.setCursor(0,0);
                      lcd.print(String("Servo ")  + String(leter)); 
                      lcd.setCursor(0,1); 
                      lcd.print("Command  ");
                      } 
//# on the keypad will execute the command on the chosen servo defined by (leter)                     
              else if(key == '#') 
                    {
                        
                                        lcd.init();                      // initialize the lcd
                                        lcd.setCursor(0,0);
                                        lcd.print(String("Servo ")  + String(leter)); // show on the LCD the servo that is chosen
                                        lcd.setCursor(0,1);
                                        lcd.print(String("Execute ")+String(command));  // show on the LCD the servo the comand is performing
                                        int i = command.toInt(); // capture on (i) the integer of the command (only numbers)
          
                             // For SERVO A
                              if(leter == 'A') {
                                                angle =servoA.read();
                                                if ( i >= angle) {
                                                              for (angle = angle; angle <= i; angle=angle +1)
                                                               {servoA.write(angle);                             
                                                               delay(10);                                                                              
                                                                }
                                                                }
                                                else 
                                                              { for (angle = angle; angle >= i; angle=angle- 1)
                                                               {servoA.write(angle);
                                                               delay(10);                                                                                                                                                     
                                                                }              
                                                                }
                                                                
                                           }
                               //For  SERVO A
                              if(leter == 'B') {
                                                angle =servoB.read();
                                                if ( i >= angle) {
                                                              for (angle = angle; angle <= i; angle=angle +1)
                                                               {servoB.write(angle);
                                                               delay(10);                                                                              
                                                                }
                                                                }
                                                else 
                                                              { for (angle = angle; angle >= i; angle=angle- 1)
                                                               {servoB.write(angle);
                                                               delay(10);                                                                                                                                                    
                                                                }              
                                                                }                                                                
                                           }
                             
                               // For  SERVO C
                              if(leter == 'C') {
                                                angle =servoA.read();
                                                if ( i >= angle) {
                                                              for (angle = angle; angle <= i; angle=angle +1)
                                                               {servoC.write(angle);
                                                               delay(10);
                                                                              
                                                                }
                                                                }
                                                else 
                                                              { for (angle = angle; angle >= i; angle=angle- 1)
                                                               {servoC.write(angle);
                                                                delay(10);                                                                                                                                               
                                                                }              
                                                                }
                                                                
                                           }
                               // For  SERVO D
                              if(leter == 'D'){
                                                angle =servoA.read();
                                                if ( i >= angle) {
                                                              for (angle = angle; angle <= i; angle=angle +1)
                                                               {servoD.write(angle);
                                                               delay(20);
                                                                              
                                                                }
                                                                }
                                                else 
                                                              { for (angle = angle; angle >= i; angle=angle- 1)
                                                               {servoD.write(angle);
                                                                delay(20);                                                                                                                                                       
                                                                }                                                                              }
                                                                
                                           }                                               
                              lcd.init(); 
                              lcd.setCursor(0,0);
                              lcd.print(String("Servo ")  + String(leter)); //write on the screen the servo chosen
                              command = "";// empty command 
                              }
              // Chosing the servo        
              else if(key == 'A' or key == 'B' or key == 'C' or key == 'D') 
                               {
                                  leter = key;
                                  lcd.init(); 
                                  lcd.setCursor(0,0);
                                  lcd.print(String("Servo ")  + String(leter));//print the name of the servo chosen  
                               if(leter == 'A') {
                                                
                                                lcd.println(servoA.read());    //print the value from the servo chosen           
                                                }
                               //  SERVO A
                              if(leter == 'B') {
                                                lcd.println(servoB.read());    //print the value from the servo chosen  
                                               }
                             
                               //  SERVO C
                              if(leter == 'C') {                                       
                                                lcd.println(servoC.read());   //print the value from the servo chosen
                                                }
                               //  SERVO D
                              if(leter == 'D') {
                                                lcd.println(servoD.read());   //print the value of the servo chosen
                                               }
                                  lcd.setCursor(0,1); 
                                  lcd.print(String("Command  ")+String(command)); //print the value of the command                 
                                  }

             
               else {
                command += key; //Add a digit to the command  
               
              }
  }}
