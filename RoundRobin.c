#include<stdio.h>
#include<stdlib.h>

void main() {
    int n, *tn, *bt, *tt, *wt, w = 0, t = 0, tq;
    float aw = 0, at = 0;
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    printf("Enter number of processes: ");
    scanf("%d", &n);
    bt = (int*)malloc(n * sizeof(int));
    tn = (int*)malloc(n * sizeof(int));
    tt = (int*)malloc(n * sizeof(int));
    wt = (int*)malloc(n * sizeof(int));
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        tn[i] = bt[i];
    }
    for (int i = 0, cont = 0; cont < n; i = (i + 1) % n) {
        if (tn[i] > 0) {
            if (tn[i] > tq) {
                tn[i] -= tq;
                t += tq;
            } else {
                t += tn[i];
                tn[i] = 0;
                tt[i] = t;
                cont++;
            }
        }
    }
    printf("bt\twt\ttt\n");
    for (int i = 0; i < n; i++) {
        wt[i] = tt[i] - bt[i];
        printf("%d\t%d\t%d\n", bt[i], wt[i], tt[i]);
        aw += wt[i];
        at += tt[i];
    }
    printf("Average wt: %f\nAverage tt: %f\n", aw/n, at/n);
    free(bt);
    free(tn);
    free(tt);
    free(wt);
}