#include <stdio.h>
int main(){
    int kor,eng,math,total;
    float avg;
    char grade;

    scanf("%d %d %d",&kor,&eng,&math);
    total=kor+math+eng;
    avg=total/3.0;
    if(90<=avg) grade='A';
    else if(80<=avg) grade='B';
    else if(70<=avg) grade='C';
    else if(60<=avg) grade='D';
    else grade='F';
    printf("%.1f %c\n",avg,grade);
  
    return 0;
}