#include <iostream>
#include <vector>

using namespace std;

struct rock {
    int left, right;
    float sum;
};

float getINT_MIN();
float maxOf3Floats(float num1, float num2, float num3);
float max3PartedSum(vector<float> &rockRates, int left, int middle, int right, struct rock &rocks);
float maxSubArraySum(vector<float> &rockRates, int left, int right, struct rock &rocks);