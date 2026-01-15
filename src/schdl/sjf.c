#include <stdio.h>
#include "process.h"

int main() {
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

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

    print_results(p, n, "SJF Scheduling");
    return 0;
}
