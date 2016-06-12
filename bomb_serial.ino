

//initialize light colors pins
int red = 9;
int green = 8;
//initialize the deactivation/detonation wires
int inDead = 6;
int inGood = 7;



void setup() {
//beging the serial monitor (instead of the LCD)
  Serial.begin(9600);
  
  
  //set the  pins modes
    pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(inDead, INPUT);
  pinMode(inGood, INPUT);
  
  
  digitalWrite(red, HIGH);
  
        
//two hour loop
     for(long i=7200; i>=0 && digitalRead(inDead)!=0 && digitalRead(inGood)!=0;i--){
    //print out the time
      Serial.println(i); 
      //delay 1 second 
      delay(1000);
     }
     
     //when loop breaks
     if(digitalRead(inGood)==0){
       //deacticvation wire was disconnected
      Serial.print("Bomb deactivated."); 
      //turn on green light
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      //game won
     }
     else{
       //detonation wire was disconnected
      Serial.print("Boom!"); 
      //game over
     }
}

void loop() {
  //nothing to loop through
}
    
  


