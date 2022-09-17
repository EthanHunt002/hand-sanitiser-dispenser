
// Define Trig and Echo pin:
#define trigPin 3  //transmitter                                                                                                                                                                            11111111111111111111111111111111111111111111111111  
 #define echoPin 2 //reciever

// Define variables:
long duration;
int distance;

void setup() {
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4,OUTPUT);

  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  digitalWrite(4, LOW);

  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance = duration * 0.034 / 2;

  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  //Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(10);
  if(distance <=12)
  { pump(1);delay(300);}
else
  {  analogWrite(4, LOW);
  }

} 
void pump(int a)// function for turning on and off the pump
{ while(a==1)
  { analogWrite(4,1024);Serial.println("pump on");
  delay(500);
  analogWrite(4,0);Serial.println("pump off");
  delay(1000);break;}
}
