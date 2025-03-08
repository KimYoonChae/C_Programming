#include <stdio.h>
int main(){
    int height, weight;
    float bmi;
    
    scanf("%d %d",&height,&weight);
    bmi=weight/((height*0.01)*(0.01*height));
    if(bmi>=25.0) printf("%.1f Overweight\n",bmi);
    else printf("%.1f Normal\n",bmi);
}