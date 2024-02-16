byte Houselight = 4;
byte Sonalert = 24;
byte Response1 = 2;
byte Response2= A1;
byte Light_1= 3;
byte Water = 53;
byte bulb28v = 8; 
byte Step_Right = 31;
byte Dir_Right =37;
int StepCount = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 pinMode(Houselight, OUTPUT);
 pinMode(Light_1, OUTPUT);
 pinMode(bulb28v, OUTPUT);
 pinMode(Water, OUTPUT);
 pinMode(Sonalert, OUTPUT);
 pinMode(Step_Right, OUTPUT);
 pinMode(Dir_Right, OUTPUT);
 pinMode(Response1,INPUT_PULLUP);
 pinMode(Response2,INPUT_PULLUP);
 
 digitalWrite (Light_1,LOW);
 digitalWrite (Houselight,LOW);
 digitalWrite (Water,LOW);
 digitalWrite (Sonalert,LOW); 
}
void loop() {
  // put your main code here, to run repeatedly: 
 if (Serial.available()>0){
   char Event=Serial.read();
    switch (Event){
    case 'A':
    digitalWrite (Houselight, HIGH);  
    break;
        
    case 'B':
    digitalWrite (Light_1, HIGH);
    break;
      
    case 'b':
    digitalWrite (Light_1, LOW);
    break;    
      
    case 'C':   
    digitalWrite (Light_1, HIGH);
    delay (500); 
    digitalWrite (Light_1, LOW);
    delay(500);       
    break;
         
    case 'R':
    for (StepCount = 0; StepCount < 80; StepCount++){
    digitalWrite(Step_Right,HIGH);
    delay(5);
    digitalWrite(Step_Right,LOW);
    delay(5);    
    }
    break;
         
    case 'T':
    digitalWrite (Sonalert, HIGH);
    delay(500); 
    digitalWrite(Sonalert, LOW);
    delay(500);
    break;
     
    case 'Z':
    digitalWrite (Sonalert, HIGH);
    break;
    case 'z':
    digitalWrite(Sonalert, LOW);
    break;
        
    case 'Q':
    digitalWrite (Water, HIGH);
    delay(500); 
    digitalWrite (Water, LOW);
    break;
     
        }
}
 Serial.println(String(digitalRead(Response1))+","+String(digitalRead(Response2)));
  delay (4);
}
