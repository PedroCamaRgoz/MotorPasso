#ifndef DISPLCD4VIAS_H
#define DISPLCD4VIAS_H


void dispLCD_instReg( unsigned char i );

void dispLCD_dataReg( unsigned char d );

void dispLCD_lincol( unsigned char lin, unsigned char col);

void dispLCD_init( void );

void dispLCD_Texto( unsigned char lin, unsigned char col, const char * str );

void dispLCD_num(  unsigned char lin, unsigned char col, int num, unsigned char tam );

void dispLCD_clr( void );


#endif









