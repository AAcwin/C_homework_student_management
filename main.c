#include <mysql.h>
#include <stdio.h>
#include<string.h>
#include"model.h"
#include"stu_file.h"
#include"stu_file.c"
#include"global.h"
#include"stu_service.h"
#include"stu_service.c"



int main(){
  // initialize();
  // addStu();
  //  search();
  // sortStu();
  // display();
  // struct students *temp=head;

  // linkMysql();
  // for(int i=0;i<num;i++){
  //   insertToFile(*temp);
  //   temp=temp->next;
  // }
  // closeMysql();

  initialize();
  linkMysql();
  readFromFile(head);
  closeMysql();
  display();
  addStu();
  sortStu();
  display();


 
}