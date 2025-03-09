#include <stdio.h>
int main(){
    int kor,eng,math,total;
    float avg;

    scanf("%d %d %d",&kor,&eng,&math);
    total=kor+math+eng;
    avg=total/3.0;
    printf("%d %.1f",total,avg);
    
    return 0;
}