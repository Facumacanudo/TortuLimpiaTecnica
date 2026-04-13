#include <SoftwareSerial.h>
//Bluetooth

SoftwareSerial bt(10, 11);
//Puente H
#define ena 6
#define in1 8
#define in2 9
#define in3 3
#define in4 4
#define enb 5


//Sensores de linea
#define sen_der 2
#define sen_izq A2
#define sen_atr A4

void setup() {
  bt.begin(38400);
  pinMode(OUTPUT, ena);
  pinMode(OUTPUT, in1);
  pinMode(OUTPUT, in2);
  pinMode(OUTPUT, in3);
  pinMode(OUTPUT, in4);
  pinMode(OUTPUT, enb);

  pinMode(INPUT, sen_der);
  pinMode(INPUT, sen_izq);
  pinMode(INPUT, sen_atr);
  Serial.begin(9600);
}
void direccion(int in1p, int in2p, int in3p, int in4p) {
  digitalWrite(in1, in1p);
  digitalWrite(in2, in2p);

  digitalWrite(in3, in3p);
  digitalWrite(in4, in4p);
}
void adelante(int m1, int m2) {
  analogWrite(ena, m1);
  direccion(1, 0, 0, 1);
  analogWrite(enb, m2);
}
void derecha(int m1, int m2) {
  analogWrite(ena, m1);
  direccion(0, 1, 0, 1);
  analogWrite(enb, m2);
}
void izquierda(int m1, int m2) {
  analogWrite(ena, m1);
  direccion(1, 0, 1, 0);
  analogWrite(enb, m2);
}
void atras(int m1, int m2) {
  analogWrite(enb, m1);
  direccion(0, 1, 1, 0);
  analogWrite(ena, m2);
}
void stop() {
  analogWrite(enb, 0);
  analogWrite(ena, 0);
}
void loop() {
  char cache = bt.read();
  if (cache == 'w') {
    adelante(255, 255);
    Serial.println("adelante");
  }
  if (cache == 's') {
    atras(255, 255);
  }
  if (cache == 'd') {
    derecha(255, 255);
  }
  if (cache == 'a') {
    izquierda(255, 255);
  }
  if (cache == 'f') {
    stop();
  }
}