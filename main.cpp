#include <iostream>
#include <vector>
#include "rock.hpp"

using namespace std;

int main() {
  /* Declarando variáveis básicas para a quantidade de pessoas, quantidade de consertos
  e a nota do concerto atual para iterar em um loop*/
  int friendAmount, rockAmount;
  float actualRate;
  
  /* Leitura dos dados referentes às quantidade de amigos e de shows da entrada padrão*/
  cin >> friendAmount >> rockAmount;

  /* Loop while que itera enquanto a condição de parada não é atingida.*/
  while(friendAmount != 0 && rockAmount != 0) {
    /* Vetor de ponto flutuante para armazenar a soma atribuída a cada show e struct que 
    armazena os shows de entrada(left) e saída(right) dos amigos, além da soma das notas(sum)*/
    vector<float>rockRates(rockAmount, 0);
    Rock *rocks = new Rock();

    /*Loop que itera adquirindo a nota de cada amigo para cada show e soma o valor
    atual atribuído pelo amigo atual ao devido show votado*/
    for(int j = 0; j < friendAmount; j++) {
      for(int i = 0; i < rockAmount; i++) {
        cin >> actualRate;
        rockRates[i] += actualRate;
      }
    }

    /* Definição de variáveis auxiliares que indicam os índices a ser processados e execução da função
    que calcula o subArray de maior soma*/
    int startShow = 0, endShow = rockAmount - 1;
    rocks->maxSubArraySum(rockRates, startShow, endShow);

    /* Loop for utilizado para verificar porque está dando erro no small_input.txt*/
    /*for (auto i : rockRates)
      cout << i << " ";
    cout << endl;*/

    /* Impressão na tela dos shows de entrada e saída dos amigos*/
    cout << rocks->getStartShow() + 1 << " " << rocks->getEndShow() + 1<< endl;

    cin >> friendAmount >> rockAmount;
  }
  return(0);
}