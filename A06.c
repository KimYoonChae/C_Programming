#include <stdio.h>
int bmiLevel(int height, int weight);

int main(){
    int height[10], weight[10], bmi_Level[10]={0},overweightcount=0;
    float bmi[10];

    for(int i=0;i<10;i++){
        scanf("%d %d",&height[i],&weight[i]);
        if(bmiLevel(height[i],weight[i])>=3) {
            bmi_Level[i]++;
            overweightcount++;
        }
    }
    for(int i=0;i<10;i++){
        if(bmi_Level[i]==1) printf("%d ",i+1);
        }
    printf("\n");
    printf("%d\n",overweightcount);

    return 0;
}

int bmiLevel(int height, int weight){
    float bmi;
    bmi=weight/((height*0.01)*(0.01*height));
    if(bmi<18.5) return 0;
    else if(bmi<23) return 1;
    else if(bmi<25) return 2;
    else if(bmi<30) return 3;
    else  return 4;
}