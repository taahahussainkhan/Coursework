#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* random(){
    int a = rand() % 10;
    int* res = malloc(sizeof(int));
    *res = a;
    return (void*)res;
}
int main(){
    pthread_t tid;
    int* result;
    pthread_create(&tid,NULL,&random,NULL);
    pthread_join(tid,(void**)&result);
    printf("Random number: %d\n",*result);
    free(result);
    return 0;
}