#ifndef PROCESS_H
#define PROCESS_H

// Definición unificada de la estructura de procesos
typedef struct {
    int id;               // Identificador del proceso
    int arrival_time;     // Tiempo de llegada
    int burst_time;       // Tiempo total de ráfaga
    int remaining_time;   // Tiempo restante (usado en RR)
    int waiting_time;     // Tiempo de espera acumulado
    int turnaround_time;  // Tiempo de retorno (espera + ráfaga)
    int completed;        // Bandera para indicar si terminó (SJF/RR)
} Process;

// Funciones auxiliares de infraestructura
void read_processes(Process p[], int n);
void init_processes(Process p[], int n);
void print_results(Process p[], int n, const char *title);

// ===== DECLARACIONES DE ALGORITMOS (OBLIGATORIAS PARA LOS TESTS) =====
void fcfs_schedule(Process p[], int n);
void sjf_schedule(Process p[], int n);
void rr_schedule(Process p[], int n, int quantum);

#endif
