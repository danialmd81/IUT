#include <pthread.h>
#include <stdio.h>

void* runner(void *args){
   int arg = *((int *)args);
   int j = 0;
   
   while(1){
    for (long i=0;i<1000000;i++);
   }
    //printf("runner %d: %d\n", arg, i ); 
  //  if ( arg==1)
  //    j = 100/j;
}

int main(){
  // pthread_t t1,t2;
  int thread_cnt = 8;
  pthread_t t[thread_cnt];
  pthread_attr_t thread_attr;
  pthread_attr_init(&thread_attr);
  int t1_id=1 , t2_id = 2;
  // pthread_create(&t1, &thread_attr, runner,(void*)&t1_id);
  // pthread_create(&t2, &thread_attr, runner,(void*)&t2_id);
  
  // pthread_join(t1,NULL);
  // printf("after first join\n");
  // pthread_join(t2,NULL);
  // printf("End of the main\n");
  for (int i=0; i<thread_cnt; i++)
    pthread_create(&t[i], &thread_attr, runner,(void*)&i);
  for(int i=0;i<thread_cnt;i++)
    pthread_join(t[i],NULL);
  return 0;
}
