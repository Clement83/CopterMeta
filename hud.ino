

const byte Go[] PROGMEM = {24,17,0x0,0x1,0x0,0x0,0x1,0x80,0x0,0x1,0xC0,0x0,0x1,0xE0,0x0,0x1,0xF0,0xFF,0xFF,0xF8,0xFF,0xFF,0xFC,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0xFC,0xFF,0xFF,0xF8,0x0,0x1,0xF0,0x0,0x1,0xE0,0x0,0x1,0xC0,0x0,0x1,0x80,0x0,0x1,0x0,};


void drawHud()
{
    //return;
   if(player.x<800)
   {
     if(gb.frameCount%20<15)
     {
       gb.display.drawBitmap(10,20,Go);
     }
   }
   gb.display.setColor(DARKBLUE);
   gb.display.setFont(font3x3);
   gb.display.print(F("\37"));
   gb.display.print(player.nbClient);
   gb.display.print(F(" \2"));
   gb.display.print(cptVictoire);
   gb.display.print(F(" \41"));
   gb.display.print(cptDeath);
   gb.display.setFont(font3x5);
   
   gb.display.drawRect(40,0,12,3);
   gb.display.setColor(BROWN);
   gb.display.drawFastHLine(41,1,getLifeHud());
   
   gb.display.setColor(BLACK);
   gb.display.drawRect(54,0,12,3);
   gb.display.setColor(BROWN);
   gb.display.drawFastHLine(55,1,getLifeMittraille());
   
   gb.display.setColor(RED);
   for(byte i=0;i<vieRestant;i++)
   {
     gb.display.cursorX = 70 - (i*4);
     gb.display.print(F(" \03"));
   }
   gb.display.setColor(BLACK);
}

uint8_t getLifeHud()
{
  return (player.hp * 10) / MAX_LIFE;
}
uint8_t getLifeMittraille()
{
  return (player.timeMitraille * 10) / TIME_TO_ENRAYE;
}
