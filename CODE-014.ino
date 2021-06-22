//https://www.youtube.com/c/VTMVlogVoThongMinh
#include <Servo.h>
#define low 6
#define high 5
#define autoo 4
#define intt 7
#define mix 2
#define wash 3
#define relay 9
Servo myservo;
int aa = 0;
int a = 0;
int timer1; // tốc độ servo
int timer2; // tốc độ servo
int gocquay = 90; // góc quay
//................................................
void setup() {
  Serial.begin(9600);
  myservo.attach(8);
  pinMode(low, INPUT_PULLUP);
  pinMode(high, INPUT_PULLUP);
  pinMode(autoo, INPUT_PULLUP);
  pinMode(intt, INPUT_PULLUP);
  pinMode(mix, INPUT_PULLUP);
  pinMode(wash, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  myservo.write(0);
  digitalWrite(relay, HIGH);
}
//................................................
void loop() {
  while (digitalRead(low) == 0) {
    timer1 = 1000; timer2 = 1000;
    runn();
  }
  while (digitalRead(high) == 0) {
    timer1 = 200; timer2 = 200;
    runn();
  }
  if (digitalRead(mix) == 0) {
    timer1 = 500; timer2 = 500;
    runn();
  }
  if (digitalRead(wash) == 0) {
    timer1 = 500; timer2 = 500;
    digitalWrite(relay, LOW);
    runn();
    digitalWrite(relay, HIGH);
  }
  while (digitalRead(intt) == 0) {
    int a = analogRead(A0); timer1 = 300;
    timer2 = map(a, 0, 1023, 300, 5000);
    runn();
  }
  while (digitalRead(autoo) == 0) {
    int a = analogRead(A1); timer1 = 300;
    Serial.println(a);
    if ((a > 200) && (a < 500)) {
      timer2 = 300;
      runn();
    }
    else if ((a > 500) && (a < 900)) {
      timer2 = 1500;
      runn();
    }
  }
}
//................................................
void runn() {
  myservo.write(gocquay);
  delay(timer1);
  myservo.write(0);
  delay(timer2);
}
