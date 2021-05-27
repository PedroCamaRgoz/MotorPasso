#ifndef STEPMOTOR_H
#define STEPMOTOR_H

#define H   1
#define AH -1

void motorpasso_init ( int num );
void passocompleto (char sentido, int graus, char t);
void passoduplo (char sentido, int graus, char t);
void meiopasso  (char sentido, int graus, char t);

// void motorpasso( char modo, char sentido, int grau, char t);





#endif