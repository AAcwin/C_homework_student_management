#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"model.h"

 struct students *head;

 void initialize(){
    head=creatLinked();
 }


void addStu(){  
    struct students *temp=head;
    char judg;
   for(int i=0;i<num;i++){
    temp=temp->next;
   }
   while (1)
   {
    printf("id,name:\n");
   scanf("%d%s",&temp->id,&temp->name);
   num++;
   temp=temp->next;
   printf("y/n");scanf(" %c",&judg);
   if (judg=='n')
   {
    break;
   }
   }
}


void display(){
    struct students *temp=head;
    for(int i=0;i<num;i++){
        printf("\n%d %s",temp->id,temp->name);
        temp=temp->next;
    }

}
void search(){
    char targetName[50];
    printf("search name?\n");
    scanf("%s",&targetName);
    struct students *temp=head;
    

    for(int i=0;i<num;i++){
        if(!strcmp(temp->name,targetName)){
            printf("%d %s",temp->id,temp->name);
            break;
        }
        temp=temp->next; 
    }

}    

void sortStu(){
    struct students *current;
    struct students *next;
    char temp_str[50];
    int temp_int;

    for(int i=0;i<num-1;i++){
        current=head;
        next=current->next;
        for (int j = 0; j < num-1-i; j++)
        {
            if (current->id>next->id)
            {
                
               strcpy(temp_str,current->name);
               strcpy(current->name,next->name);
               strcpy(next->name,temp_str);

                temp_int=current->id;
                current->id=next->id;
                next->id=temp_int;

            }
            current=current->next;
            next=next->next;
        }
    }
}
