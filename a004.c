#include <stdio.h>
int main(){
    int height[10], weight[10],overweightcount=0;
    float bmi[10];

    for(int i=0;i<10;i++){
         scanf("%d %d",&height[i],&weight[i]);
         bmi[i]=weight[i]/((height[i]*0.01)*(0.01*height[i]));
        if(bmi[i]>=25.0) overweightcount++;
    }

    for(int i=0;i<10;i++){
        if(bmi[i]>=25.0) printf("%d ",i+1);
    }
    printf("\n");
    printf("%d\n",overweightcount);
    return 0;
}