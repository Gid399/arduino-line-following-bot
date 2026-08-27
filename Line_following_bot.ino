// ================= SENSOR PINS =================

// Define the pins connected to the three IR sensors.
int sensor_1 = A0; // Left sensor
int sensor_2 = A1; // Middle sensor
int sensor_3 = A2; // Right sensor

// ================= MOTOR CONTROL PINS =================

// ENA and ENB are the enable pins of the motor driver.
// They are used with PWM to control motor speed.
int ENA = 10;
int ENB = 9;

// Motor 1 direction control pins
int motor1_forward = 6;
int motor1_reverse = 5;

// Motor 2 direction control pins
int motor2_forward = 4;
int motor2_reverse = 3;

// ================= MOTOR SPEEDS =================

// Speed used when the robot is moving straight.
short int straight_speed = 150;

// Speed used for the motor on the inside of a turn.
// A lower speed makes the robot turn.
short int turn_speed = 80;


// Variables used to store the readings from the three sensors.
int value_1, value_2, value_3;

// The threshold determines whether a sensor has detected the line.
// Sensor readings above 500 are treated as detecting the line.
int threshold = 500;

void setup() {

  // Set the three IR sensor pins as inputs
  // because the Arduino needs to receive readings from them.
  pinMode(sensor_1, INPUT);
  pinMode(sensor_2, INPUT);
  pinMode(sensor_3, INPUT);


  // Set the motor enable pins as outputs.
  // These pins control the speed of the motors using PWM.
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);


  // Set the motor direction pins as outputs.
  pinMode(motor1_forward, OUTPUT);
  pinMode(motor1_reverse, OUTPUT);
  pinMode(motor2_forward, OUTPUT);
  pinMode(motor2_reverse, OUTPUT);


  // Start serial communication so that sensor values
  // and robot movement can be displayed in the Serial Monitor.
  Serial.begin(9600);

}

void loop() {

  // Read the analog value from each IR sensor.
  value_1 = analogRead(sensor_1);
  value_2 = analogRead(sensor_2);
  value_3 = analogRead(sensor_3);

  // ================= FORWARD =================

  // If the center sensor detects the line,
  // the robot moves forward.
  if(value_2 > threshold){

    Serial.println("FOWARD");

    // Call the forward function.
    foward();

    // Very short delay before taking another reading.
    delay(1);
  }

  // ================= RIGHT TURN =================

  // If the right sensor detects the line,
  // the robot turns to the right.
  else if(value_3 > threshold){

    Serial.println("RIGHT");

    // Call the right-turn function.
    right();

    delay(1);
  }


  // ================= LEFT TURN =================

  // If the left sensor detects the line,
  // the robot turns to the left.
  else if(value_1 > threshold){

    Serial.println("LEFT");

    // Call the left-turn function.
    left();

    delay(1);
  }

  // ================= STOP =================

  // If none of the sensors detect the line,
  // stop the robot.
  else{

    Serial.println("STOP");

    // Call the stop function.
    stopMotor();

    delay(1);
  }

}

// ==========================================================
//                     FORWARD FUNCTION
// ==========================================================

// Makes both motors rotate so that the robot moves forward.
void foward(){

  // Set both motors to the normal straight-line speed.
  analogWrite(ENA, straight_speed);
  analogWrite(ENB, straight_speed);

  // Set the motor direction.
  digitalWrite(motor1_forward, HIGH);
  digitalWrite(motor1_reverse, HIGH);

  digitalWrite(motor2_forward, LOW);
  digitalWrite(motor2_reverse, LOW);

}

// ==========================================================
//                       LEFT FUNCTION
// ==========================================================

// Makes the robot turn left by using different speeds
// for the two motors.
void left(){

  // Motor 1 runs at the slower turning speed.
  analogWrite(ENA, turn_speed);

  // Motor 2 continues at the normal speed.
  analogWrite(ENB, straight_speed);

  // Set the motor direction.
  digitalWrite(motor1_forward, HIGH);
  digitalWrite(motor1_reverse, HIGH);

  digitalWrite(motor2_forward, LOW);
  digitalWrite(motor2_reverse, LOW);

}

// ==========================================================
//                      RIGHT FUNCTION
// ==========================================================

// Makes the robot turn right by slowing down one motor.
void right(){

  // Motor 1 continues at the normal speed.
  analogWrite(ENA, straight_speed);

  // Motor 2 runs at the slower turning speed.
  analogWrite(ENB, turn_speed);

  // Set the motor direction.
  digitalWrite(motor1_forward, HIGH);
  digitalWrite(motor1_reverse, HIGH);

  digitalWrite(motor2_forward, LOW);
  digitalWrite(motor2_reverse, LOW);

}

// ==========================================================
//                    STOP MOTOR FUNCTION
// ==========================================================

// Stops both motors by turning off all motor direction signals.
void stopMotor(){

  // Stop Motor 1.
  digitalWrite(motor1_forward, LOW);
  digitalWrite(motor1_reverse, LOW);

  // Stop Motor 2.
  digitalWrite(motor2_forward, LOW);
  digitalWrite(motor2_reverse, LOW);

}