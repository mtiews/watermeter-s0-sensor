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

// Updated version now using an inductive sensor (NPN) pulling the sensor output to ground
// Change was required due to the fact, that the watermeter was changed and the old solution
// did not work any more!

#define WM_INPUT_PIN A0
#define WM_LED_PIN 8
#define WM_OUTPUT_PIN 7

bool prevPinstate = false;

void setup() {
  Serial.begin(115200);
  pinMode(WM_INPUT_PIN, INPUT_PULLUP);
  pinMode(WM_LED_PIN, OUTPUT);
  pinMode(WM_OUTPUT_PIN, OUTPUT);
}

void loop() {
  readInputAndPulse();
}

void readInputAndPulse() {
  boolean pinstate = digitalRead(WM_INPUT_PIN);

  // ONLY react on state changes 
  // Important: this could be done in an isr as well, but in isrs delay() does not
  // work, so this has to be done then in the main loop with counting millis etc. 
  if(!pinstate && prevPinstate) {
      digitalWrite(WM_OUTPUT_PIN, HIGH); 
      digitalWrite(WM_LED_PIN, HIGH); 
      delay(100);
      digitalWrite(WM_OUTPUT_PIN, LOW);  
      digitalWrite(WM_LED_PIN, LOW); 
  }
  prevPinstate = pinstate;
}

