#include <mysql.h>
#include <stdio.h>
#include"global.h"
#include"model.h"
#include<string.h>
#include"stu_file.h"

 MYSQL *con;

void closeMysql(){
      mysql_close(con);
}

void insertToFile(struct students stu) {   
    char sql1[256] ;
    sprintf(sql1,"replace into info1 (id,stu_name,gender,age,Cscore,Matchscore,Englishscore) values (%d,'%s','%c',%d,%lf,%lf,%lf)",
                                        stu.id,stu.name,stu.gender,stu.age,stu.Cscore,stu.Mscore,stu.Escore);
    
   
    if (mysql_query(con, sql1) != 0) {//如果链接失败返回failed
        printf("mysql_query() failed: %s\n", mysql_error(con));
        mysql_close(con);
        return;
    }
 printf("Successfully add student info!\n");
}



void AllinsertToFile(struct students *stu){
    struct students *temp=head;
    for (int i = 0; i < num; i++)
    {
        insertToFile(*temp);
        temp=temp->next;
    }

}


 void readFromFile(struct students *stu){
    char *sql="SELECT * FROM info1";//读取数据库
    if (mysql_query(con, sql) != 0) {
        printf("select failed: %s\n", mysql_error(con));
        mysql_close(con);
        return;
    }
    MYSQL_RES *res=mysql_store_result(con);
    int num_col=mysql_num_fields(res);
    int num_row=mysql_num_rows(res);//获得数据库的行列数
    num=mysql_num_rows(res);
    struct students *temp=stu;
 for(int i=0;i<num_row;i++){//讲数据库的内容传入单链表
     MYSQL_ROW row=mysql_fetch_row(res);
        temp->id=atoi (row[0]);
        strcpy(temp->name,row[1]); 
        temp->gender=row[2][0];
        temp->age=atoi(row[3]);
        temp->Cscore=atof(row[4]);
        temp->Mscore=atof(row[5]);
        temp->Escore=atof(row[6]);
        temp=temp->next; 
 }
 printf("Reading success!\n");
 mysql_free_result(res);   
}

void initialize(){
    head=creatLinked();
    //使用mysql创建数据库：
            //    "CREATE DATABASE IF NOT EXISTS stuInfo;
            //    CREATE TABLE IF NOT EXISTS info1(

            //    id INT UNIQUE,
            //    stu_name VARCHAR(30),
            //    gender VARCHAR(1),
            //    age INT,
            //    Cscore DECIMAL(10,5),
            //    Matchscore DECIMAL(10,5),
            //    Englishscore DECIMAL(10,5)
            //  )"
    con = mysql_init(NULL);
    
   if (!(mysql_real_connect(con, "localhost", "root", "aaaa123", "stuInfo", 3306, NULL, 0))){

    printf("linking failed\n");}
    else{
        printf("linking success!\n\n");
    }
 }