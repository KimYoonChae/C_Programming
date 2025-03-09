#include <stdio.h>
struct st_jumsu{
    char name[20];
    int jumsu[3];
    int sum;
    float avg;
    char grade;
};
char getGrade(float score);
int main(){
    struct st_jumsu info;
    scanf("%s",info.name);
    info.sum=0;
    for(int i=0;i<3;i++)
    {
        scanf("%d",&info.jumsu[i]);
        info.sum+=info.jumsu[i];
    }
    info.avg=info.sum/3.0;

    printf("%s %d %.1f %c\n",info.name,info.sum,info.avg,getGrade(info.avg));


    return 0;
}

char getGrade(float score){
    if(score>=90) return 'A';
    else if(score>=80) return 'B';
    else if(score>=70) return 'C';
    else if(score>=60) return 'D';
    else return 'F';
}