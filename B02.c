#include <stdio.h>
int main(){
    int kor,eng,math,total;
    float avg;

    scanf("%d %d %d",&kor,&eng,&math);
    total=kor+math+eng;
    avg=total/3.0;
    printf("%d %.1f\n",total,avg);
    if(kor>=90) printf("kor ");
    if(eng>=90) printf("eng ");
    if(math>=90) printf("math");
    printf("\n");
    
    return 0;
}