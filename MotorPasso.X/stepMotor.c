/*
 * File:   stepMotor.c
 * Author: 20187263
 *
 * Created on 26 de Maio de 2021, 15:26
 */

#include "config.h"
#include <xc.h>
#include "delay.h"

char numeropasso[4]={0x02,0x04,0x01,0x08};
char duplopulso [4]={0x09,0x0A,0x06,0x05};
int    meiopass [8]={0x02,0x06,0x04,0X05,0x01,0x09,0x08,0x0A};

unsigned int ppr = 0; // ppr =  passos por revolução/ pulsos por revolução

void motorpasso_init ( int num )
{
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    
    PORTD = 0;
    
    ppr = num;
    
}

void passocompleto ( char sentido , int graus , char t)
{
    char i;   char aux = 0;
    
    char passo = (graus * ppr)/360;   
    
    for(i=0; i<passo; i++)
    {
        
     PORTD = (PORTD & 0xF0) | numeropasso[aux];
     delay(t);
     aux = ( aux + sentido )  % 4;                 // sentido de rotação + aux que está direcionando as colunas do vetor "numpasso", s
                                                   // sentido, igual a +1, soma os vetores em ordem crescente, se for igual a -1 vetores fica decrescente
    }
}

void passoduplo (char sentido, int graus, char t)
{
    char i;    char aux = 0;
    
    char passo = (graus * ppr)/360;  
    
    for(i=0; i<passo; i++)
    {
      PORTD = (PORTD & 0xF0) | duplopulso[aux];
      delay(t);
      aux = ( aux + sentido )  % 4;                   
    }    
}

void meiopasso (char sentido, int graus, char t)
{
    char i;    char aux = 0;
    
    char passo = (graus * ppr)/180;  
    
    for(i=0; i<passo; i++)
    {
      PORTD = (PORTD & 0xF0) | meiopass[aux];
      delay(t);
      aux = ( aux + sentido )  % 8;                   
    }    
}

