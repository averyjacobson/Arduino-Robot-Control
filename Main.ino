#include <Servo.h>

Servo TillServo; //servo for tiller
Servo SeedServo; //servo for seed release
int MotorLF = 11;
int MotorLR = 10;
int MotorRF = 13;
int MotorRR = 12;
int MotorToggle = 9;
bool servoForward = true;

void setup()                    // run once, when the sketch starts
{
 TillServo.attach(8);
 SeedServo.attach(7);
 Serial.begin(9600); 
 TillServo.write(90);
 SeedServo.write(97); //set seed servo to center
 pinMode(MotorLF, OUTPUT);
 pinMode(MotorLR, OUTPUT);
 pinMode(MotorRF, OUTPUT);
 pinMode(MotorRR, OUTPUT);
 pinMode(MotorToggle, OUTPUT);// set the baud rate to 9600, same should be of your Serial Monitor
}
int number = 0;

void loop() 
{
    
      switch ((char)Serial.read()) {
        case 'd':
        digitalWrite(MotorToggle, !digitalRead(MotorToggle)); //toggle or untoggle motor
        //2 motor backwards
        digitalWrite(MotorLF, HIGH);
        digitalWrite(MotorLR, LOW);
        digitalWrite(MotorRF, HIGH);
        digitalWrite(MotorRR, LOW);
        Serial.println("go down");
        break;
        case 'u':
        digitalWrite(MotorToggle, !digitalRead(MotorToggle)); //toggle or untoggle motor
        //2 motor up
        digitalWrite(MotorLF, LOW);
        digitalWrite(MotorLR, HIGH);
        digitalWrite(MotorRF, LOW);
        digitalWrite(MotorRR, HIGH);
        Serial.println("go up");
        break;
        case 'r':
        digitalWrite(MotorToggle, !digitalRead(MotorToggle)); //toggle or untoggle motor
        //left motor forward and right backward
        Serial.println("go right");
        digitalWrite(MotorLF, HIGH);
        digitalWrite(MotorLR, LOW);
        digitalWrite(MotorRF, LOW);
        digitalWrite(MotorRR, HIGH);
        break;
        case 'l':
        digitalWrite(MotorToggle, !digitalRead(MotorToggle)); //toggle or untoggle motor
        //right motor forward and left backward 
        Serial.println("go left");
        digitalWrite(MotorLF, LOW);
        digitalWrite(MotorLR, HIGH);
        digitalWrite(MotorRF, HIGH);
        digitalWrite(MotorRR, LOW);
        break;
        case 's':
        Serial.println("TillServo actuate");
        
        //check direction
        if (TillServo.read() == 90) {
          TillServo.write(TillServo.read() - 20);
        }
        else {
          TillServo.write(TillServo.read() + 20);
        }
        Serial.print("TillServo angle: ");
        Serial.println(TillServo.read());
        delay(150);
        break;
        case 'i':
        Serial.println("Hopper Servo R actuate");
        //check direction
   
        if (SeedServo.read() == 97) {
          SeedServo.write(SeedServo.read() - 20);
        }
        else {
          SeedServo.write(SeedServo.read() + 20);
        }
        delay(150);
        break;
        case 'x':
        Serial.println("Hopper Servo L actuate");
        //check direction
        if (SeedServo.read() == 97){
          SeedServo.write(SeedServo.read() + 20);
        }
        else {
          SeedServo.write(SeedServo.read() - 20);
        }
        delay(150);
        break;
      }
} 
