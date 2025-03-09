#include <stdio.h>
//5명의 학생의 총점과 평균점수 출력하기
int main(){
    int jumsu[5][3];
    int total[1][5];
    float ave[1][5];

    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
             scanf("%d",&jumsu[i][j]);
             total[0][i]+=jumsu[i][j];
        }
        ave[0][i]=total[0][i]/3.0;
    }
    printf("\n");
    for(int i=0;i<5;i++){
        printf("%d. %d %.1f\n",i+1,total[0][i],ave[0][i]);
    }
    
    return 0;
}