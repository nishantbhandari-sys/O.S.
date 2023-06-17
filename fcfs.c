#include<stdio.h>
#include<stdlib.h>

int getminAT(int at[], int curr, int n){
        int diff = 100, ans;

        if(curr == -1){
                //      get min
                for(int i=0; i < n; i++){
                        if(at[i] < diff){
                                ans = i;
                                diff = at[i];
                        }
                }
        return ans;
        }

        for(int i=0; i < n; i++){
                if(at[i] != 100){

                if( abs(curr - at[i]) < diff ){
                        ans = i;
                        diff = abs(curr - at[i]);
                }
                }
        }
return ans;
}

int main(){

int n, i;
scanf("%d", &n);

int at[n], bt[n], st[n], ct[n], tat[n], wt[n], rt[n];

for(i=0; i < n; i++)
        scanf("%d", &at[i] );

for(i=0; i < n; i++)
        scanf("%d", &bt[i] );

for(i=0; i < n; i++){
        printf("%d  %d\n", at[i], bt[i]);
}


int curr = -1, j = -1, time = 0;

for(i=0; i < n; i++){

        j = getminAT(at, curr, n);
        printf("AT: %d\n", at[j]);

        st[j] = time;
        ct[j] = time = time + bt[j];

        curr = at[j];
        at[j] = 100;
}

for(i=0; i < n; i++){
        printf("A: %d  %d\n", st[i], ct[i]);
}

return 0;
}
