#include <Servo.h>

Servo h_servo;  // create servo object to control a servo
Servo v_servo;
int h_min=50;
int h_max=180;
int v_min=2;
int v_max=132;
int h_pos=0;
int v_pos=0;
//serial value
const byte numChars = 32;
char recvChars[numChars];
boolean newData = false;
int x_value = 0;
int y_value = 0;

void setup() {
  Serial.begin(9600);
  h_servo.attach(2);
  v_servo.attach(3);
  Serial.println("calibrating horizontal servo...");
  h_servo.write(h_min); //left
  delay(500);
  h_servo.write(h_max);  //right
  delay(500);
  h_servo.write((h_min+h_max)/2);  //center
  delay(500);
  Serial.println("calibrating vertical servo...");
  v_servo.write(v_min); //up
  delay(500);
  v_servo.write(v_max);  //down
  delay(500);
  v_servo.write((v_min+v_max)/2);  //center
  delay(500);
  v_pos=(v_min+v_max)/2;
}

void loop() {
  recvWithStartEndMarker();
  getXYServoCoord();
  Serial.println(v_pos);
  Serial.println(h_pos);
  v_servo.write(v_pos);
  h_servo.write(h_pos);
  delay(2000);
}

void recvWithStartEndMarker() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
       rc = Serial.read();
       if (recvInProgress == true) {    
         if (rc != endMarker) {
            recvChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
         }
         else {
            recvChars[ndx] = '\0';
            recvInProgress = false;
            ndx = 0;
            newData = true;
         }
      }
      else if (rc == startMarker) {
         recvInProgress = true;
      }
    }
}

void getXYServoCoord() {
  if (newData == true) {
        char x_val[4];
        char y_val[4];
        int temp_h_pos = 0;
        int temp_v_pos = 0;
        if (recvChars[0] == 'x')
        { 
          x_val[0] = recvChars[1];
          x_val[1] = recvChars[2];
          x_val[2] = recvChars[3];
          x_val[3] = '\0';
        }
        if (recvChars[4] =='y')
        {
          y_val[0] = recvChars[5];
          y_val[1] = recvChars[6];
          y_val[2] = recvChars[7];
          y_val[3] = '\0';
        }
        Serial.println(recvChars);
        Serial.println(atoi(x_val));
        Serial.println(atoi(y_val));
        temp_h_pos = map(atoi(x_val), 0, 500, h_min, h_max);
        temp_v_pos = map(atoi(y_val), 0, 500, v_min, v_max);
        if (h_pos!=temp_h_pos && temp_h_pos>0)
        {
          h_pos = temp_h_pos;
        }
        if (v_pos!=temp_v_pos && temp_v_pos>0)
        {
          v_pos = temp_v_pos;
        }
        newData = false;
  }
}
