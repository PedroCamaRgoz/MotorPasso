/*
 * File:   keyboard4x4.c
 * Author: Pedro
 *
 * Created on 12 de Maio de 2021, 18:48
 */

#include <xc.h>

void teclado_init (void)
{
    TRISB = 0xF0;
    ANSELH = 0;
    OPTION_REGbits.nRBPU = 0;
    WPUB = 0xFF;
    PORTB = 0xFF;
    
}

#define MASK 0x10

char tecladoMatriz[4][4] = { {'1','2','3','A'},
                             {'4','5','6','B'},
                             {'7','8','9','C'},
                             {'*','0','#','D'}, };

char teclado (void)
{
    char aux = 0;
    unsigned char l,c;
    
    for( l=0; l<4; l++ )
    {
        PORTB = ~(0x01 << l);
        
        for( c=0; c<4; c++ )
        {            
             if( ~PORTB & (MASK<<c) )   
             {
                 aux = tecladoMatriz[l][c];
             }
             
        }
        
    }
    return(aux);   
}