//
//  DStack.h
//  prog3-calc
//
//  Created by Marysia Knapczyk on 16/03/2023.
//

//D CZYLI STOS LICZB

#ifndef DStack_h
#define DStack_h

typedef struct tagDStackItem
{
  //pole key-char pole pNext- wskaznik na sb samego
  double           key;
  tagDStackItem* pNext;
} DStackItem;

DStackItem* createDStack();
void Dpush( DStackItem** pStack, double x ); // wloz na stos
double Dpop(DStackItem** pStack);          // zdejmij i zwroc szczytowy eleme stosu
double Dtop(DStackItem* pStack);          // zwroc szczytowy elem stosu
void Ddel(DStackItem** pStack);         // usun szczytowy (zdejmij)
int isDEmpty(DStackItem* pStack);      // zwraca true jesli stos pusty - else false


#endif /* DStack_h */
