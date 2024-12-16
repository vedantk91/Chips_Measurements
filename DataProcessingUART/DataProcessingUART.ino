#define SL_PIN 2       
#define OUTFIN_PIN 5   
#define ANALOG_PIN A0
#define BIT_COUNT 8    
#define READ_FREQ 100000  
#define READ_DELAY (1000000 / READ_FREQ) 

volatile bool resetData = false; 
volatile uint8_t data = 0;       
uint8_t previousData = 0;        
uint8_t nextbit = 0;

void setup() {

  pinMode(SL_PIN, INPUT);        
  pinMode(OUTFIN_PIN, INPUT);    
  Serial.begin(9600);        

  for (int pin = 6; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
  }
  
  attachInterrupt(digitalPinToInterrupt(SL_PIN), resetDataISR, RISING);


}

void loop() {

  if (resetData) {
    resetData = false; 
    data = 0;          
  }

  if (digitalRead(SL_PIN) == LOW) {
    uint8_t tempData = 0;



    for (int i = 0; i < BIT_COUNT; i++) {
      if(analogRead(ANALOG_PIN) > 185){
      nextbit = 1;
      }
      else{
      nextbit = 0;
      }
      //Serial.println(analogRead(ANALOG_PIN));
      Serial.println(nextbit);
      tempData |= nextbit; 
      if (i < BIT_COUNT - 1) {
        tempData <<= 1;       
      }
      delayMicroseconds(READ_DELAY); 
    }

    uint8_t temp = tempData; 
    for (int pin = 6; pin <= 13; pin++) {
      digitalWrite(pin, (temp & 1));  
      temp >>= 1;                    
    }

    data = tempData;

    //Serial.println(data, DEC);
}

}

void resetDataISR() {
  resetData = true;
}
