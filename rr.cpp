#include<iostream>
#include<queue>
using namespace std;

int getminAT(int at[], int n){
    int diff = 100, ans = 0;
        
                //      get min
                for(int i=0; i < n; i++){
                        if(at[i] < diff){
                                ans = i;
                                diff = at[i];
                        }
                }
        return ans;
}

int main(){

int n, i, z = 0, tq = 2;
queue<int> q;
scanf("%d", &n);

int at[n], bt[n], st[n], ct[n], tat[n], wt[n], rt[n];

for(i=0; i < n; i++)
        scanf("%d", &at[i] );

for(i=0; i < n; i++)
        scanf("%d", &bt[i] );

for(i=0; i < n; i++){
        printf("%d  %d\n", at[i], bt[i]);
}

for(i=0; i < n; i++){
        st[i] = -1;
        // printf("%d", )
}


int curr = -1, j = -1, time = 0;
j = getminAT(at, n);
q.push(j);
at[j] = 100;

while(z < n){

        j = q.front();
        q.pop();
     printf("AT: %d\n", j+1);

        if(st[j] == -1)
                st[j] = time;

        int m = min(tq, bt[j]);
        ct[j] = time = time + m;

        for(i = 0; i < n; i++ ){
                //      all process having at < time goto queue
                if(at[i] != 100 && at[i] <= time){
                        q.push(i);
                        at[i] = 100;
                }
        }

        if(bt[j] <= tq){
                z++;
        }
        else{
                q.push(j);
        }

        bt[j] -= m;

}

for(i=0; i < n; i++){
        printf("A: %d  %d\n", st[i], ct[i]);
}

return 0;
}

/*
4              
0
1
2
4
5
4
2
1
*/
