#include <mysql.h>
#include <stdio.h>
#pragma(lib,libmysql)

int main() {
    MYSQL *con = mysql_init(NULL);

  mysql_real_connect(con, "localhost", "root", "aaaa123", "aa11", 3306, NULL, 0);

    char sql1[256] = "insert into players (id, name) values (10086, 'cwin')";

    if (mysql_query(con, sql1) != 0) {
        fprintf(stderr, "mysql_query() failed: %s\n", mysql_error(con));
        mysql_close(con);
        return 1;
    }

    mysql_close(con);

    return 0;
}