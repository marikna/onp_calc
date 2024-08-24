
#ifndef _STACK_H
#define _STACK_H

// naglowki funkcji publicznych modulu

// BEZ D CZYLI STOS OPERATOROW

typedef struct tagStackItem
{
  //pole key-char pole pNext- wskaznik na sb samego
  char           key;
  tagStackItem* pNext;
} StackItem;

 StackItem* createStack();
 void push( StackItem** pStack, char x ); // wloz na stos, wejsciowo wyjsciowy modyfikacja *
 char pop( StackItem** pStack);          // zdejmij i zwroc szczytowy eleme stosu
 char top( StackItem* pStack );          // zwroc szczytowy element stosu, tylko czyta *
 void del( StackItem** pStack );         // usun szczytowy (zdejmij)
 int isEmpty( StackItem* pStack );      // zwraca true jesli stos pusty - else false

#endif

// wejsciowo wyjsciowe **
// wewnatrz zawartosc komorki wyluskanie *
