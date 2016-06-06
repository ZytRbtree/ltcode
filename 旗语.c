#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  key_t key1=ftok("旗语.c",0x1234);
  if(key1==-1)
  {
    perror("ftok key1:");
    exit(-1);
  }

  key_t key2=ftok("旗语.c",0x5678);
  if(key2==-1)
  {
    perror("ftok key2:");
    exit(-1);
  }//得到键值

  int semid1=semget(key1,1,IPC_EXCL|IPC_CREAT);
  if(semid1==-1)
  {
    perror("semid1 get:");
    exit(-1);
  }

  int semid2=semget(key2,1,IPC_EXCL|IPC_CREAT);
  if(semid2==-1)
  {
    perror("semid2 get:");
    exit(-1);
  }//创建旗语变量

  semctl(semid1,0,SETVAL,0);
  semctl(semid2,0,SETVAL,1);//旗语变量初始化

  struct sembuf buf;
  int flag=0;
  pid_t pid=fork();
  if(pid==-1)
  {
    perror("process creat:");
    exit(-1);
  }
  if(pid>0)
  {
    while(1)
    {
      buf.sem_num=0;
      buf.sem_op=-1;
      buf.sem_flg=0;
      semop(semid2,&buf,1);
      if(flag!=15)
      {
        printf("child %d is coming\n",flag);
        flag++;
      }
      else
      {
        break;
      }
      buf.sem_num=0;
      buf.sem_op=+1;
      buf.sem_flg=0;
      semop(semid1,&buf,1);
    }

  }
  if(pid==0)
  {
    while(1)
    {
      buf.sem_num=0;
      buf.sem_op=+1;
      buf.sem_flg=0;
      semop(semid2,&buf,1);
      if(flag!=15)
      {
        printf("parent %d is coming\n",flag);
        flag++;
      }
      else
      {
        break;
      }
      buf.sem_num=0;
      buf.sem_op=-1;
      buf.sem_flg=0;
      semop(semid1,&buf,1);
    }
  }
  semctl(semid1,0,IPC_RMID);
  semctl(semid2,0,IPC_RMID);
  return 0;
}
