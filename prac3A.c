
#include<stdio.h>
#include <unistd.h>

// Orphan Process
//    Child gets terminated first & Parent doesn't
//       so ppid in child is different

int main(){
   printf( "\nNishant Bhandari\n" );
   
   int pid = fork();
   
   if( pid == 0 ){
      
      sleep( 4 );
      printf( "\nIn child process---------\npid: %d & ppid: %d\n", getpid(), getppid() );
   }
   else{

      printf( "\nIn Parent process--------\npid: %d\n", getpid() );
   }

   return 0;
}







