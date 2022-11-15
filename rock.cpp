#include <vector>
#include "rock.hpp"

using namespace std;

float INT_MIN = -2147483647;

float getINT_MIN() { return INT_MIN; }

Rock::Rock() {
  this->startShow = 0;
  this->endShow = 0;
  this->sum = getINT_MIN();
}

int Rock::getStartShow() {
  return startShow;
}

void Rock::setStartShow(int value) {
  this->startShow = value;
}

int Rock::getEndShow() {
  return endShow;
}

void Rock::setEndShow(int value) {
  this->endShow = value;
}

float Rock::getSum() {
  return sum;
}

void Rock::setSum(float value) {
  this->sum = value;
}

float maxOf3Floats(float num1, float num2, float num3) {
  float aux = (num1 > num2) ? num1 : num2;
  return (aux > num3) ? aux : num3;
}

float Rock::max3PartedSum(vector<float> &rockRates, int startShow, int middle, int endShow) {
  /* Definição de valores auxiliares e bases para execução dos procedimentos*/
  float leftSum = INT_MIN, rightSum = INT_MIN, middleSum = INT_MIN, sum = 0;
  int leftIndex = middle, rightIndex = middle;

  /* Construção da soma do array para a partição das esquerda*/
  for(int i = middle; i >= startShow; i--) {
    sum += rockRates[i];
    if(sum > leftSum) {
      leftSum = sum;
      leftIndex = i;
    }
  }
  sum = 0;
  /* Construção da soma para a partição da direita*/
  for(int i = middle; i <= endShow; i++) {
    sum += rockRates[i];
    if(sum > rightSum) {
      rightSum = sum;
      rightIndex = i;
    }
  }

  /* Soma da partição correspondente ao vetor completo que correspionde à soma de
  leftSum + rightSum. É feito a subtração de rockRate[middle], por foi somada duas vezes*/
  middleSum = leftSum + rightSum - rockRates[middle];

  /* Definição do maior valor da soma dentre as 3 partições*/
  float maxSum = maxOf3Floats(leftSum, middleSum, rightSum);

  /* Atualização dos valores de entrada, saída e a soma correspondente*/
  if(maxSum >=this->getSum() ) {
    this->setStartShow(leftIndex);
    this->setEndShow(rightIndex);
    this->setSum(maxSum);
  }

  return maxSum;
}

float Rock::maxSubArraySum(vector<float> &rockRates, int startShow, int endShow) {
  /* Caso em que a entrada dos amigos é depois da saída, o que é impossível, de modo
  a retornar o valor INT_MIN como soma para essa situação impossível*/
  if(startShow > endShow) {
    return INT_MIN;
  }
 
  /* Valor médio para triparticionar o array de shows a fim de realizar a comparação
  das somas das notas dos intervalos*/
  int middle = (startShow + endShow)/2;

  /* Criação de structs para a partição esquerda, mediana e direita para analisar
  qual possui o subarray de maior soma*/
  float leftRocks = maxSubArraySum(rockRates, startShow, middle - 1);
  float middleRocks = max3PartedSum(rockRates, startShow, middle, endShow);
  float rightRocks = maxSubArraySum(rockRates, middle + 1, endShow);

  /* Definição do valor máximo da soma para o subproblema atual*/
  float maxValue = maxOf3Floats(leftRocks, middleRocks, rightRocks);

  return maxValue;
}