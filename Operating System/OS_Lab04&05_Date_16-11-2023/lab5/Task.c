#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int ArrSum(int *arrPtr, int size)
{
  int sum = 0;
  int i = 0;
  while (i < size)
  {
    sum += arrPtr[i];
    i++;
  }
  return sum;
}
int ArrMinValue(int *arrPtr, int size)
{
  int min = arrPtr[0];
  int i = 1;
  while (i < size)
  {
    if (min > arrPtr[i])
    {
      min = arrPtr[i];
    }
    i++;
  }
  return min;
}
int main(int argc, char *argv[])
{
  int dataArr[argc - 1];
 
  int fd1[2];
  if (pipe(fd1) == -1)
  {
    perror("Piping 1 failed!!!\n");
  }
  int fd2[2];
  if (pipe(fd2) == -1)
  {
    perror("Piping 2 failed!!!\n");
  }

  pid_t p[2];
  p[0] = fork();
  if (p[0] < 0)
  {
    perror("Fork 1 failed!!!\n");
  }
  else if (p[0] == 0)
  {
    sleep(1);
    int arr[argc - 1];
    close(fd1[1]);
    if (read(fd1[0], arr, sizeof(arr)) < 0)
    {
      perror("Child 1 Reading pipe Failed!");
      exit(-1);
    }
    int sum = ArrSum(arr, argc - 1);
    close(fd2[0]);
    if (write(fd2[1], &sum, sizeof(sum)) < 0)
    {
      perror("Child 1 Writing pipe Failed!");
      exit(-1);
    }
    close(fd2[1]);
    close(fd1[0]);
  }
  else
  {
    int i = 1;
    while (i < argc)
    {
      dataArr[i - 1] = atoi(argv[i]);
      i++;
    }
    close(fd1[0]);
    if (write(fd1[1], dataArr, sizeof(dataArr)) < 0)
    {
      perror("Parent's Writing pipe 1 Failed!");
      exit(-1);
    }
    close(fd1[1]);
    wait(NULL);
    close(fd2[1]);
    int sum = 0;
    if (read(fd2[0], &sum, sizeof(sum)) < 0)
    {
      perror("Parent Reading pipe 1 Failed!");
      exit(-1);
    }
    close(fd2[0]);
    printf("Sum of the array: %d\n", sum);
    ////////////////////////////
    int fd3[2];
    if (pipe(fd3) == -1)
    {
      perror("Piping 3 failed!!!\n");
    }
    int fd4[2];
    if (pipe(fd4) == -1)
    {
      perror("Piping 4 failed!!!\n");
    }
    p[1] = fork();
    if (p[1] < 0)
    {
      perror("Fork 2 failed!!!\n");
    }
    else if (p[1] == 0)
    {
      sleep(1);
      int arr[argc - 1];
      close(fd3[1]);
      if (read(fd3[0], arr, sizeof(arr)) < 0)
      {
        perror("Child 2 Reading from pipe Failed!");
        exit(-1);
      }
      close(fd3[0]);
      int min = ArrMinValue(arr, argc - 1);
      close(fd4[0]);
      if (write(fd4[1], &min, sizeof(min)) < 0)
      {
        perror("Child 1 Writing to pipe 4 Failed!");
        exit(-1);
      }
      close(fd4[1]);
    }
    else
    {
      close(fd3[0]);
      if (write(fd3[1], dataArr, sizeof(dataArr)) < 0)
      {
        perror("Parent Writing to pipe 3 Failed!");
        exit(-1);
      }
      close(fd3[1]);
      wait(NULL);
      close(fd4[1]);
      int min = 0;
      if (read(fd4[0], &min, sizeof(min)) < 0)
      {
        perror("Parent Reading form pipe 4 Failed!");
        exit(-1);
      }
      printf("Min of the array: %d\n", min);
    }
  }
 
  return 0;
}
