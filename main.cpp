#include <iostream>
#include <vector>
#include "rock.hpp"

using namespace std;

int main() {
  /* Declarando variáveis básicas para a quantidade de pessoas, quantidade de consertos
  e a nota do concerto atual para iterar em um loop*/
  int friendAmount, rockAmount;
  float actualRate;
  
  cin >> friendAmount >> rockAmount;

  /* Loop while que itera enquanto a condição de parada não é atingida.*/
  while(friendAmount != 0 && rockAmount != 0) {
    /* Vetor de ponto flutuante para armazenar a soma atribuída a cada show e struct que 
    armazena os shows de entrada(left) e saída(right) dos amigos, além da soma das notas(sum)*/
    vector<float>rockRates(rockAmount);
    struct rock rocks;

    /*Loop que itera adquirindo a nota de cada amigo para cada show e soma o valor
    atual atribuído pelo amigo atual ao devido show votado*/
    for(int j = 0; j < friendAmount; j++) {
      for(int i = 0; i < rockAmount; i++) {
        cin >> actualRate;
        rockRates[i] += actualRate;
      }
    }

    int left = 0, right = rockAmount - 1;
    rocks = maxSubArraySum(rockRates, left, right);

    /* Impressão na tela dos shows de entrada e saída dos amigos*/
    cout << rocks.left + 1 << " " << rocks.right + 1<< endl;

    cin >> friendAmount >> rockAmount;
  }
  return(0);
}