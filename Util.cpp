//
//  Util.cpp
//  prog3-calc
//
//  Created by Marysia Knapczyk on 16/03/2023.
//

#include "Util.h"
#include <cmath>
#define DBL_MIN 1e-150


double getNum() // czytamy doubla bez znaka
{
  char c;
  double res = 0;
  skipSpaces();
  while( isDigit( c = getchar() ) )
    res =  res * 10 + c - '0';
  if( c == '.' )
  {
    double coef = 0.1;
    while( isDigit( c = getchar() ) )
    {
      res += (c-'0') * coef;
      coef *= 0.1;
    }
  }
  ungetc(c, stdin );
  return res;
}

char getOper()
{
  skipSpaces();
  return getchar();
}

int isOper( char c ) //switchem
{
  switch( c ) {
     case '+':
     case '-':
     case '*':
     case '/':
     case '^': return 1;
     }
     return 0;
}

int prior( char oper ) //switchem
{
  switch( oper ) {
         case '+': 
         case '-':return 1;
         case '*':
         case '/': return 2;
         case '^': return 3;
     }
     return 0;
}

double Eval( double arg1, double arg2, char oper )//switch
{
  switch( oper ) {
    case '+': return arg1 + arg2;
    case '-': return arg1 - arg2;
    case '*': return arg1 * arg2;
    case '/': if( fabs(arg2)>DBL_MIN )
                return arg1 / arg2;
      perror( "ERROR: you must not divide by ZERO!! \n");
      break;
    case '^': return pow( arg1, arg2 );
     }
     return 0;
}

void skipSpaces()
{
  char c;
  while( ( c = getchar() ) == ' '  || c == '\t' );
  ungetc( c, stdin );
}

int isDigit( char c )
{
  return ( c >= '0' && c <= '9' );
}
