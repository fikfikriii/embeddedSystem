//Simple sketch to access the internal hall effect detector on the esp32.
//values can be quite low. 
//Brian Degger / @sctv  
int val = 0;
const int ledPin1 = 22;
const int ledPin2 = 23;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = hallRead();
  // print the results to the serial monitor:
  //Serial.print("sensor = ");
  Serial.println(val);//to graph 
  delay(200);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  if (val < 10){
    digitalWrite(ledPin1, HIGH);
  }
  else if(val > 90){
    digitalWrite(ledPin2, HIGH);
  }
}
