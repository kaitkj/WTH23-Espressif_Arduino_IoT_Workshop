/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-light-sensor
 *
 * Modified for SUTD WTH23 IoT Workshop
 * 
 */

//GPIO for LDR (make sure to use GPIO with ADC support)
#define LIGHT_SENSOR_PIN 4

//GPIO for push button
static int gpio_0 = 0;
static int gpio_switch = 16;

/* Variable for reading pin status*/
bool switch_state = true;

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  pinMode(gpio_0, INPUT_PULLUP);
  pinMode(gpio_switch, OUTPUT);
  digitalWrite(gpio_switch, true);
}

void loop() {
  // reads the input on analog pin (value between 0 and 4095)
  int analogValue = analogRead(LIGHT_SENSOR_PIN);

  Serial.print("Analog Value = ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 40) {
    Serial.println(" => Dark");
  } else if (analogValue < 800) {
    Serial.println(" => Dim");
  } else if (analogValue < 2000) {
    Serial.println(" => Light");
  } else if (analogValue < 3200) {
    Serial.println(" => Bright");
  } else {
    Serial.println(" => Very bright");
  }
  
  if (digitalRead(gpio_0) == LOW) {  // Push button pressed
    delay(100);
    switch_state = !switch_state;
    Serial.printf("Toggle State to %s.\n", switch_state ? "true" : "false");

    if(switch_state == false){      // ON OFF LED according to switch state
      digitalWrite(gpio_switch, LOW);
      }
    else digitalWrite(gpio_switch, HIGH);
  }
  delay(500);
}
