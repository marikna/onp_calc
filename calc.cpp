//
//  main.cpp
//  prog3-calc
//
//  Created by Marysia Knapczyk on 16/03/2023.
//

#include <iostream>
#include <stdio.h>
#include "Stack.h"
#include "DStack.h"
#include "Util.h"


double ONP();

int main()
{
  
  printf( "Podaj wyrazenie: ");
  printf( "Wynik wyrazenia = %lf\n", ONP() );
  
  
  return 0;
} 

double ONP()
{
//  zadeklarowac zmienna stosowa i wykreowac stos operatora
  StackItem* pStack = createStack();
  DStackItem* pDStack = createDStack();
  
  char c;
  
    //wczytac liczbe i wlozyc na stos operanda
    Dpush( &pDStack, getNum());
  // ( prior operatora <= priorytetu stosu operatora )
    while( isOper(c = getOper()))//wczytujemy kolejny operator i sorawdzamy
    {
      while ( prior( c ) <= prior( top( pStack ) ) )
      {
        // sciagnac dwa operandy ze stosu i operator -> przeliczyc
        //wylizcyc wynik na stos operanda
        // na stos wczytany operator
        double a = Dpop(&pDStack);
        Dpush( &pDStack, Eval(Dpop(&pDStack), a, pop(&pStack)) );
        // nowy operand wczytac wstawic
      }
      push( &pStack, c );
      Dpush( &pDStack, getNum() );
    }
    while( !isEmpty(pStack) /*nie pusty stos operanda*/ )
    {
      // sciagnac dwa operandy ze stosu i operator -> przeliczyc
        double a = Dpop(&pDStack);
        //wyliczyc wynik na stos operanda
      Dpush( &pDStack, Eval(Dpop(&pDStack), a, pop(&pStack)) );
    }
    return Dpop(&pDStack); /*szczyt stosu operatora*/;
}
