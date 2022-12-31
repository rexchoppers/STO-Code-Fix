void setup()
{

  Serial.begin(9600);
  tft.reset(); // LCARS START
  tft.begin(0x9341);
  tft.fillScreen(BLACK);
  tft.setRotation(1);
  tft.setTextSize(4);
  tft.setTextColor(YELLOW);
  tft.setCursor(40, 80);
  tft.println("LCARS MENU");
  tft.setCursor(80, 130);
  tft.println("SYSTEM");                      // LCARS END
  tft.fillRoundRect(0, 5, 130, 50, 20, CYAN); // MACO START
  tft.fillRect(100, 40, 120, 15, CYAN);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 20);
  tft.println("74656-MACO");              // MACO END
  tft.fillRect(140, 5, 170, 30, MAGENTA); // ONLINE START
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(190, 14);
  tft.println("ONLINE");                       // ONLINE END
  tft.fillRect(230, 40, 80, 15, YELLOW);       // BAR
  tft.fillRoundRect(0, 180, 180, 60, 30, RED); // POWER START
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.setCursor(45, 198);
  tft.println("POWER");                            // POWER END
  tft.fillRoundRect(200, 180, 120, 60, 30, GREEN); // OK START
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.setCursor(244, 198);
  tft.println("OK"); // OK END
  delay(3000);

  tft.setRotation(2);    // Initialise LCD
  tft.fillScreen(BLACK); // Black Background

  tft.fillRect(8, 210, 60, 100, MAGENTA);          // Fan on square
  tft.fillRoundRect(8, 180, 60, 130, 30, MAGENTA); // Fan on round

  tft.fillRect(8, 10, 60, 100, MAGENTA);          // Fan off square
  tft.fillRoundRect(8, 10, 60, 130, 30, MAGENTA); // Fan off round

  tft.fillRect(80, 210, 60, 100, CYAN);         // Led on square
  tft.fillRoundRect(80, 180, 60, 130, 30, CYAN); // Led on round

  tft.fillRect(80, 10, 60, 100, CYAN);          // Led off square
  tft.fillRoundRect(80, 10, 60, 130, 30, CYAN); // Led off round

  tft.fillRect(153, 210, 60, 100, GREEN);          // Visor on square
  tft.fillRoundRect(153, 180, 60, 130, 30, GREEN); // visor on round

  tft.fillRect(153, 10, 60, 100, RED);          // visor off square
  tft.fillRoundRect(153, 10, 60, 130, 30, RED); // visor off round

  tft.fillRoundRect(220, 80, 40, 900, 20, YELLOW); // Yellow bar
  tft.fillRoundRect(220, 0, 40, 70, 20, BLUE);     // Blue bar

  tft.fillRoundRect(0, 315, 320, 40, 10, YELLOW);
  tft.setTextColor(BLACK); // Set Text Proporties
  tft.setTextSize(2);
  tft.setCursor(30, 30);
  tft.setRotation(1);
  tft.println("FAN ON"); // Write Text on LCD
  tft.setCursor(200, 30);
  tft.println("FAN OFF");
  tft.setCursor(30, 100);
  tft.println("LIGHT ON");
  tft.setCursor(200, 100);
  tft.println("LIGHT OFF");
  tft.setCursor(30, 175);
  tft.println("VISOR UP");
  tft.setCursor(185, 175);
  tft.println("VISOR DOWN");
  tft.setCursor(180, 220);
  Servo1.attach(32);
  pinMode(26, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(30, OUTPUT);
}
