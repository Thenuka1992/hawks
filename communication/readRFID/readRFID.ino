/* 
PINOUT:
RC522 MODULE    Uno/Nano     MEGA
SDA             D10          D9
SCK             D13          D52
MOSI            D11          D51
MISO            D12          D50
IRQ             N/A          N/A
GND             GND          GND
RST             D9           D8
3.3V            3.3V         3.3V

*/

#include <SPI.h>
#include <RFID.h>

/* Define the DIO used for the SDA (SS) and RST (reset) pins. */
#define SDA_DIO 10
#define RESET_DIO 9

/* Create an instance of the RFID library */
RFID RC522(SDA_DIO, RESET_DIO); 


void setup()
{ 
  Serial.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
}

void loop()
{
  /* Temporary loop counter */
  byte i;

  /* Has a card been detected? */
  if (RC522.isCard())
  {
    /* If so then get its serial number */
    RC522.readCardSerial();

    //Serial.println("Card detected:");

    /* Output the serial number to the UART */
    for(i = 0; i <= 4; i++)
    {
      Serial.print(RC522.serNum[i],HEX);
      //Serial.println();
      //Serial.print("");
    }
    Serial.println();
    //Serial.println();
  }
}