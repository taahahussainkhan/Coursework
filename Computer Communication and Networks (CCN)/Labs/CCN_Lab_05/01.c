#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
struct ThreadArgs {
    char *name;
    int reg_number;
};

void *printInfo(void *args) {
    struct ThreadArgs *info = (struct ThreadArgs *)args;
    printf("Name: %s\nRegistration Number: %d\n", info->name, info->reg_number);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid; 
    struct ThreadArgs args; 
    
    args.name = "Taaha Hussain Khan";
    args.reg_number = 917; 
    
    if (pthread_create(&tid, NULL, printInfo, (void *)&args) != 0) {
        fprintf(stderr, "Failed to create thread\n");
        return 1;
    }
    
    if (pthread_join(tid, NULL) != 0) {
        fprintf(stderr, "Failed to join thread\n");
        return 1;
    }
    
    return 0;
}
