// From: http://www.cs.dartmouth.edu/~campbell/cs50/threads.html
// deadlock00.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void* thr_1(void *ptr) {
  pthread_mutex_lock(&mutex1);
  pthread_mutex_lock(&mutex2);
  printf ("thr 1 - critical section \n");
  pthread_mutex_unlock(&mutex2);
  pthread_mutex_unlock(&mutex1); 
  return NULL;
}

void* thr_2(void *ptr) {
  
  pthread_mutex_lock(&mutex2);
  pthread_mutex_lock(&mutex1);
  printf ("thr 2 - critical section \n");
  pthread_mutex_unlock(&mutex1);
  pthread_mutex_unlock(&mutex2); 
  return NULL;
}

int main() {
  pthread_t t1, t2;
  int tret1 = pthread_create(&t1, NULL, thr_1, NULL);
  int tret2 = pthread_create(&t2, NULL, thr_2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}
