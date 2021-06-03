/*
 * File:   stepMotor.c
 * Author: 20187263
 *
 * Created on 26 de Maio de 2021, 15:26
 */

#include "config.h"
#include <xc.h>
#include "delay.h"

// **                 Vetores de passo                    ***

char complete_step[4]={0x02,0x04,0x01,0x08};
char double_step  [4]={0x06,0x05,0x09,0x0A};
char half_step    [8]={0x02,0x06,0x04,0X05,0x01,0x09,0x08,0x0A};



//**                Variaveis de passo                    ***

int  ppr = 0;                                      
char aux = 0;

// função de inicialização e configuração dos port's escolhidos
void motorpasso_init ( int num)
{
    TRISDbits.TRISD0 = 0;  
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;  
    TRISDbits.TRISD3 = 0;

   
    PORTD = 0;             
    
    ppr = num;  
    
 
}

// Função principal motor de passo

void Motorpasso (char modo ,char sentido, int graus, char t )
{
    char i; 
    char passo = (graus * ppr)/360;  
    
    
    switch(modo)
    {
        case 10:                                       // completo
                for(i=0; i<passo; i++)
                {
                     aux = ( aux + sentido )  % 4;
                     delay(t);
                     PORTD = (PORTD & 0xF0) | complete_step[aux];                        
                }
                break;
                 
        case 15:                                       // duplo
                for(i=0; i<passo; i++)                   
                { 
                     aux = ( aux + sentido )  % 4;   
                     delay(t);
                     PORTD = (PORTD & 0xF0) | double_step[aux];   
                }
                break;
                
        case 20:                                        // metade
                passo = (graus * ppr)/180;  
     
                for(i=0; i<passo; i++)
                {
                     aux = ( aux + sentido )  % 8;
                     delay(t);
                     PORTD = (PORTD & 0xF0) | half_step[aux];    
                }
                break;              
    }   
}

