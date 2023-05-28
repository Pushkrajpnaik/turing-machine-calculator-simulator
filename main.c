#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#include "doublelinkedlist.h"
#include <time.h>

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}
DoubleLinkedList t(int c[])
{   DoubleLinkedList d = newDoubleLinkedList(d,-1);
    for (int i = 0; i < 10; i++)
{
    d = insertEndDoubleLinkedList(d, -1);
}

for (int i = 0; i < 10; i++)
{
    d = insertEndDoubleLinkedList(d, c[i]);
}
for (int i = 0; i < 10; i++)
{
    d = insertEndDoubleLinkedList(d, -1);
}
    return d;
}

typedef struct state{
    int state;
    struct state* self;
    struct state* next;
}State;

int main()
{
    State* ss = (State*)malloc(sizeof(State));
    ss->self = ss;
    ss->state = 0;
     ss->next = (State*)malloc(sizeof(State));
     ss->next->self = ss->next;
     ss->next->state = 1;
     
     ss->next->next = (State*)malloc(sizeof(State));
     ss->next->next->self = ss->next->next;
      ss->next->next->state = 2;
      ss->next->next->next = NULL;

    int a[10] = {1,1,1,1,1,1,1,1,1,1};
    DoubleLinkedList tape = t(a);
    Node* pointer = tape.head;
    State* s = ss;
    Node* ptr = tape.head;
    printf("\n");
    for (int i = 0; i < 30; i++)
    {
        printf("%i",ptr->data );
        ptr = ptr->next;
    }
    while (pointer->data== -1 )
    {
        pointer = pointer->next;
    }
    while (s->state != 2)
    {   // 1/1,R   0->0
        if (s->state == 0 && pointer->data == 1)
        {                            waitFor(1);
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 1;
                          //  waitFor(1);
  //  displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;


    
        }
        // 0/0,R   0->0
       else if (s->state == 0 && pointer->data == 0)
        {                            waitFor(1);
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 0;
                           // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        }
        // b/b,l  0->1
        else if (s->state == 0 && pointer->data == -1)
        {                            waitFor(1);
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = -1;
                           // waitFor(1);
   // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        }
        // 1/0,L  1->1
     else   if (s->state == 1 && pointer->data == 1)
        {                            waitFor(1);
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 0;
                            waitFor(1);
    displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }
        // b/1,n   1->2
      else  if (s->state == 1 && pointer->data == -1)
        {                            waitFor(1);
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 1;
                           waitFor(1);
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
           // pointer = pointer->next;

        }
        // 0/1,n  1->2
     else   if (s->state == 1 && pointer->data == 0)
        {                            waitFor(1);
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 1;
                            waitFor(1);
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            //pointer = pointer->next;

        }
        
    }
    
    //  Node* ptr2= tape.head;
    //  printf("\n");
    // for (int i = 0; i < 30; i++)
    // {
    //     printf("%i",ptr2->data );
    //     ptr2 = ptr2->next;
    // }
    // waitFor(1);
    // displayDoubleLinkekdList(tape, pointer);

    return 0;
}