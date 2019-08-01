int pinA=3; //Connected to CLK on KY-040
int pinB=4; // Connected to DT on KY-040
int encoderPosCount = 0;
int pinALast=0;
int aVal=0;
boolean bCW=0;

void setup() {
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  /* Read Pin A
    Whatever state it's in will reflect the last position
  */
  pinALast = digitalRead(pinA);
             Serial.begin(9600);
}
void loop() {
  aVal = digitalRead(pinA);
  if (aVal != pinALast) { // Means the knob is rotating
    // if the knob is rotating, we need to determine direction
    // We do that by reading pin B.
    if (digitalRead(pinB) != aVal) { // Means pin A Changed first ­ We're Rotating Clockwise
      encoderPosCount ++;
      bCW = true;
    } else {// Otherwise B changed first and we're moving CCW
      bCW = false;
            encoderPosCount--;
    }
    Serial.print ("Rotated: ");
    if (bCW) {
      Serial.println ("clockwise");
    } else {
      Serial.println("counterclockwise");
    }
    Serial.print("Encoder Position: ");
    Serial.println(encoderPosCount);
  }
  pinALast = aVal;
}
