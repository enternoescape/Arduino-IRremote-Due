/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 * Samsung and Samsung2 protocol added by Joseph Shuttlesworth
 * (Thanks to Ribeiro Santos from the original blog post and http://www.maartendamen.com/2010/05/jeenode-infrared-project-part-1-getting-started/)
 */
#include <IRremote2.h>
 
#define Samsung2Address      0x200       // Samsung2 Address (Pre data) 
#define Samsung2Power        0x7007F000  // Samsung2 Power Button

#define Samsung              0xB4B40CF3 //Samsung Power Button

IRsend irsend;

void setup()
{
}

void loop() {
  irsend.sendSamsung2(Samsung2Address,Samsung2Power); // This should turn your TV on and off
  
  irsend.sendSamsung(REPEAT, 32); // Some receivers seem to respond a lot faster when a repeat is sent before the actual command.
  delay(35); //This delay is needed for optimal response.
  irsend.sendSamsung(Samsung, 32); // hex value, 32 bits
  delayMicroseconds(50);
}
