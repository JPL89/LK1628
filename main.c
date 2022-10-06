/*
	@File 		
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		02/10/22
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 
  
*/

#include "config.h"

#include <xc.h>
#include "lk1628.h"

// BOARD MODEL: JXY048CY
//
// ADDRESS 0x00 - 0x01
// B15   
// B14   
// B13   
// B12  
// B11  MP3 
// B10   
// B9   
// B8   MP4   
// B7   DP
// B6   PLAY
// B5   PAUSE
// B4   DVD
// B3   CD
// B2   -
// B1   -
// B0   -  

// ADDRESS 0x02 - 0x03
// ADDRESS 0x04 - 0x05
// ADDRESS 0x06 - 0x07
// ADDRESS 0x08 - 0x09
//
// B15  -   
// B14  -   
// B13  -   
// B12  -   
// B11  G   
// B10  -   
// B9   -   
// B8   F
// B7   E   
// B6   A   
// B5   B   
// B4   C   
// B3   D   
// B2   -   
// B1   -   
// B0   -

#define CD          3
#define DVD         4
#define PAUSE       5
#define PLAY        6
#define DP          7
#define MP4         8     
#define MP3         11

static unsigned char address[] = {0x08, 0x06, 0x04, 0x02};

volatile unsigned char key = 0;

unsigned char SYMBOL = 0;

static const unsigned short Font[] =
{
    0x01F8, // 0
    0x0030, // 1
    0x08E8, // 2
    0x0878, // 3
    0x0930, // 4
    0x0958, // 5
    0x09D8, // 6
    0x0070, // 7
    0x09F8, // 8
    0x0978, // 9
};

void SetData(unsigned char addr, unsigned char num)
{
    LK1628_Data(address[ addr] + 0, Font[ num ] & 0xFF);
    LK1628_Data(address[ addr] + 1, Font[ num ] >> 8);
}

void SetSymbol(unsigned char sym, unsigned char state)
{
    SYMBOL &=~(1 << sym);
    
    SYMBOL |= (state << sym);
    
    LK1628_Data(0x00,   SYMBOL & 0xFF);
    LK1628_Data(0x01,   SYMBOL >> 8 );
}

int main(void) 
{
    // WAIT VCC
    __delay_ms(500);
    
    LK1628_Init();
    
    SetData(0, 1);
    SetData(1, 2);
    SetData(2, 3);
    SetData(3, 4);
    
    while(1)
    {
        
    }
    
    return 0;
}
