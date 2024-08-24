//
//  Util.h
//  prog3-calc
//
//  Created by Marysia Knapczyk on 16/03/2023.
//

#ifndef _UTIL_H_
#define _UTIL_H_
#include <stdio.h>

double getNum();
char getOper();
int isOper( char );
int prior( char oper );
double Eval( double arg1, double arg2, char oper );
void skipSpaces();
int isDigit( char c );


#endif /* Util_h */
 
