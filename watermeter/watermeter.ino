// #########################################################################
// # Copyright 2018 Marcel Tiews marcel.tiews@gmail.com
// #########################################################################
// #
// # This sketch is free software: you can redistribute it and/or modify
// # it under the terms of the GNU General Public License as published by
// # the Free Software Foundation, either version 3 of the License, or
// # (at your option) any later version.
// #
// # This plugin is distributed in the hope that it will be useful,
// # but WITHOUT ANY WARRANTY; without even the implied warranty of
// # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// # GNU General Public License for more details.
// #
// # You should have received a copy of the GNU General Public License
// # along with this plugin. If not, see <http://www.gnu.org/licenses/>.
// #########################################################################

#define WM_INPUT_PIN A0
#define WM_LED_PIN 8
#define WM_OUTPUT_PIN 7

#define HYSTERESIS 100
#define UPPER_THRESHOLD 450
#define LOWER_THRESHOLD 250

bool active = false;

void setup() {
  Serial.begin(115200);
  pinMode(WM_LED_PIN, OUTPUT);
  pinMode(WM_OUTPUT_PIN, OUTPUT);
}

void loop() {
  readInputAndPulse();
  switchLed();
}

void readInputAndPulse() {
  int aval = analogRead(A0);
  
  if(active) {
    if(aval > (UPPER_THRESHOLD - HYSTERESIS)) {
      active = false;
    }
  }
  else {
    if(aval < (LOWER_THRESHOLD + HYSTERESIS)) {
      active = true;
      // Pulse output if switching from un-active to active
      digitalWrite(WM_OUTPUT_PIN, HIGH);  
      delay(5);
      digitalWrite(WM_OUTPUT_PIN, LOW);  
    }
  }
}

void switchLed() {
  if(active) {
    digitalWrite(WM_LED_PIN, HIGH);
  }
  else {
    digitalWrite(WM_LED_PIN, LOW); 
  }
}
