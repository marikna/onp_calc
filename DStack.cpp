//
//  DStack.cpp
//  prog3-calc
//
//  Created by Marysia Knapczyk on 16/03/2023.
//

#include "DStack.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>


DStackItem* createDStack()
{
  return NULL;
}

void Dpush( DStackItem** pDStack, double x ) // wloz na stos
{
  DStackItem* p = (DStackItem*)malloc( sizeof( DStackItem ) );
  if( !p ) {
    perror("push: Allocation Error!\n" );
      return;
  }
  memset( p, 0, sizeof( DStackItem ) );
  p->key = x; 
  p->pNext = *pDStack;
  *pDStack = p;
}

double Dpop(DStackItem** pDStack)          // zdejmij i zwroc szczytowy eleme stosu
{
  if( !isDEmpty( *pDStack ) )
  {
     double x = Dtop( *pDStack );   //wyluskanie bo (stackitem*) w top
     Ddel( pDStack );
     return x;
  }
  perror( "dpop: Stack underflow1!\n") ;
  return 0;
}

double Dtop(DStackItem* pDStack)          // zwroc szczytowy elem stosu
{
  if( !isDEmpty( pDStack ) )
    return pDStack->key;     //to samo co (*pDStack).key
  perror( "dtop: Stack underflow2!\n");
  return 0;

}
void Ddel(DStackItem** pDStack)         // usun szczytowy (zdejmij)
{
  if( !isDEmpty(*pDStack) )
  {
    // "zlapac" pierwszy element listy dodatkowym wskaznikiem
    DStackItem* p = *pDStack;
    // przewiazac wskaznik listy na kolejny element
    *pDStack = p->pNext;
    //zwolnienie pamieci
    free( p );
    return;
  }
  perror( "ddel; Stack underflow!\n" );
}
int isDEmpty(DStackItem* pDStack)      // zwraca true jesli stos pusty - else false
{
  return !pDStack;
}
