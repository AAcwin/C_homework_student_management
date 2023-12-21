#include <mysql.h>
#include <stdio.h>
#include<string.h>
#include"model.h"
#include"stu_file.h"
#include"global.h"
#include"stu_service.h"



int main(){
   initialize();
   int result=1;
   int choice;
   printf("******************************\n");
   printf("Student Information Management\n");
   printf("******************************\n");


   while (result)
   {
    printf("\n**********Menu**********\n");
    printf("1 Add Student Info\n");
    printf("2 Display Student Info\n");
    printf("3 Sort By Student ID\n");
    printf("4 Search Student Info\n");
    printf("5 Save Student Info\n");
    printf("6 Read Student Info\n");
    printf("0 Exit System\n");
    printf("************************\n");
    printf("Please enter your option<0~6>:");
    choice=0;
    scanf(" %d",&choice);

    switch (choice)
    {
    case 0:
      result =0;
      break;

    case 1:
      addStu();
      break;  

    case 2:
      display();
      break;

    case 3:
      sortStu();
      break;  

    case 4:
      search();
      break;

    case 5:
      AllinsertToFile(head);
      break;

    case 6:
      readFromFile(head);    
      break;  
    
    default:
      printf("\nError enter!enter again:");
      break;

    }
   }
  closeMysql(); 
  return 0;
}