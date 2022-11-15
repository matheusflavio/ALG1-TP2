#include <vector>
#include "rock.hpp"

using namespace std;

float INT_MIN = -2147483647;

float maxOf3Floats(float num1, float num2, float num3) {
  float aux = (num1 > num2) ? num1 : num2;
  return (aux > num3) ? aux : num3;
}

rock getMaxRocks(rock leftRocks, rock middleRocks, rock rightRocks) {
  struct rock aux = (leftRocks.sum > middleRocks.sum) ? leftRocks : middleRocks;
  return (aux.sum > rightRocks.sum) ? aux : rightRocks; 
}

rock max3PartedSum(vector<float>rockRates, int left, int middle, int right) {
  float leftSum = INT_MIN, rightSum = INT_MIN, middleSum = INT_MIN, sum = 0;
  int leftIndex = middle, rightIndex = middle;

  /* Construção da soma do array para a partição das esquerda*/
  for(int i = middle; i >= left; i--) {
    sum += rockRates[i];
    if(sum > leftSum) {
      leftSum = sum;
      leftIndex = i;
    }
  }
  sum = 0;
  /* Construção da soma para a partição da direita*/
  for(int i = middle; i <= right; i++) {
    sum += rockRates[i];
    if(sum > rightSum) {
      rightSum = sum;
      rightIndex = i;
    }
  }

  /* Soma da partição correspondente ao vetor completo que correspionde à soma de leftSum + rightSum.
  É feito a subtração de rockRate[middle], por foi somada duas vezes*/
  middleSum = leftSum + rightSum - rockRates[middle];

  float maxSum = maxOf3Floats(leftSum, middleSum, rightSum);

  if(maxSum == leftSum) return { leftIndex, middle, leftSum };
  else if(maxSum == rightSum) return { middle, rightIndex, rightSum };
  return { leftIndex, rightIndex, middleSum };
}

rock maxSubArraySum(vector<float> rockRates, int left, int right) {
  /* Caso em que a entrada dos amigos é depois da saída, o que é impossível*/
  if(left > right) return { left, right, INT_MIN };
  /* Caso em que é passado uma sctruct em que o show de entrada é o mesmo que o de saída.
  Em outras palavras, é o único show a ser assistido*/
  if(left == right) return { left, right, rockRates[left] };

  /* Valor médio para triparticionar o array de shows*/
  int middle = (left + right)/2;

  /* Criação de structs para a partição esquerda, mediana e direita para analisar qual possui
  o subarray de maior soma*/
  struct rock leftRocks = maxSubArraySum(rockRates, left, middle - 1);
  struct rock middleRocks = max3PartedSum(rockRates, left, middle, right);
  struct rock rightRocks = maxSubArraySum(rockRates, middle + 1, right);

  return getMaxRocks(leftRocks, middleRocks, rightRocks);
}