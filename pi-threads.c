#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

// Array para armazenar resultados de soma calculados nas execuções de calculoPI
double resultados[100];

// Struct com dados de um intervalo
typedef struct {
    int id, inicio, final;
} dadosIntervalo;


// Função para calcular PI executada pelas threads
void *calculoPI(void *arg){
  double soma = 0.0;
  int threadID, termoInicial, termoFinal;

  // Obter dados passados por parâmetros
  dadosIntervalo *data = (dadosIntervalo *)arg;

  // Atribuir valores da variável data a novas variáveis
  threadID = data->id;
  termoInicial = data->inicio;
  termoFinal = data->final;


  // Cálculo da série de Leibniz
  for (;termoInicial <= termoFinal; termoInicial++) {
    // Cálculo do termo
    if (fmod(termoInicial, 2) == 0) {
      soma += 1.0 / (2 * termoInicial + 1);
    } else {
      soma -= 1.0 / (2 * termoInicial + 1);
    }
  }

  // Armazenando valor de soma em uma das posições de resultados
  resultados[threadID] = soma;

  // Encerrar thread
  pthread_exit(NULL);
}


int main(){

  int precisao, tamanhoSerie, termoInicial=0, termoFinal=0, numThreads;
  double soma = 0.0, pi;

  printf("\nInforme a quantidade de termos da série: ");
  scanf("%d", &precisao);
  printf("Informe a quantidade de threads que vai utilizar: ");
  scanf("%d", &numThreads);

  // Definir qual o tamanho de série executado por thread
  tamanhoSerie = precisao/numThreads;

  // Inicializar termoFinal com o tamanho da série
  termoFinal += tamanhoSerie;

  // Criar array de threads
  pthread_t threads[numThreads];

  // Criar array de informações dos intervalos de threads
  dadosIntervalo intervalo[numThreads];

  // Criar quantidade de threads informadas
  for (int i = 0; i < numThreads; i++){
    // Definir informações sobre o intervalo da thread
    intervalo[i].id = i;
    intervalo[i].inicio = termoInicial;
    intervalo[i].final = termoFinal;

    // Criar Thread que execute a função calculoPI
    pthread_create(&threads[i], NULL, calculoPI, (void *)&intervalo[i]);

    // Alterar valores dos termos inicial e final para nova thread
    termoInicial = termoFinal + 1;
    termoFinal += tamanhoSerie;
    if (i == numThreads - 1){
      termoFinal = precisao;
    }

  }

  // Esperar todas as threads finalizarem para que o programa possa seguir
  for (int i = 0; i < numThreads; i++) {
    pthread_join(threads[i], NULL);
  }

  // Unir valores de soma retornados pelas threads em uma única soma
  for (int i = 0; i < numThreads; i++){
    soma += resultados[i];
  }

  // Obter valor de PI
  pi = 4 * soma;

  // Exibição do resultado
  printf("Pi (Fórmula de Leibniz): %.10f\n", pi);

  return 0;
}
