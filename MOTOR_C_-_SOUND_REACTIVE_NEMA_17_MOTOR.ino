/*
  Stepper Motor Demonstration 4
  Stepper-Demo4.ino
  Demonstrates NEMA 17 Bipolar Stepper with A4988 Driver
 
Sound Reactive Motor "MOTOR  C" for sound reactive drawing machine project 2022 based of the original project by Angela Bullock 

Code in collaboration with open source material provided by DroneBot Workshop 2018 

and 
Will Hardy 
Dom Hardy 
Frank F 
  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/
 

// Define Constants
 

// Connections to A4988
const int dirPin = 2;  // Direction
const int stepPin = 3; // Step

// Connections to A4988
#define dirPin 2  // Direction
#define stepPin 3 // Step
#define sensorPin A0


// need to connect information from A0 information that goes through the else if motions to the A6988 to activate the motions of dir and step pin in 2 + 3

float sensorValue = 0, filteredSignal = 0,
    filteredSignalValues[] = {4.2, 3.8, 3.4, 3.0, 2.2, 1.8, 1.4, 1.0};


// Defined new list of values to serve as motor thresholds
float motorSignalValues[] = {0.16, 0.14, 0.12, 0.10, 0.08 , 0.06, 0.04, 0.02, 0.0};

// Motor steps per rotation
const int STEPS_PER_REV = 210;
 

void setup() {
  

  // Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  

  Serial.begin (9600);

}
void loop() {

  sensorValue = (float) analogRead(sensorPin) * (5.0 / 1024.0);

  FilterSignal(sensorValue);

  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.println(filteredSignal);
  CompareSignalFiltered(filteredSignal);
}

void FilterSignal(float sensorSignal) {

  filteredSignal = (0.945 * filteredSignal) + (0.0549 * sensorSignal);
}

void CompareSignalFiltered(float filteredSignal) 

{ 

  if (filteredSignal > filteredSignalValues[0]) {
     // Set motor direction clockwise
    digitalWrite(dirPin,HIGH); 
    // Spin motor one rotation slowly
    Motor(motorSignalValues[0] );


            // Pause for one second
            delay(1);    

  } else if (filteredSignal <= filteredSignalValues[0] && filteredSignal > filteredSignalValues[1]) {
            // Set motor direction clockwise
            digitalWrite(dirPin,LOW); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[1] );
 
             // Pause for one second
            delay(1);
                       
            digitalWrite(dirPin,HIGH); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[1] );

             // Pause for one second
            delay(1);            

  } else if (filteredSignal <= filteredSignalValues[1] && filteredSignal > filteredSignalValues[2]) {
            // Set motor direction clockwise
            digitalWrite(dirPin,HIGH); 
            //  Spin motor one rotation slowly
            Motor(motorSignalValues[2] );

             // Pause for one second
            delay(1);
                        
            digitalWrite(dirPin,LOW); 
            //  Spin motor one rotation slowly
            Motor(motorSignalValues[2] );

            // Pause for one second
            delay(1);

  } else if (filteredSignal <= filteredSignalValues[2] && filteredSignal > filteredSignalValues[3]) {
            // Set motor direction clockwise
            digitalWrite(dirPin,LOW); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[3] );

             // Pause for one second
            delay(1);
                        
            digitalWrite(dirPin,HIGH); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[3] );

             // Pause for one second
            delay(1);
             
  } else if (filteredSignal <= filteredSignalValues[3] && filteredSignal > filteredSignalValues[4]) {
            // Set motor direction clockwise
            digitalWrite(dirPin,HIGH); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[4] );

             // Pause for one second
            delay(1);
                        
            digitalWrite(dirPin,LOW); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[4] );

            // Pause for one second
            delay(1);
             
  } else if (filteredSignal <= filteredSignalValues[4] && filteredSignal > filteredSignalValues[5]) {
            // Set motor direction clockwise
            digitalWrite(dirPin,LOW); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[5] );

             // Pause for one second
            delay(1);
                        
            digitalWrite(dirPin,HIGH); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[5] );

            // Pause for one second
            delay(1);            

  } else if (filteredSignal <= filteredSignalValues[5] && filteredSignal > filteredSignalValues[6]) {
            // Set motor direction clockwise
            digitalWrite(dirPin,HIGH); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[6] );

             // Pause for one second
            delay(1);
                        
            digitalWrite(dirPin,LOW); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[6] );
            
            // Pause for one second
            delay(1);
           
  } else if (filteredSignal <= filteredSignalValues[6] && filteredSignal > filteredSignalValues[7]) {
            // Set motor direction clockwise
            digitalWrite(dirPin,LOW); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[7] );

             // Pause for one second
            delay(1);
                        
            digitalWrite(dirPin,HIGH); 
            // Spin motor one rotation slowly
            Motor(motorSignalValues[7] );

            // Pause for one second
            delay(1);
             
  } else {
           // Set motor direction clockwise
            digitalWrite(dirPin,HIGH); 
           // Spin motor one rotation slowly
           Motor(motorSignalValues[8] );


             // Pause for one second 
            delay(1);  
            digitalWrite(dirPin,LOW); 
           // Spin motor one rotation slowly
           Motor(motorSignalValues[8] );

            // Pause for one second
            delay(1);           
  
}
  }

  // list = motorSignalValues
  // word ‘float’ is not necessarily needed ??? ---- NEEDED - WILL CORRECTION
void Motor( float Motor_sig) {
  for(int x = 0; x < (STEPS_PER_REV * Motor_sig); x++) {
               digitalWrite(stepPin,HIGH); 
               delayMicroseconds(500); 
               digitalWrite(stepPin,LOW); 
               delayMicroseconds(500); 
           }
         
}
