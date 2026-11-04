//Notes 
//Same concecpt from esp32_lesson_3 but now were're using the interal
//  built-in pullup and pulldown resistors in the esp32 dev board notes 
//  arduino uno r3  does not have internal pulldown resistors on the esp32S3 or C6
/*
1. GPIO 5 – Internal pull-down

One side of the button → 3.3V
Other side → GPIO 5
Code: pinMode(5, INPUT_PULLDOWN);
When pressed, GPIO 5 reads HIGH. When released, it reads LOW.

2. GPIO 6 – Internal pull-up

One side of the button → GND
Other side → GPIO 6
Code: pinMode(6, INPUT_PULLUP);
When pressed, GPIO 6 reads LOW. When released, it reads HIGH.
*/

/// Global  variables:
//LEDs
const int pullup_led = 4;
const int pulldown_led = 7;
//BUTTONs
const int pullupBtn = 6;
const int pulldownBtn = 5;

void setup() {
  Serial.begin(115200);
  pinMode(pullup_led, OUTPUT);
  pinMode(pulldown_led, OUTPUT);

  pinMode(pulldownBtn, INPUT_PULLDOWN); // were're implimenting the internal pulldown resistors
  pinMode(pullupBtn, INPUT_PULLUP);// were're implimenting the internal  pullup resistors
  
}

void loop() {
  int pulldown_Btnreads =  digitalRead(pulldownBtn);// reads high/ low for gpio 5 input
  int pullup_Btnreads =  digitalRead(pullupBtn); // reads high/ low for gpio 6 input

  if(pulldown_Btnreads == HIGH) {
    digitalWrite(pulldown_led, HIGH);
  } else {
    digitalWrite(pulldown_led, LOW);
  }

  if(pullup_Btnreads == LOW) {
    digitalWrite(pullup_led, HIGH);
  } else {
    digitalWrite(pullup_led, LOW);
  }

  Serial.print("Pull Up button status: ");
  Serial.print(pullup_Btnreads);
  Serial.print("   Pull Down button status: ");
  Serial.println(pulldown_Btnreads); 
  delay(100);

}

