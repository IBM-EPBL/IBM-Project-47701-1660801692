// C++ code
//

void setup()
{
  Serial.begin(9600);
  pinMode(4,INPUT); // for PIR
  pinMode(13, OUTPUT);  // for peizo
}

void loop()
{
  double data = analogRead(A1);
  double n = data/1024;
  
  double volt = n * 5; //because connected to 5V
  double off = volt - 0.5;
  double temperature = off * 100;
  
  if(temperature > 60){
    Serial.print("--------------TMP----------------\n");
    Serial.print("Temperature is above 60C: ");
  	Serial.print(temperature);
  	Serial.println("C");
    
    
    tone(13,1800,100);  //freq 1000 Hz,delay 100 ms
    delay(1000);
    tone(13,1800,1000); //freq 1000 Hz,delay 1 sec
    delay(100);
   
  }
  else{
    Serial.print("--------------TMP----------------\n");
    Serial.print("Temperature is below 60C: ");
  	Serial.print(temperature);
  	Serial.println("C");
    Serial.print("\n\n");
    
    noTone(13);
    
  }
    
  
  
  
  
  
  // for PIR
  int motion = digitalRead(4);
  Serial.print("--------------PIR----------------\n");
  Serial.print("Position is: ");
  Serial.println(motion);
  
  
  if(motion == 1){
    Serial.println("Motion Detected");
    // For peizo
    tone(13,1000,100);  //freq 1000 Hz,delay 100 ms
	delay(1000);
	tone(13,1000,1000); //freq 1000 Hz,delay 1 sec
	delay(100);
    
  }
  else{
    Serial.println("No Motion");
    noTone(13);
  }
}