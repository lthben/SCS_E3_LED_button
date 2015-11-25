/*  Author: Benjamin Low (benjamin.low@digimagic.com.sg)
 *  Description: Operation of a LED arcade button
 *  Last updated: 25 Nov 2015
 */


#define switch_read_pin 2 //connected to button switch
#define power_control_pin 3 //connected to relay. Relay is active-low.

boolean button_state;

void setup() {
  pinMode(switch_read_pin, INPUT);
  pinMode(power_control_pin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(power_control_pin, HIGH); //turn off
}

void loop() {

        if (Serial.available()) {
                char my_command = Serial.read();

                if (my_command == '1') {
                        digitalWrite(power_control_pin, LOW);
                }
                else if (my_command == '2') {
                        digitalWrite(power_control_pin, HIGH);
                }
                
        }
        
  if (digitalRead(switch_read_pin) == HIGH) {
    if (button_state != true) {
      button_state = true;
      Serial.println("button pressed");
      digitalWrite(power_control_pin, LOW);
    }
  }
  else if (digitalRead(switch_read_pin) == LOW) {
    if (button_state != false) {
      button_state = false;
      Serial.println("button released");
      digitalWrite(power_control_pin, HIGH);
    }
  }

  delay(2);
}
