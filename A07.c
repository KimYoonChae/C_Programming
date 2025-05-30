#include <stdio.h>

int bmiLevel(int height, int weight);

int main() {
    int height[20], weight[20], bmi_level[20];
    int count = 0, all;

    scanf("%d", &all);
    for (int i = 0; i < all; i++) {
        scanf("%d %d", &height[i], &weight[i]);
        bmi_level[i] = bmiLevel(height[i], weight[i]);
        if (bmi_level[i] >= 3) count++;
    }

    printf("%d/%d", count, all);
    return 0;
}

int bmiLevel(int height, int weight) {
    float bmi = weight / ((height * 0.01) * (height * 0.01));
    if (bmi < 18.5) return 0;
    else if (bmi < 23) return 1;
    else if (bmi < 25) return 2;
    else if (bmi < 30) return 3;
    else return 4;
}
