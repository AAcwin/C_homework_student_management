#ifndef STU_FILE_H
#define STU_FILE_H

#include <mysql.h>
#include"stu_file.c"

 extern MYSQL *con;
void linkMysql();
void closeMysql();
void insertToFile(struct students stu);
void readFromFile(struct students stu[]);
void initialize();
void AllinsertToFile(struct students *stu);



#endif