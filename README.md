## 🌐 Language | Idioma

[🇺🇸 English (Default)](#en) | [🇧🇷 Português](#pt)

<div id="en"></div>

---

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

<div id="pt"></div>

---

# Simulador de Escalonamento de Processos \ ***3º Termo - Estruturas de Dados I***

Este projeto implementa uma simulação de um processador multicore com 4 núcleos, desenvolvido em C/C++. O sistema gerencia a execução de tarefas baseadas em filas de prioridade dinâmica, com interface visual em terminal e persistência de dados via arquivo binário.

## Visão Geral

A Aplicação funciona de forma que o processador começe a executar as instruções, e se o usuário desejar, o mesmo pode pausar a execução pressionando a tecla **ESC**, o que vai fazer com que salvemos o estado dos processos em arquivos binários. Podendo assim até mesmo fechar a aplicação e voltar a executar, o que fará com que a aplicação perceba que existe um arquivo de retomada (`instrucoes_retomada.txt`) e continuará a executar as instruções que faltam no ponto que havia parado.

O programa simula a leitura de instruções de um arquivo externo (`instrucoes_do_processador.txt`), distribuindo-as entre 4 núcleos de processamento. Cada tarefa possui um tempo de execução (em Unidades de Tempo - ut) e uma prioridade específica. O sistema gerencia o ciclo de vida dos processos, desde a entrada na fila até a conclusão, permitindo interrupções e retomadas sem perda de dados.

## Funcionalidades Principais

*   **Fila de Prioridade:** As tarefas são ordenadas na fila de execução seguindo a regra de negócio estrita:
    1.  Gravar Dispositivo Interno (Maior Prioridade)
    2.  Gravar Dispositivo Externo
    3.  Deletar
    4.  Ler
    5.  Imprimir (Menor Prioridade)
*   **Interface Visual (TUI):** Interface gráfica baseada em texto (`conio2`) com molduras, barras de progresso e visualização em tempo real das filas e núcleos.
*   **Persistência de Estado:**
    *   Capacidade de interromper a simulação a qualquer momento (tecla ESC ou interação do usuário).
    *   Salvamento automático do estado atual das filas e contadores em arquivo (`instrucoes_retomada.txt`) para posterior continuação.
*   **Relatórios Estatísticos:** Exibição ao final da execução do total de tarefas por processador e por tipo de operação.

## Estrutura do Projeto

### Estruturas de Dados (`TADLISTAPRIORIDADE.h` e `main`) - O arquivo de TAD é usado para definir estruturas auxiliares usadas na aplicação

*   **`Processador`**: Representa um núcleo físico. Contém o ID do processador e ponteiros para sua fila de execução.
    *   `DescProc`: Estrutura para usar a lista com um descritor (que guarda o início e fim da lista).
*   **`Caixa` (Nó da Lista)**: Representa uma instrução/tarefa. Armazena:
    *   `Arquivo`: Nome do arquivo alvo da operação.
    *   `Prioridade`: Nível de prioridade (1 a 5).
    *   `Tempo`: Tempo restante de execução (ut).
    *   `Ponteiros`: Ponteiros **Ant** (Caixa anterior), **Prox** (Próxima caixa).
*   **`ExecucoesEPrioridades`**: Struct auxiliar para contagem estatística de operações (GDI, GDE, DEL, LER, IMP) e carga de trabalho por núcleo.

### Módulos e Funções Principais

*   **Gerenciamento de Execução (`Leitura`, `Retomar`, `EsvaziarFilas`)**:
    *   `Leitura`: Lê o arquivo de entrada, converte comandos textuais em prioridades numéricas e aloca tarefas aos processadores.
    *   `Retomar`: Gerencia a restauração da sessão. Verifica a existência de arquivos de *dump* de memória, recarrega as estatísticas (`ExecucoesEPrioridades`) e reinicia o processamento (`Leitura`) do ponto exato onde parou.
    *   `EsvaziarFilas`: Responsável por salvar o estado atual da memória em disco quando a execução é interrompida.
*   **Interface e UX (`DesenhoExecucao`, `VisualizarFila`, `FormPrincipal`)**:
    *   Responsáveis por desenhar as molduras, atualizar os contadores de tempo na tela e exibir o status das filas de cada núcleo.

## Arquivos de Entrada e Saída

O sistema opera manipulando arquivos de texto para simular o fluxo de dados:

1.  **Entrada:** `instrucoes_do_processador.txt` (Arquivo original com as instruções).
2.  **Persistência:** `instrucoes_retomada.txt` (Gerado ao pausar, contém o estado da fila).
3.  **Logs:** `processos_contadores.txt` (Armazena as estatísticas parciais).


* **Este projeto depende da biblioteca `conio2`. Para compilar e executar:**

---

* **OBS:** Deixarei no repositório uma pasta **Utils** contendo o enunciado do trabalho proposto e um guia de instalação da biblioteca do `conio2`, considerando o `DEV C++` como ambiente.

---

**Desenvolvido por:** Luis Fernando Oliveira Belato & Nicolas Augusto Silva Oliveira
