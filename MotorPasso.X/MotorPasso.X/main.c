/*
 * File:   main.c
 * Author: 20187263
 *
 * Created on 21 de Maio de 2021, 16:02
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "dispLCD4vias.h"
#include "keyboard4x4.h"
#include "stepMotor.h"

//                       **** INSTRU��ES ******
//
// Adicione � fun��o Motorpasso as seguintes op��es : 
//   -  completo = uma passo por vez;  
//   -  duplo    = dois passos por vezes, criando um movimento em diagona
//   -  metade   = meio passo dando por vez ( metade + duplo)
//   
//
// OBS 1 : caso adicione mais de um fun��o para o motor � recomendavel o uso de delay.
// OBS 2 : limite de valor na variavel graus � 360.
// 

void main(void)
{
   motorpasso_init(4);
    
    while( 1 )
    {
         
        Motorpasso(duplo,H,360,2000);
        delay(3000);
        Motorpasso(duplo,AH,360,2000);
        delay(3000);
    
    }
}
