#include <DabbleESP32.h>

#include <esp32PWMUtilities.h>
Servo Servo25;

Servo Servo26;

Servo Servo13;
float angel;
void _setup() {
  Dabble.begin("TTCar_Green");

  Servo25.attach(25);

  Servo26.attach(26);

  Servo13.attach(13);
}

void _loop() {
  Dabble.processInput();
}

void setup() {
  _setup();
}

void loop() {
  _loop();
  if (GamePad.isPressed(0)) {
    Servo25.write(150);
    Servo26.write(30);
  }
  else {
    if (GamePad.isPressed(1)) {
      Servo25.write(30);
      Servo26.write(150);
    }
    else {
      if (GamePad.isPressed(2)) {
        Servo25.write(30);
        Servo26.write(90);
        delay(0.2 * 1000);
        Servo25.write(90);
        Servo26.write(90);
      }
      else {
        if (GamePad.isPressed(3)) {
          Servo25.write(90);
          Servo26.write(150);
          delay(0.2 * 1000);
          Servo25.write(90);
          Servo26.write(90);
        }
        else {
          if (GamePad.isPressed(7)) {
            Servo25.write(90);
            Servo26.write(150);
          }
          else {
            if (GamePad.isPressed(8)) {
              Servo25.write(90);
              Servo26.write(90);
            }
            else {
              if (GamePad.isPressed(6)) {
                Servo13.write(angel);
                angel += 15;
                delay(0.2 * 1000);
                if ((angel > 120)) {
                  angel = 15;
                }
              }
              else {
                if (GamePad.isPressed(9)) {
                  Servo13.write(30);
                  delay(0.1 * 1000);
                  Servo13.write(60);
                  delay(0.1 * 1000);
                  Servo13.write(90);
                  delay(0.1 * 1000);
                  Servo13.write(120);
                  delay(0.1 * 1000);
                  Servo13.write(150);
                  delay(0.4 * 1000);
                  Servo13.write(120);
                  delay(0.4 * 1000);
                  Servo13.write(60);
                  delay(0.4 * 1000);
                  Servo13.write(15);
                }
              }
            }
          }
        }
      }
    }
  }
}
