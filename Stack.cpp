#include "Stack.h"  // "" bo moj plik nagl
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

//#define MAXSTACK   10
//
//char Stack[MAXSTACK] = { 0 };
//int nHead = 0; // indeks pierwszego wolnego miesca na stosie


StackItem* createStack()
{
  return NULL;
}

void push(StackItem** pStack, char x ) // wloz na stos
{
  //alokacja pamieci, zrzutowanie
  StackItem* p = (StackItem*)malloc( sizeof( StackItem ) );
  if (!p ) // p==NULL
  {
    perror("push: Allocation Error!\n" ); 
    return;
  }
  memset( p, 0, sizeof( StackItem ) );
  //wstawic info do nowego elementu (ewentualnie wyzerowac wczesniej)
  p->key = x;
  // dowiązać do listy, przewiązać wskaźnik listy na nowy element
  p->pNext = *pStack;
  *pStack = p;
  
}

char pop(StackItem** pStack)          // zdejmij i zwroc szczytowy eleme stosu
{
  if( !isEmpty( *pStack ) )
  {
     char x = top( *pStack );   //wyluskanie bo (stackitem*) w top
     del( pStack );
     return x;
  }
  perror( "Stack underflow1!\n") ;
  return 0;
}

char top(StackItem* pStack)      // zwroc szczytowy elem stosu
{
  if( !isEmpty( pStack ) )
    return pStack->key;     //to samo co (*pStack).key
//cerr << "Stack underflow2!\n";
  return 0;

}

void del(StackItem** pStack)         // usun szczytowy (zdejmij)
{
  if( !isEmpty(*pStack) )
  {
    // "zlapac" pierwszy element listy dodatkowym wskaznikiem
    StackItem* p = *pStack;
    // przewiazac wskaznik listy na kolejny element
    *pStack = p->pNext;
    //zwolnienie pamieci
    free( p );
    return;
  }
  perror( "Stack underflow!\n" );
}

int isEmpty(StackItem* pStack)      // zwraca true jesli stos pusty - else false
{
  return !pStack;
}
