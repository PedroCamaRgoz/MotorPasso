#ifndef STEPMOTOR_H
#define STEPMOTOR_H

#define PORTA_B 0x006
#define PORTA_D 0x008

#define H   1
#define AH -1

#define completo 10
#define duplo    15
#define metade   20

void motorpasso_init ( int num );
void Motorpasso (char modo ,char sentido, int graus, char t );


#endif
