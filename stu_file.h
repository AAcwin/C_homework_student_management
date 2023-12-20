#ifndef STU_FILE_H
#define STU_FILE_H

#include <mysql.h>

 extern MYSQL *con;
void linkMysql();
void closeMysql();
void insertToFile(struct students stu);
void readFromFile(struct students stu[]);


#endif