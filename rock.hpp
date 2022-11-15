#include <iostream>
#include <vector>

using namespace std;

class Rock {
    private:
        /* Inteiro que registra o índice do show de entrada dos amigos para o evento*/
        int startShow;
        /* Inteiro que registra o índice do show de sáida dos amigos para o evento*/
        int endShow;
        /* Ponto flutuante para armazenar a soma das notas correspondente ao intervalo definido por startShow e endShow*/
        float sum;

    public:
        /* Fução de inicialização da classe com valores predefinidos considerando que os amigos não irão a nenhum jogo e é dada uma nota extremamente baixa para quesito de futuras comparações mediante a execução dos procedimentos*/
        Rock();

        /* Função que retorna o valor armazenado como show de entrada dos amigos no festival*/
        int getStartShow();

        /* Função que seta o atributo startShow = value*/
        void setStartShow(int value);

        /* Função que retorna o valor armazenado como show de saída dos amigos do festival*/
        int getEndShow();

        /* Função que seta o atributo endShow = value*/
        void setEndShow(int value);

        /* Função que retorna o valor atual da soma dos shows dos intervalos entre startShow e endShow*/
        float getSum();

        /* Função que retorna o valor da soma das notas dos shows entre startShow e endShow*/
        void setSum(float value);

        /* Função realmente responsável por resolver o problema mediante a divisão e conquista, sempre executação os passos basses a partir do momento em que é atingido um vetor simples. Considera 3 vetores para as comparações*/
        float max3PartedSum(vector<float> &rockRates, int startShow, int middle, int endShow);

        /* Função responsável por dividir o vetor em 3 partes quando necessário utilizando a função max3PartedSum e retornar o resultado final da maior soma das notas dos shows, embora esse valor não seja realmente utilizado, mas serve como parâmetro de comparação*/
        float maxSubArraySum(vector<float> &rockRates, int startShow, int endShow);
};

/* Função que retorna o valor definido como mínimo para atribuição inicial e em casos específicos*/
float getINT_MIN();

/* Função que retorna o valor máximo dentre 3 inputs de entrada do tipo float*/
float maxOf3Floats(float num1, float num2, float num3);