#ifndef MODEL_H
#define MODEL_H

#include<stdio.h>
#include<stdlib.h>
#include"global.h"

struct students

{
    int id;
    char name[50];
    // char gender;
    // int age;
    // double Cscore;
    // double Mscore;
    // double Escore;  
    struct students *next;
};

struct students *creatLinked(){
    struct students *head;
    struct students *p;
    head=(struct students*)malloc(sizeof(struct students));
    p=(struct students*)malloc(sizeof(struct students));
    head->next=p;
    struct students *temp=head;
    for (int i = 0; i < count; i++)
    {
         p=(struct students*)malloc(sizeof(struct students));
         temp=temp->next;
         temp->next=p;
    }
    p->next=NULL;

    return head;  
}






#endif