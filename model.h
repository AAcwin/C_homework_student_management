#ifndef MODEL_H
#define MODEL_H
#include "global.h"


struct students

{
    int id;
    char name[50];
    char gender;
    int age;
    double Cscore;
    double Mscore;
    double Escore;  
    struct students *next;
};

struct students *creatLinked();




#endif