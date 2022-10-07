#include<stdio.h>
#include <unistd.h>

int main(){
   printf( "\nNishant Bhandari\n" );

   fork();
   printf("Process id = %d\n",getpid());

   return 0;
}


