#include <stdio.h>

int main(){
    int jumsu[5][3];
    int total[1][5];
    float ave[1][5];
    char grade[1][5];
    int stotal[3]={0};
    float atotal[3]={0.0};
    char subject[3][20]={"korean","english","math"};

    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
             scanf("%d",&jumsu[i][j]);
             total[0][i]+=jumsu[i][j];
             stotal[j] += jumsu[i][j];  // 과목별 총점 계산
        }
        
        ave[0][i]=total[0][i]/3.0;
    }

    for (int i=0;i<3;i++)
    {
       atotal[i]=stotal[i]/5.0; 
    }
    
    printf("\n");
    for(int i=0;i<5;i++){
        if(ave[0][i]>=90)  grade[0][i]='A';
        else if(ave[0][i]>=80)  grade[0][i]='B';
        else if(ave[0][i]>=70)  grade[0][i]='C';
        else if(ave[0][i]>=60)  grade[0][i]='D';
        else grade[0][i]='F';
        printf("%d. %d %.1f %c\n",i+1,total[0][i],ave[0][i],grade[0][i]);
    }

    for (int i=0;i<3;i++){
        printf("%s %d %.1f\n",subject[i],stotal[i],atotal[i]);
    }
    return 0;
}