/*
 * File:   main.c
 * Author: 20190224
 *
 * Created on 27 de Maio de 2021, 13:36
 */

#include "config.h"
#include <xc.h>
#include "passoMOTOR.h"
#include "dispLCD4vias.h"
#include "keyboard4x4.h"
#include "stepMotor.h"
#include "delay.h"

//                       **** INSTRUÇÕES ******
//
// Adicione as  funções no while : passocompleto, passoduplo e meiopasso
// caso 1 : caso adicione mais de um função para o motor é recomendavel o uso de delay.
// case 2 : limite de valor na variavel graus é 360.


void main(void) 
{

    motor_init();
    
    while( 1 )
    {
     
        
        

    motorpasso_init(8);
      
    }

    return;

}
