#include <stdio.h>
#include <math.h>

int main() {
  double i, n, pi, soma;

  // Número de termos da série
  n = 1000000000;

  // Inicialização da soma
  soma = 0.0;

  // Cálculo da série de Leibniz
  for (i = 0; i <= n; i++) {
    // Cálculo do termo
    if (fmod(i, 2) == 0) {
      soma += 1.0 / (2 * i + 1);
    } else {
      soma -= 1.0 / (2 * i + 1);
    }
  }

  // Multiplicação da soma por 4
  pi = 4 * soma;

  // Exibição do resultado
  printf("Pi (Fórmula de Leibniz): %.10f\n", pi);

  return 0;
}

