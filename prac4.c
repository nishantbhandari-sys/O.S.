#include <stdio.h>
#include <stdlib.h>

/*

5 4
2 3
0 1
10 5
5 2

4 6
2 4
6 7
0 2
1 3

*/
typedef struct Process{
	
	int id;
	float bt;
	float at;
	float st;
	float ct;
	float rt;
	float tat;
	float wt;
} Process;

int comp_arr( const void *p1, const void *p2 ){

	int a1 = ((const Process*)p1) -> at;
	int a2 = ((const Process*)p2) -> at;

	//	Acc. to arrival time
	if( a1 < a2 )
		return 0;

	//	Sort acc. to ID's
	else if( a1 == a2 )
		if( ((const Process*)p1) -> id < ((const Process*)p2) -> id )
			return 0;

	return 1;
}

int comp_ids( const void *p1, const void *p2 ){

	int id1 = ((const Process*)p1) -> id;
	int id2 = ((const Process*)p2) -> id;

	//	Sort acc. to ID's
	if( id1 < id2 )
		return 0;

	return 1;
}

void sort( Process pcs[], int nop ){
	//	Sorts structure acc. to A.T

	qsort( (void*) pcs, nop, sizeof( pcs[ 0 ] ), comp_arr );
}

void make_table( Process pcs[], int nop, float avg[] ){

	float prev_time = 0;
	for (int i = 0; i < nop; ++i){

		//	ith process has not arrived
		//	Cpu's Idle time
		prev_time =(prev_time < pcs[ i ].at)? pcs[ i ].at: prev_time;

		pcs[ i ].st = prev_time;
		pcs[ i ].ct = prev_time + pcs[ i ].bt;
		prev_time = pcs[ i ].ct;

		pcs[ i ].rt = pcs[ i ].st - pcs[ i ].at;
		pcs[ i ].tat = pcs[ i ].ct - pcs[ i ].at;
		pcs[ i ].wt = pcs[ i ].tat - pcs[ i ].bt;

		avg[ 0 ] += pcs[ i ].rt;	//	Sum. R.T
		avg[ 1 ] += pcs[ i ].tat;	//	Sum. T.A.T
		avg[ 2 ] += pcs[ i ].wt;	//	Sum. W.T
		avg[ 3 ] += pcs[ i ].bt;	//	Sum. B.T
	}

	avg[ 0 ] /= nop;
	avg[ 1 ] /= nop;
	avg[ 2 ] /= nop;
	avg[ 4 ] = prev_time;	//	time when last process ended
}

void print_table( Process pcs[], int nop, float avg[] ){

	//	Sort Acc. to Id's
	// qsort( (void*) pcs, nop, sizeof( pcs[ 0 ] ), comp_ids );

	printf( "\n%-9s%-8s%-9s%-8s%-9s%-8s%-9s%-9s\n", "I.D","A.T","B.T","S.T","C.T","R.T","T.A.T","W.T" );
	printf("----------------------------------------------------------------\n");
	for (int i = 0; i < nop; ++i){

		printf("%-8d %-8.1f", 	pcs[ i ].id,  pcs[ i ].at );
		printf("%-8.1f %-8.1f", pcs[ i ].bt,  pcs[ i ].st );
		printf("%-8.1f %-8.1f", pcs[ i ].ct,  pcs[ i ].rt );
		printf("%-8.1f %-8.1f\n", pcs[ i ].tat, pcs[ i ].wt );
	}

	printf("\nAverage R.T: %.1f", avg[ 0 ] );
	printf("\nAverage T.A.T: %.1f", avg[ 1 ] );
	printf("\nAverage W.T: %.1f", avg[ 2 ] );
	printf("\nThroughPut: %.1f", nop / avg[ 4 ] );
	printf("\nCPU Utilization( %% ): %.1f\n\n\n", avg[ 3 ] / avg[ 4 ] *100 );
}

int main(int argc, char const *argv[]){
	printf( "\nNishant Bhandari\n" );

	int nop = 5;
	Process pcs[ nop ];

	//	Assign ID's to Processes
	//	Read A.T & B.T
	printf("Enter Arrival Time & Burst Time.........\n" );
	for (int i = 0; i < nop; ++i){
		scanf( "%f %f", &pcs[ i ].at, &pcs[ i ].bt );

		pcs[ i ].id = i +1;
		pcs[ i ].st = 0.0;
		pcs[ i ].ct = 0.0;
		pcs[ i ].rt = 0.0;
		pcs[ i ].tat = 0.0;
		pcs[ i ].wt = 0.0;
	}
	

	float avg[ 5 ] = { 0.0, 0.0, 0.0, 0.0, 0.0 };

	sort( pcs, nop );
	// print_table( pcs, nop, avg );

	make_table( pcs, nop, avg );

	print_table( pcs, nop, avg );

	return 0;
}










