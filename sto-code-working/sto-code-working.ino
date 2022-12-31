#include <Elegoo_GFX.h>     // Core graphics library
#include <Elegoo_TFTLCD.h>  // Hardware-specific library
#include <TouchScreen.h>
#include <Servo.h>
Servo Servo1;
int pos = 0;

#define TS_MINX 920
#define TS_MINY 120

#define TS_MAXX 150
#define TS_MAXY 940

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 100);

// macros for color (16 bit)
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

#define LCD_CS A3     // Chip Select goes to Analog 3
#define LCD_CD A2     // Command/Data goes to Analog 2
#define LCD_WR A1     // LCD Write goes to Analog 1
#define LCD_RD A0     // LCD Read goes to Analog 0
#define LCD_RESET A4  // Can alternately just connect to Arduino's reset pin

// H = 240
// W = 320

Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void initSecondScreen() {
  /** INIT SCREEN **/
  tft.setRotation(2);
  tft.fillScreen(BLACK);

  /** FAN ON SECTION **/
  tft.fillRect(8, 210, 60, 100, MAGENTA);
  tft.fillRoundRect(8, 180, 60, 130, 30, MAGENTA);

  /** FAN OFF SECTION **/
  tft.fillRect(8, 10, 60, 100, MAGENTA);
  tft.fillRoundRect(8, 10, 60, 130, 30, MAGENTA);

  /** LED ON SECTION **/
  tft.fillRect(80, 210, 60, 100, CYAN);
  tft.fillRoundRect(80, 180, 60, 130, 30, CYAN);

  /** LED OFF SECTION **/
  tft.fillRect(80, 10, 60, 100, CYAN);
  tft.fillRoundRect(80, 10, 60, 130, 30, CYAN);

  /** VISOR ON SECTION **/
  tft.fillRect(153, 210, 60, 100, GREEN);
  tft.fillRoundRect(153, 180, 60, 130, 30, GREEN);

  /** VISOR OFF SECTION **/
  tft.fillRect(153, 10, 60, 100, RED);
  tft.fillRoundRect(153, 10, 60, 130, 30, RED);

  /** BARS AT BOTTOM **/
  tft.fillRoundRect(220, 80, 40, 900, 20, YELLOW);
  tft.fillRoundRect(220, 0, 40, 70, 20, BLUE);

  /** LEFT SIDE BAR FILL **/
  tft.fillRoundRect(0, 315, 320, 40, 10, YELLOW);

  /** SET UP TEXT PROPERTIES **/
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setRotation(1);

  /** "FAN ON" TEXT **/
  tft.setCursor(30, 30);
  tft.println("FAN ON");

  /** "FAN OFF" TEXT **/
  tft.setCursor(200, 30);
  tft.println("FAN OFF");

  /** "LIGHT ON" TEXT **/
  tft.setCursor(30, 100);
  tft.println("LIGHT ON");

  /** "LIGHT OFF" TEXT **/
  tft.setCursor(200, 100);
  tft.println("LIGHT OFF");

  /** "VISOR UP" TEXT **/
  tft.setCursor(30, 175);
  tft.println("VISOR UP");

  /** "VISOR DOWN" TEXT **/
  tft.setCursor(185, 175);
  tft.println("VISOR DOWN");
}

void setup() {

  Serial.begin(9600);
  tft.reset();  // LCARS START
  tft.begin(0x9341);
  tft.fillScreen(BLACK);

  // DEBUG Line for testing boundaries
  // tft.drawRect(0, 0, 240, 320, CYAN);

  // Set screen rotation
  tft.setRotation(1);

  /** "LCARS MENU" TEXT **/
  tft.setTextSize(4);
  tft.setTextColor(YELLOW);
  tft.setCursor(40, 80);
  tft.println("LCARS MENU");

  /** "SYSTEM" TEXT **/
  tft.setCursor(80, 130);
  tft.println("SYSTEM");

  /** "74656-MACO" TEXT **/
  tft.fillRoundRect(0, 5, 130, 50, 20, CYAN);
  tft.fillRect(100, 40, 120, 15, CYAN);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 20);
  tft.println("74656-MACO");

  /** "ONLINE" TEXT **/
  tft.fillRect(140, 5, 170, 30, MAGENTA);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(190, 14);
  tft.println("ONLINE");

  /** Draw bar **/
  tft.fillRect(230, 40, 80, 15, YELLOW);

  /** "POWER" TEXT **/
  tft.fillRoundRect(0, 180, 180, 60, 30, RED);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.setCursor(45, 198);
  tft.println("POWER");

  /** "OK" TEXT **/
  tft.fillRoundRect(200, 180, 120, 60, 30, GREEN);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.setCursor(244, 198);
  tft.println("OK");

  /** DELAY UNTIL NEXT SCREEN **/
  delay(3000);

  /** DEBUG - RESET SCREEN AND BUFFERS **/
  // tft.reset();

  /** ============ SCREEN 2 ============ **/
  initSecondScreen();

  Servo1.attach(32);
  pinMode(26, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(30, OUTPUT);
}

void loop() {
  TSPoint p = ts.getPoint();

  if (p.z > 10 && p.z < 1000) {

    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);

    if (p.x > 240 && p.x < 300)  // Fan
    {
      if (p.y > 0 && p.y < 160) {
        digitalWrite(22, HIGH);
        delay(1000);
        digitalWrite(26, HIGH);
      } else if (p.y > 160 && p.y < 320) {
        digitalWrite(22, LOW);
        digitalWrite(26, LOW);
      }
    }

    // "LIGHT ON" - Pressed
    if (p.x > 170 && p.x < 230 && p.y > 0 && p.y < 160) {
      digitalWrite(30, HIGH);
    }

    // "LIGHT OFF" - Pressed
    if (p.x > 170 && p.x < 230 && p.y > 160 && p.y < 320) {
      digitalWrite(30, LOW);
    }

    // "VISOR UP" - Pressed
    if (p.x > 0 && p.x < 140 && p.y > 0 && p.y < 160)  // Servo
    {
      for (pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
                                             // in steps of 1 degree
        Servo1.write(pos);                   // tell servo to go to position in variable 'pos'
        delay(5);
      }
    }

    // "VISOR DOWN" - Pressed
    if (p.x > 0 && p.x < 140 && p.y > 160 && p.y < 320) {
      for (pos = 180; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
        Servo1.write(pos);                   // tell servo to go to position in variable 'pos'
        delay(5);
      }
    }
  }

  delay(50);
}