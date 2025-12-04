# Simuladore de Escalonamento de Processos \ ***3º Termo - Estruturas de Dados I***

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

**Desenvolvido por:** Luis Fernando Oliveira Belato & Nicolas Augusto Silva Oliveira
