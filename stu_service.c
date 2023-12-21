#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"model.h"
#include"global.h"

 

void addStu(){  
    struct students *temp=head;
    char judg;
    int decide=1;
   for(int i=0;i<num;i++){
    temp=temp->next;
   }
   printf("\n*****Add student info*****\n");
   while (decide)
   {
    printf("\nstudent ID:");
   scanf("%d",&temp->id);

    printf("\nname:");
   scanf("%s",&temp->name);

    printf("\ngender[m/f]:");
   scanf(" %c",&temp->gender);

    printf("\nage:");
   scanf("%d",&temp->age);

    printf("\nC score:");
   scanf("%lf",&temp->Cscore);

     printf("\nmath score:");
   scanf("%lf",&temp->Mscore);

     printf("\nEnglish score:");
   scanf("%lf",&temp->Escore);

   printf("\n\nSuccessfully add student info!\n");
   printf("Continue to add student info or not[y/n]:");
   num++;
   temp=temp->next;
while(1){
   scanf(" %c",&judg);
   if(judg=='n'||judg=='N'){
    decide=0;
    break;
   }

   else if(judg=='y'||judg=='Y'){
    decide=1;
    break;
   }

   else
   {
    printf("error input! enter again:\n");
   }
       }
}
}



void display(){
    struct students *temp=head;
    printf("\n**********Display student info**********\n");
    printf("Student ID      Name       Gender       Age     Cscore      MatchScore      EnglishScore\n");
    for(int i=0;i<num;i++){
        printf("%d\t\t%s\t\t%c\t%d\t%lf\t%lf\t%lf\n",temp->id,temp->name,temp->gender,temp->age,
                                                           temp->Cscore,temp->Mscore,temp->Escore);
        
        temp=temp->next;
    }

}
void search(){
    int end=0;
    char targetName[50];
    printf("\n******Search student info******\n");
    printf("Please enter student name you want to search:");
    scanf("%s",&targetName);
    struct students *temp=head;
    printf("\nThe student info is as follows:\n");
    printf("Student ID      Name       Gender       Age     Cscore      MatchScore      EnglishScore\n");
 for(int i=0;i<num;i++){
        if(!strcmp(temp->name,targetName)){
            end=1;
            printf("%d\t\t%s\t\t%c\t%d\t%lf\t%lf\t%lf\n",temp->id,temp->name,temp->gender,temp->age,
                                                                 temp->Cscore,temp->Mscore,temp->Escore);
    
        }
        temp=temp->next; 
    }
    if(end==0){
        printf("**error to search!**\n");
    }
}    

void sortStu(){
    struct students *current;
    struct students *next;
    char temp_str[50];
    int temp_int;
    double temp_d;
    char temp_c;

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

                temp_c=current->gender;
                current->gender=next->gender;
                next->gender=temp_c;

                 temp_int=current->age;
                current->age=next->age;
                next->age=temp_int;

                temp_d=current->Cscore;
                current->Cscore=next->Cscore;
                next->Cscore=temp_d;

                 temp_d=current->Escore;
                current->Escore=next->Escore;
                next->Escore=temp_d;

                 temp_d=current->Mscore;
                current->Mscore=next->Mscore;
                next->Mscore=temp_d;
            }
            current=current->next;
            next=next->next;
        }
    }
    printf("Sorting success!\n");
}
