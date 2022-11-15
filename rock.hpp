#include <iostream>
#include <vector>

using namespace std;

struct rock {
    int left, right;
    float sum;
};

float maxOf3Floats(float num1, float num2, float num3);
rock getMaxRocks(rock leftRocks, rock middleRocks, rock rightRocks);
rock max3PartedSum(vector<float> rockRates, int left, int middle, int right);
rock maxSubArraySum(vector<float> rockRates, int left, int right);