#ifndef CONFIG_H
#define	CONFIG_H

// CONFIG1H
#pragma config OSC = HS         
#pragma config FCMEN = OFF      
#pragma config IESO = OFF       

// CONFIG2L
#pragma config PWRT = OFF       
#pragma config BOREN = OFF      
#pragma config BORV = 3         

// CONFIG2H
#pragma config WDT = OFF        
#pragma config WDTPS = 32768    

// CONFIG3H
#pragma config CCP2MX = PORTC   
#pragma config PBADEN = OFF     
#pragma config LPT1OSC = OFF    
#pragma config MCLRE = ON       

// CONFIG4L
#pragma config STVREN = OFF     
#pragma config LVP = OFF        
#pragma config XINST = OFF      

// CONFIG5L
#pragma config CP0 = OFF        
#pragma config CP1 = OFF        
#pragma config CP2 = OFF        
#pragma config CP3 = OFF        

// CONFIG5H
#pragma config CPB = OFF        
#pragma config CPD = OFF        

// CONFIG6L
#pragma config WRT0 = OFF       
#pragma config WRT1 = OFF       
#pragma config WRT2 = OFF       
#pragma config WRT3 = OFF       

// CONFIG6H
#pragma config WRTC = OFF       
#pragma config WRTB = OFF       
#pragma config WRTD = OFF       

// CONFIG7L
#pragma config EBTR0 = OFF      
#pragma config EBTR1 = OFF      
#pragma config EBTR2 = OFF      
#pragma config EBTR3 = OFF      

// CONFIG7H
#pragma config EBTRB = OFF     

#define _XTAL_FREQ   20000000

#endif	/* CONFIG_H */

