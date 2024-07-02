// constants won't change:
int32_t f = 300;   //stepper motor rotation speed
uint32_t t = 1000000/f/2;    

bool can_flag;


int label_sensor = 12;       //D6 // Label sensor
int can_presence_sensor = 0; //D3 // Can presence sensor.
int step_motor_pulse = 4;    //D2 - PWM for step controller stopping

void setup() {
  pinMode(label_sensor, INPUT_PULLUP); 
  pinMode(can_presence_sensor, INPUT_PULLUP);
   
  pinMode(step_motor_pulse, OUTPUT); 
  digitalWrite(step_motor_pulse, LOW);
}

void loop() {

if (digitalRead(label_sensor) == HIGH) {
  Serial.println("between 2 labels");
}
    else{
      digitalWrite(step_motor_pulse, 1);
        delayMicroseconds(t);     
        digitalWrite(step_motor_pulse, 0);
        delayMicroseconds(t);     
      }


if (digitalRead(can_presence_sensor)==false && can_flag==false){
  
 
  for(int i=0; i<10; i++){           
           digitalWrite(step_motor_pulse, 1 );      
           delayMicroseconds(t);           
           digitalWrite(step_motor_pulse, 0 );  
           delayMicroseconds(t);         
       } 
          can_flag = true;                    
}


if (digitalRead(can_presence_sensor)==true && can_flag==true){
  can_flag = false;
       }                        
  
}




  
