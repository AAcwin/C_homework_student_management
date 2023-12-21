#include <mysql.h>
#include <stdio.h>
#include<string.h>
#include"model.h"
#include"stu_file.h"
#include"global.h"
#include"stu_service.h"



int main(){
   initialize();//连接数据库，创建单项链
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
      addStu();//添加数据
      break;  

    case 2:
      display();//遍历数据
      break;

    case 3:
      sortStu();//排序数据
      break;  

    case 4:
      search();//查询数据
      break;

    case 5:
      AllinsertToFile(head);//保存数据
      break;

    case 6:
      readFromFile(head);    //读取数据
      break;  
    
    default:
      printf("\nError enter!enter again:");
      break;

    }
   }
  closeMysql(); //关闭数据库
  return 0;
}