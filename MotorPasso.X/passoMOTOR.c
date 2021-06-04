/*
 * File:   passoMOTOR.c
 * Author: 20190224
 *
 * Created on 27 de Maio de 2021, 13:36
 */

#include "config.h"
#include "delay.h"
#include <xc.h>

void motor_init(void)
{   
        ANSELH = 0;
        TRISD= 0x00; 
        PORTD = 0x00;
}



void motor(int pulsos, int sentido)
{
    pulsos = pulsos / 4;
    int z;
    int n;
    
    if(sentido == 0)
    {   
        for(z = pulsos; z>0; z--)
        {                
            char i = 0x01;

            for(n=0; n<4; n++)
            {
                PORTD = i<<n;
                __delay_ms(100);
            }
        }    
    }   
        
    if(sentido == 1)    
    {   
        for(z = pulsos; z>0; z--)
        {
            char i = 0x08;

            for(n=0; n<4; n++)
            {
                PORTD = i>>n;
                __delay_ms(100);

            }
        }    
    }
}