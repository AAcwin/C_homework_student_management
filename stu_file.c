#include <mysql.h>
#include <stdio.h>
#include"global.h"
#include"model.h"
#include<string.h>
#include"stu_file.h"

 MYSQL *con;
void linkMysql(){
    con = mysql_init(NULL);
    
   if (!(mysql_real_connect(con, "localhost", "root", "aaaa123", "aa11", 3306, NULL, 0))){

    printf("linking failed\n");}
    else{
        printf("linking success\n");
    }
}

void closeMysql(){
      mysql_close(con);
}

void insertToFile(struct students stu) {   
    char sql1[256] ;
    sprintf(sql1,"insert into players (id, name) values (%d, '%s')",stu.id,stu.name);
    
   
    if (mysql_query(con, sql1) != 0) {
        printf("mysql_query() failed: %s\n", mysql_error(con));
        mysql_close(con);
        return;
    }
 printf("Successfully add student info!\n");
}


 void readFromFile(struct students *stu){
    char *sql="SELECT * FROM players";
    if (mysql_query(con, sql) != 0) {
        printf("select failed: %s\n", mysql_error(con));
        mysql_close(con);
        return;
    }
    MYSQL_RES *res=mysql_store_result(con);
    int num_col=mysql_num_fields(res);
    int num_row=mysql_num_rows(res);
    num=mysql_num_rows(res);
    struct students *temp=stu;
 for(int i=0;i<num_row;i++){
     MYSQL_ROW row=mysql_fetch_row(res);
        temp->id=atoi (row[0]);
        strcpy(temp->name,row[1]);  
        temp=temp->next; 
 }

 mysql_free_result(res);
    
}