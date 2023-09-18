#include<stdio.h>
#include<stdlib.h>

void main() {
    int n, *bt, *pr, *tt, *wt, w = 0, t = 0;
    float aw = 0, at = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    bt = (int*)malloc(n * sizeof(int));
    pr = (int*)malloc(n * sizeof(int));
    tt = (int*)malloc(n * sizeof(int));
    wt = (int*)malloc(n * sizeof(int));
    /* printf("Enter burst time for each process:\n"); */
    for (int i = 0; i < n; i++) {
        printf("Enter (Burst time , priority) of processes %d:",i+1);
        scanf("%d", &bt[i]);
        /* printf("Enter the priority of processes %d:",i+1); */
        scanf("%d", &pr[i]);
		/* Insertion sort */
	    for (int j = i; j > 0; j--){
			if(pr[j] < pr[j-1]){
				pr[j] += pr[j-1];
				pr[j-1] = pr[j] - pr[j-1];
				pr[j] -= pr[j-1];

				bt[j] += bt[j-1];
				bt[j-1] = bt[j] - bt[j-1];
				bt[j] -= bt[j-1];
			}
		}
	}	
	for(int i=0;i<n;i++){
		wt[i] = w;
		tt[i] = t+bt[i];
		w +=  bt[i];
		t += bt[i];
		aw += wt[i];
		at += tt[i];
	}
    printf("bt\tpr\twt\ttt\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", bt[i], pr[i], wt[i], tt[i]);
    }
    printf("Average wt: %f\nAverage tt: %f\n", aw/n, at/n);
    free(bt);
    free(tt);
    free(wt);
}
