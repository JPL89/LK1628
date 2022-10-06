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

#ifndef LK1628_H_
#define LK1628_H_

#include <xc.h>

#define LK1628_MOSI_LOW					PORTCbits.RC0=0
#define LK1628_MOSI_HIGH				PORTCbits.RC0=1

#define LK1628_CS_LOW					PORTCbits.RC2=0
#define LK1628_CS_HIGH					PORTCbits.RC2=1

#define LK1628_SCK_LOW					PORTCbits.RC1=0
#define LK1628_SCK_HIGH					PORTCbits.RC1=1

void LK1628_Write(unsigned char data);
void LK1628_Command(unsigned char data);
void LK1628_Data(unsigned char address, unsigned char data);
void LK1628_Init(void);

unsigned char LK1628_GetKey(void);
unsigned char LK1628_Read(void);

#endif /*  */