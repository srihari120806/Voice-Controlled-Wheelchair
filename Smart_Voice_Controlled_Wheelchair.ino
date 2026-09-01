/*
 Smart Voice-Controlled Wheelchair
 Arduino UNO + HC-05 + L298N + HC-SR04
 Safety features: emergency stop, obstacle detection,
 speed control, buzzer feedback and command timeout.
*/

const int ENA = 5, IN1 = 6, IN2 = 7, IN3 = 8, IN4 = 9, ENB = 10;
const int TRIG = 11, ECHO = 12;
const int BUZZER = 13;
const int EMERGENCY_STOP = 4;

int motorSpeed = 180;
unsigned long lastCommandTime = 0;
const unsigned long COMMAND_TIMEOUT = 3000;
const int SAFE_DISTANCE = 30;

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(TRIG, OUTPUT); pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(EMERGENCY_STOP, INPUT_PULLUP);

  stopMotors();
  beep(1);
}

void loop() {
  if (digitalRead(EMERGENCY_STOP) == LOW) {
    emergencyStop();
    return;
  }

  if (Serial.available()) {
    char command = Serial.read();
    lastCommandTime = millis();
    handleCommand(command);
  }

  if (millis() - lastCommandTime > COMMAND_TIMEOUT && lastCommandTime != 0) {
    stopMotors();
  }
}

void handleCommand(char c) {
  switch (toupper(c)) {
    case 'F':
      if (getDistance() > SAFE_DISTANCE) forward();
      else obstacleStop();
      break;
    case 'B': backward(); break;
    case 'L': left(); break;
    case 'R': right(); break;
    case 'S': stopMotors(); break;
    case '1': motorSpeed = 120; updateSpeed(); beep(1); break;
    case '2': motorSpeed = 180; updateSpeed(); beep(2); break;
    case '3': motorSpeed = 255; updateSpeed(); beep(3); break;
  }
}

long getDistance() {
  digitalWrite(TRIG, LOW); delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH, 30000);
  if (duration == 0) return 999;
  return duration * 0.034 / 2;
}

void updateSpeed() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}

void forward() {
  updateSpeed();
  digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
}

void backward() {
  updateSpeed();
  digitalWrite(IN1,LOW); digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW); digitalWrite(IN4,HIGH);
}

void left() {
  updateSpeed();
  digitalWrite(IN1,LOW); digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
}

void right() {
  updateSpeed();
  digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW); digitalWrite(IN4,HIGH);
}

void stopMotors() {
  digitalWrite(IN1,LOW); digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW); digitalWrite(IN4,LOW);
}

void emergencyStop() {
  stopMotors();
  tone(BUZZER, 1200, 300);
}

void obstacleStop() {
  stopMotors();
  tone(BUZZER, 900, 500);
}

void beep(int count) {
  for (int i=0; i<count; i++) {
    tone(BUZZER, 1500, 100);
    delay(180);
  }
}
