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

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

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



  Servo1.attach(32);
  pinMode(26, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(30, OUTPUT);
}

void loop() {


  delay(100);
}