
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;



int trigger=7;                               // Der Trigger Pin

int echo=8;                                  // Der Echo Pin

long dauer=0;                                // Hier wird die Zeitdauer abgespeichert

                                             // die die Ultraschallwelle braucht

                                             // um zum Sensor zurückzukommen

long entfernung=0;                           // Hier wird die Entfernung vom 

                                             // Hindernis abgespeichert

int personenzahl =0; 
 

void setup()

 

{

    Serial.begin(9600);                      // Die serielle Kommunikation starten

    pinMode(trigger, OUTPUT);                // Trigger Pin als Ausgang definieren

    pinMode(echo, INPUT);  
        lcd.begin(16, 2);

}

 

void loop()

{

    digitalWrite(trigger, LOW);              // Den Trigger auf LOW setzen um

                                             // ein rauschfreies Signal

                                             // senden zu können

    delay(5);                                // 5 Millisekunden warten

    digitalWrite(trigger, HIGH);             // Den Trigger auf HIGH setzen um eine 

                                             // Ultraschallwelle zu senden

    delay(10);                               // 10 Millisekunden warten

    digitalWrite(trigger, LOW);              // Trigger auf LOW setzen um das 

                                             // Senden abzuschließen

    dauer = pulseIn(echo, HIGH);             // Die Zeit messen bis die 

                                             // Ultraschallwelle zurückkommt

    entfernung = (dauer/2) / 29.1;           // Die Zeit in den Weg in Zentimeter umrechnen

 

        Serial.print(entfernung);            // Den Weg in Zentimeter ausgeben

        Serial.println(" cm");               //


if(entfernung <88)
{

  personenzahl = personenzahl +1;
  delay(2000);


}
  Serial.println(personenzahl);

  lcd.setCursor(0,0);
  lcd.print("Personenzahl:");
  lcd.setCursor(0,1);
  lcd.print(personenzahl);


 
                     // Nach einer Sekunde wiederholen

 

}
