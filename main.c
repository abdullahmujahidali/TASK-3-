/* Multithreaded C Program Using the Pthread API */
#include<pthread.h>
#include<stdio.h>
#include <stdlib.h>
int sum; /*This data is shared by the thread(s) */
void *runner(void *param); /* the thread */
int main(int argc, char *argv[]) {
 pthread_t tid; /* the thread identifier */
 pthread_attr_t attr; /* set of thread attributes */
 if(argc != 2)
 {
 fprintf(stderr,"usage: a.out <integer value>\n");
 exit(0);
 }
 if(atoi(argv[1]) < 0)
 {
 fprintf(stderr, "%d must be >= 0 \n", atoi(argv[1]));
 exit(0);
 }
/* get the default attributes */
 pthread_attr_init(&attr);
/*create the thread */
 pthread_create(&tid,&attr,runner,argv[1]);
/* Now wait for the thread to exit */
 pthread_join(tid,NULL);
 printf("sum = %d\n",sum);
}
 /*The thread will begin control in this function */
void *runner(void *param){
 int upper = atoi(param);
 int i;
 sum=0;
 if(upper > 0)
 {
 for(i=1; i <= upper;i++)
 sum += i;
 }
 pthread_exit(0);
}

 