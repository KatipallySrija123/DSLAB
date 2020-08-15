#include<stdio.h>
struct student
{
    char name[20];
    int rollno;
    int m1,m2,m3;
    float avg;
    char grade;
};

int main()
{
    struct student s[3];
    for(int i=0;i<3;i++)
    { 
        printf("Enter student name, rollno, marks(3), grade(a/b/c):");
        scanf("%s%d%d%d%d%c",s[i].name,&s[i].rollno,&s[i].m1,&s[i].m2,&s[i].m3,&s[i].grade);
        s[i].avg = (s[i].m1 + s[i].m2 + s[i].m3)/3;
    }
    for(int i=0;i<3;i++)
    {   
        printf("name: %s \n rollno: %d \n avg: %f \n grade: %c \n",s[i].name,s[i].rollno,s[i].avg,s[i].grade);
    }
    return 0;
}