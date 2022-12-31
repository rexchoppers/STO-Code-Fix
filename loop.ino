  TSPoint p = ts.getPoint();
  if (p.z > 10 && p.z < 1000)
  {
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);
    if (p.x > 240 && p.x < 300) // Fan
    {
      if (p.y > 0 && p.y < 160)
      {
        digitalWrite(22, HIGH);
        delay(1000);
        digitalWrite(26, HIGH);
      }
      else if (p.y > 160 && p.y < 320)
      {
        digitalWrite(22, LOW);
        digitalWrite(26, LOW);
      }
    }
    if (p.x > 170 && p.x < 230) // LED
    {
      if (p.y > 0 && p.y < 160)
      {
        digitalWrite(30, HIGH);
      }
    }
    else if (p.y > 160 && p.y < 320)
    {
      digitalWrite(30, LOW);
    }
    if (p.x > 0 && p.x < 140) // Servo
    {
      if (p.y > 0 && p.y < 160)
      {
        for (pos = 0; pos <= 180; pos += 1)
        {                    // goes from 0 degrees to 180 degrees
                             // in steps of 1 degree
          Servo1.write(pos); // tell servo to go to position in variable 'pos'
          delay(15);
        }
      }
      else if (p.y > 160 && p.y < 320)
      {
        for (pos = 180; pos >= 0; pos -= 1)
        {                    // goes from 180 degrees to 0 degrees
          Servo1.write(pos); // tell servo to go to position in variable 'pos'
          delay(15);
        }
      }
    }
  }
