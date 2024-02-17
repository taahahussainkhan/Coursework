#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* routine(){
    printf("Hello from thread\n");
}
int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,&routine,NULL);
    printf("Hello from main\n");
    pthread_join(tid,NULL);
    return 0;

}