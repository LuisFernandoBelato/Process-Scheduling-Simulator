# Process Scheduling Simulator \ ***3rd Term - Data Structures I***

This project implements a simulation of a 4-core multicore processor, developed in C/C++. The system manages task execution based on dynamic priority queues, featuring a visual terminal interface and data persistence via binary files.

## Overview

The application operates by having the processor start executing instructions. If the user wishes, they can pause execution by pressing the **ESC** key, which triggers the state of the processes to be saved into binary files. This allows the application to be closed and restarted later; the system will detect the presence of a resume file (`instrucoes_retomada.txt`) and continue executing the remaining instructions from the exact point where it stopped.

The program simulates reading instructions from an external file (`instrucoes_do_processador.txt`), distributing them among 4 processing cores. Each task has an execution time (in Time Units - ut) and a specific priority. The system manages the lifecycle of processes, from entry into the queue to completion, allowing for interruptions and resumptions without data loss.

## Key Features

*   **Priority Queue:** Tasks are ordered in the execution queue following a strict business rule:
    1.  Write Internal Device (Highest Priority)
    2.  Write External Device
    3.  Delete
    4.  Read
    5.  Print (Lowest Priority)
*   **Visual Interface (TUI):** Text-based graphical interface (`conio2`) with frames, progress bars, and real-time visualization of queues and cores.
*   **State Persistence:**
    *   Ability to interrupt the simulation at any time (ESC key or user interaction).
    *   Automatic saving of the current state of queues and counters to a file (`instrucoes_retomada.txt`) for later continuation.
*   **Statistical Reports:** Display of total tasks per processor and per operation type at the end of execution.

## Project Structure

### Data Structures (`TADLISTAPRIORIDADE.h` and `main`) - The ADT file is used to define auxiliary structures used in the application

*   **`Processador`**: Represents a physical core. Contains the processor ID and pointers to its execution queue.
    *   `DescProc`: Structure to use the list with a descriptor (which stores the start and end of the list).
*   **`Caixa` (List Node)**: Represents an instruction/task. Stores:
    *   `Arquivo`: Target file name of the operation.
    *   `Prioridade`: Priority level (1 to 5).
    *   `Tempo`: Remaining execution time (ut).
    *   `Ponteiros`: Pointers **Ant** (Previous box), **Prox** (Next box).
*   **`ExecucoesEPrioridades`**: Auxiliary struct for statistical counting of operations (GDI, GDE, DEL, LER, IMP) and workload per core.

### Modules and Main Functions

*   **Execution Management (`Leitura`, `Retomar`, `EsvaziarFilas`)**:
    *   `Leitura`: Reads the input file, converts textual commands into numeric priorities, and allocates tasks to processors.
    *   `Retomar`: Manages session restoration. Checks for the existence of memory *dump* files, reloads statistics (`ExecucoesEPrioridades`), and restarts processing (`Leitura`) from the exact point where it stopped.
    *   `EsvaziarFilas`: Responsible for saving the current memory state to disk when execution is interrupted.
*   **Interface and UX (`DesenhoExecucao`, `VisualizarFila`, `FormPrincipal`)**:
    *   Responsible for drawing frames, updating on-screen time counters, and displaying the queue status of each core.

## Input and Output Files

The system operates by manipulating text files to simulate data flow:

1.  **Input:** `instrucoes_do_processador.txt` (Original file with instructions).
2.  **Persistence:** `instrucoes_retomada.txt` (Generated upon pausing, contains queue state).
3.  **Logs:** `processos_contadores.txt` (Stores partial statistics).


* **This project depends on the `conio2` library. To compile and run:**
  
---

* **NOTE:** I will leave a **Utils** folder in the repository containing the proposed assignment description and an installation guide for the `conio2` library, considering `DEV C++` as the environment.

---

**Developed by:** Luis Fernando Oliveira Belato & Nicolas Augusto Silva Oliveira
