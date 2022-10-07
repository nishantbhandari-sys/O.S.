
#include<stdio.h>
#include <unistd.h>

// Zombie
//    Parent gets terminated first & child doesn't

int main(){
   printf( "\nNishant Bhandari\n" );
   
   int pid = fork();
   
   if( pid == 0 ){
      
      printf( "\nIn child process---------\npid: %d & ppid: %d\n", getpid(), getppid() );
   }
   else{
   
      sleep( 4 );
      printf( "\nIn Parent process--------\npid: %d\n", getpid());
   }

   return 0;
}





