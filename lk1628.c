/*
	@File 		
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		20/06/21
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#include "lk1628.h"

#define _NOP() __asm__ __volatile__("nop")

void LK1628_Write(unsigned char data)
{
    for(unsigned char mask = 0x01; mask; mask <<= 1)
    {
        LK1628_SCK_LOW; 
        if (data & mask) LK1628_MOSI_HIGH; else LK1628_MOSI_LOW;
	LK1628_SCK_HIGH;
    }
}

void LK1628_Command(unsigned char data)
{
	LK1628_CS_LOW;
	LK1628_Write(data);	
	LK1628_CS_HIGH;
}

void LK1628_Data(unsigned char address, unsigned char data)
{        
        LK1628_Command(0x44);
        
	LK1628_CS_LOW;	
	LK1628_Write(0xC0 | address);
	LK1628_Write(data);	
	LK1628_CS_HIGH;
}

unsigned char LK1628_Read(void)
{
	unsigned char data = 0;
              
	TRISC0 = 1;
        
	for (unsigned char bit=0; bit<8; bit++) 
        {
		LK1628_SCK_LOW;
                
                data >>= 1;
                
		if (PORTCbits.RC0 == 1) data |= 0x80;
			
		LK1628_SCK_HIGH;
	}
        
	TRISC0 = 0;
        
	return data;
}

unsigned char LK1628_GetKey(void)
{
    unsigned char key = 0;

    LK1628_CS_LOW;

    LK1628_Write(0x42);

    key |= LK1628_Read() << 0; 
    key |= LK1628_Read() << 1;
    key |= LK1628_Read() << 2;
    key |= LK1628_Read() << 3;
    key |= LK1628_Read() << 4;

    LK1628_CS_HIGH;        

    return key;
}

void LK1628_Init(void)
{
    TRISC0 = 0;
    TRISC1 = 0;
    TRISC2 = 0;
	
    LK1628_CS_HIGH;

    // COMMAND1
    // B7 B6 B5 B4 B3 B2 B1 B0
    // 0  0  -  -  -  -  1  0   6 Grids, 12 Segments
    // 0  0  -  -  -  -  1  1   7 Grids, 11 Segments
    LK1628_Command( 0x00 | 0x02 );
    
    // COMMAND2
    // B7 B6 B5 B4 B3 B2 B1 B0
    // 0  1  -  -  -  0  0  0   Write data to display mode
    // 0  1  -  -  -  0  1  0   Read key scan data
    // 0  1  -  -  -  1  0  0   Fixed Address
    LK1628_Command( 0x40 | 0x04 );
    
    // COMMAND3: [B0..B3] address [0x00..0x0D]
    // B7 B6 B5 B4 B3 B2 B1 B0
    // 0  0  -  -  0  0  0  0   
    // 0  0  -  -  0  0  0  0   
    // 0  0  -  -  0  0  0  0   
    // 0  0  -  -  0  0  0  0  
    LK1628_Command( 0xC0 | 0x00 );
    
    // COMMAND4
    // B7 B6 B5 B4 B3 B2 B1 B0
    // 1  0  -  -  0  0  0  0   Pulse width = 1/16
    // 1  0  -  -  0  0  0  1   Pulse width = 2/16
    // 1  0  -  -  0  0  1  0   Pulse width = 4/16
    // 1  0  -  -  0  0  1  1   Pulse width = 10/16
    // 1  0  -  -  0  1  0  0   Pulse width = 11/16
    // 1  0  -  -  0  1  0  1   Pulse width = 12/16
    // 1  0  -  -  0  1  1  0   Pulse width = 13/16
    // 1  0  -  -  0  1  1  1   Pulse width = 14/16
    // 1  0  -  -  1  0  0  0   Display ON 
    LK1628_Command( 0x88 | 0x07 );
}
