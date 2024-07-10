#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void printFunc(void *ptr)
{
    char name[25]="Afham Nazir";
    char reg[25]="L1F18BSCS0000";
    printf("----------\n");
    printf("Name:           %s\n",name);
    printf("REgestration:   %s\n",reg);
}

int main(int argc, char** argv)
{

    pthread_t thread;
    pthread_create(&thread,NULL,(void*)printFunc,NULL);
    pthread_join(thread,NULL);
    printf("---Thread End---\n");

    return 0;
}