#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void sjf_schedule(Process p[], int n)
{
    (void)p;
    (void)n;
    /* TODO: Implement SJF scheduling algorithm here */
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

<<<<<<< HEAD
    // TODO: Aquí va la lógica del scheduler
    int time = 0;
    int completed = 0;

    while (completed < n) {
        int idx = -1;
        int min_bt = 1000000;

        for (int i = 0; i < n; i++) {
            if (!p[i].finished && p[i].at <= time) {
                if (p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
        } else {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].finished = 1;
            completed++;
        }
    }
=======
    sjf_schedule(p, n);
>>>>>>> e295d968ed0cea49e0d03f3c31992a399f5359b8

    print_results(p, n, "SJF Scheduling");
    return 0;
}
<<<<<<< HEAD
=======
#endif
>>>>>>> e295d968ed0cea49e0d03f3c31992a399f5359b8
