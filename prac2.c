
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

   printf( "\nNishant Bhandari\n" );

   int arr[ 6 ] = { 1,2,3,4,5,6 };
   int n = 6, sum ;
   int pid = fork();
   
   if( pid == 0 ){
      sum = 0;
      for( int i = 0; i < n; i ++ )
         if( arr[ i ] %2 == 0 )
            sum += arr[ i ]; 
         
      printf( "\nIn child process---------\nEvenSum: %d, ppid: %d & pid: %d\n", sum, getppid(), getpid() );
   }
   else{
      sum = 0;
      for( int i = 0; i < n; i ++ )
         if( arr[ i ] %2 != 0 )
            sum += arr[ i ];
            
      printf( "\nIn Parent process--------\nOddSum: %d & pid: %d\n", sum, getpid() );
      sleep( 1 ); // So that parent doesn't get terminated first as we have to get ppid from child
   }

   return 0;
}



