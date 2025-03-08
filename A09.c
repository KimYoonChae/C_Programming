#include <stdio.h>
struct bmi_struct{
    char name[20]; //공백없이 알파벳으로 구성
    int height, weight;
    float bmi;
    int bmi_level;
};
void bmiResolve(struct bmi_struct* sp);
/*
파라미터) sp: 신장과 체중이 입력되어 있는 구조체 변수의 포인터
수행내용) sp 포인터 내의 신장과 체중을 사용하여 비만도와 비만 등급을 계산하여 넣는다.
리턴값) 없음
*/

int main(){
    struct bmi_struct people;
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};
    scanf("%s %d %d",people.name,&people.height,&people.weight);
    bmiResolve(&people);
    printf("%s, You are %s.",people.name,bmi_string[people.bmi_level]);
    return 0;
}

void bmiResolve(struct bmi_struct* sp){
    sp->bmi=sp->weight/((0.01*sp->height)*(0.01*sp->height));
    if(sp->bmi<18.5) sp->bmi_level = 0;
    else if(sp->bmi<23) sp->bmi_level = 1;
    else if(sp->bmi<25) sp->bmi_level = 2;
    else if(sp->bmi<30) sp->bmi_level = 3;
    else  sp->bmi_level = 4;
}