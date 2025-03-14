#include <stdio.h>
#include <string.h>

int bmiLevel(int height, int weight);

int main() {
    int height[20], weight[20], bmi_level[20];
    int bmantotalcount = 0, all;
    int bmannumber[20];  
    char bman_string[20][20]; 
    char bmi_string[5][20] = {"Underweight", "Normal weight", "Overweight", "Mild obesity", "Severe obesity"};

    scanf("%d", &all);
    
    int idx = 0; 
    for (int i = 0; i < all; i++) {
        scanf("%d %d", &height[i], &weight[i]);
        bmi_level[i] = bmiLevel(height[i], weight[i]);
        
        if (bmi_level[i] >= 3) {
            bmannumber[idx] = i + 1;  
            strcpy(bman_string[idx], bmi_string[bmi_level[i]]);
            idx++;
        }
    }

    bmantotalcount = idx; 
    for (int i = 0; i < bmantotalcount; i++) {
        printf("%d %s\n", bmannumber[i], bman_string[i]);
    }

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
