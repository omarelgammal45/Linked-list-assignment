#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[25];
    int ID;
    int birth_day;
    int birth_month;
    int birth_year;
    int score;
    struct student* ptr;
};

int main()
{
    printf("Hello !\n");
    return 0;
}
