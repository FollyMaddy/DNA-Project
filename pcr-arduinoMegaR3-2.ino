#include "U8glib.h"

int ThermistorPin = A0;
int DekselPin = A1;
int Vo;
int Vd;
float R0 = 100000.0;
//https://www.thinksrs.com/downloads/programs/Therm%20Calc/NTCCalibrator/NTCcalculator.htm
//25,62,100
//float c1 = 0.6123279002e-03, c2 = 2.203449904e-04, c3 = 1.342541828e-07; 
//25,62,105
float c1 = 1.073676236e-03, c2 = 1.560431092e-04, c3 = 3.170541791e-07; 
//float c1 = 0.8270549106e-03, c2 = 2.088087683e-04, c3 = 0.8057733763e-07;

//deksel
float Rd0 = 10000.0;
float c4 = 1.009249522e-03, c5 = 2.378405444e-04, c6 = 2.019202697e-07;
//float c4 = 1.127936811e-03, c5 = 2.343414632e-04, c6 = 0.8666779408e-07;

float logR1, logRd, R1, Rd, T, Td;
U8GLIB_ST7920_128X64_1X u8g(52, 51, 1);  // SPI Com: SCK = en = 52, MOSI = rw = 51, CS = di = 1

void setup() {  
  u8g.setFont(u8g_font_unifont);
  u8g.setColorIndex(1); // Instructs the display to draw with a pixel on. 
}

void loop() {  
  Vo = analogRead(ThermistorPin);
  R1 = R0 * (1023.0 / (float)Vo - 1.0);
  logR1 = log(R1);
  T = (1.0 / (c1 + c2*logR1 + c3*logR1*logR1*logR1));
  T = T - 273.15;

  Vd = analogRead(DekselPin);
  Rd = Rd0 * (1023.0 / (float)Vd - 1.0);
  logRd = log(Rd);
  Td = (1.0 / (c4 + c5*logRd + c6*logRd*logRd*logRd));
  Td = Td - 273.15;

  u8g.firstPage();
  do {  
    draw();
  } while( u8g.nextPage() );
  delay(500);
}
  
void draw(){
  u8g.drawStr( 0, 15, "Temp = ");
  u8g.drawStr(95, 15, " C");
  //u8g.drawStr(0,35, "R = ");
  u8g.setPrintPos(50, 15);
  u8g.print(T);
  //u8g.setPrintPos(25, 35);
  //u8g.print(R2);

  u8g.drawStr( 0,35, "Deksel = ");
  u8g.drawStr(115, 35, " C");
  u8g.drawStr(0,55, "Rd = ");
  u8g.setPrintPos(65, 35);
  u8g.print(Td);
  u8g.setPrintPos(35, 55);
  u8g.print(Rd);
}
