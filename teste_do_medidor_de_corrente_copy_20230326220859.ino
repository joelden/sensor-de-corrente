#include <Wire.h>
#include <MicroLCD.h>
#include "EmonLib.h"
LCD_SSD1306 lcd; 
EnergyMonitor SCT013;
int pinSCT = A0;   //Pino analógico conectado ao SCT-013
int tensao =  110;
int potencia;
double porta0; 
void setup()
{
    Serial.begin(9600);
    pinMode(A0,INPUT);
    SCT013.current(pinSCT,275); //60.606   
    lcd.begin();
    lcd.clear();    
    delay(1000);
  }
 
void loop()
{
    double Irms = SCT013.calcIrms(2000);   // Calcula o valor da Corrente
    porta0=(analogRead(A0)); //guarda a informacao da pora A0
    //if (porta0 < 0.1) {Irms= 0; potencia =0;} // retira o falha do sensor
    potencia =  Irms * tensao; //calcula a potencia  
   
    lcd.setFontSize (FONT_SIZE_SMALL);
    lcd.setCursor(0,0);
    lcd.print("Corr. = ");
    lcd.print(Irms);
    lcd.println(" A  ");
    lcd.println();
    lcd.print("Pot. = ");
    lcd.print(potencia);
    lcd.println(" W  ");
    lcd.println();
    lcd.print("sensor= ");
    lcd.println(SCT013.calcIrms(2000));
    lcd.println();
    lcd.print("porta A0= ");
    lcd.print(porta0);
    
  Serial.print("corrent= ");
  Serial.print(Irms);
  Serial.print("A ");;
  Serial.print(" Potencia= ");
  Serial.print(potencia);
  Serial.print("W ");
  Serial.print("Sensor= ");
  Serial.print(SCT013.calcIrms(2000));
  Serial.print("  ");
  Serial.print("Porta A0= ");
  Serial.println(porta0);
  
  
}
