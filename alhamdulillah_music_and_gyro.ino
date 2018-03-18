const int AMAX = 200;

//dari Buletooth audio sambung ke pin A0 arduino
const int analogInPin = A0;
const int pinSTATUS = 12;

char a[AMAX];
int sensorValue = 0;
int outputValue = 0;
int xx,C=0;
float A,B;
char c = ' ';
const char RUN = '>';
const char STOP = 'X';


void setup() {

  Serial.begin(9600);  
  pinMode(pinSTATUS, OUTPUT);
//  digitalWrite(pinGyro, LOW);
}

void loop() {
  Serial.print("Suara: ");
  Serial.println(outputValue);

  C = 0;
  for(xx=0;xx<=AMAX-1;xx++){
  sensorValue = analogRead(analogInPin);
  C +=  sensorValue;    
  }
  
  Serial.print("C:");
  Serial.println(C);
  if( C > 50 )// range  nois for signal
  {
    digitalWrite(pinSTATUS,HIGH);      
  } else {
    digitalWrite(pinSTATUS,LOW);       
  }
  
}

