const int buffer_size = 20;
char buf[buffer_size];


void setup() {
  Serial.begin(9600);

  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);

  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

}
void loop() {
  if (Serial.available() > 0) {
    int angle = Serial.readBytes(buf, buffer_size);
    Serial.print("You sent me: ");
    Serial.println(angle);
    analogWrite(11,(int) buf[0] - '0');
    analogWrite(10,(int) buf[1] - '0');



    //    switch (angle) {
    //      case 1:
    //        analogWrite(11, angle[0]);
    //        analogWrite(10, angle[1]);
    //
    //        break;
    //      case 2:
    //
    //        analogWrite(11, angle[0]);
    //        analogWrite(10, angle[1]);
    //
    //        break;
    //      case 3:
    //
    //        analogWrite(11, angle[0]);
    //        analogWrite(10, angle[1]);
    //
    //        break;
    //      default:
    //        break;
    //    }
  }
}
