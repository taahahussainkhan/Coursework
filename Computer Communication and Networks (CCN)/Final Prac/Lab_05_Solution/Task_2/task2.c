#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
struct Student
{
    char *name;
    char *reg;
};

void *printFunc(void *ptr)
{
    struct Student *stu;//
    stu=(struct Studentinfo *)ptr;//
    printf("Name:           %s\n",stu->name);
    printf("REgestration:   %s\n",stu->reg);
}
int main(int argc, char** argv)
{

    pthread_t thread;
    struct Student stu;
    stu.name=argv[2];;
    stu.reg=argv[3];
    pthread_create(&thread,NULL,(void*)printFunc,(void*)&stu);
    pthread_join(thread,NULL);
    printf("---Thread End---\n");

    return 0;
}
