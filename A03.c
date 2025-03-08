#include <stdio.h>
int main(){
    int height, weight,count,overweightcount=0;
    float bmi;
    
    scanf("%d",&count);
    for(int i=0;i<count;i++){
         scanf("%d %d",&height,&weight);
         bmi=weight/((height*0.01)*(0.01*height));
        if(bmi>=25.0) overweightcount++;
    }
    printf("%d명이 비만입니다.\n",overweightcount);
    return 0;
}