#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_person{
    char name[20];
    int gender; //0:femaile, 1:male
    int country;
    int birthday;
};

void printinfo(struct st_person* p);
//파라미터: 학생 정보 구조체 포인터
//리턴값: 없음
//수행내용: 해당 학생 정보의 내용을 출력한다.
int getCountry(char* str);
//파라미터: 국적을 나타내는 문자열
//리턴값: 국적에 해당되는 인덱스
//수행내용: 국적 문자열에 해당하는 인덱스를 찾는다.
/*
int CountGender(struct st_person* data[], int size, int gender);
//파라미터: 학생 정보 데이터 포인터 배열,데이터 개수, 성별 인덱스
//리턴값: 해당 성별 인원 수
//수행내용: 모든 학생 정보 데이터에서 특정 성별인 인원 수를 구한다.
*/


int main(){
   struct st_person* one;
   char country[5]; //국적 입력을 위한 문자열
   one = (struct st_person*)malloc(sizeof(struct st_person));
   scanf("%s %d %s %d",one->name,&one->gender,country,&one->birthday);
   one->country=getCountry(country);
   printinfo(one);
}
int getCountry(char* str){
    if(strcmp(str,"KR")==0) return 0;
    else if(strcmp(str,"US")==0) return 1;
    else if(strcmp(str,"JP")==0) return 2;
    else if(strcmp(str,"CN")==0) return 3;
    else if(strcmp(str,"FR")==0) return 4;
    else return 5;
}
void printinfo(struct st_person* p){
    char sex[2][10]={"Male","Female"};
    int age;
    printf("%s ",p->name);
    if(p->gender==0) printf("(%s, ",sex[1]);
    else if(p->gender==1) printf("(%s, ",sex[0]);
    printf("age: %d, ",(age=(2025-p->birthday)));
    if(p->country==0) printf("from KR)\n");
    else if(p->country==1) printf("from US)\n");
    else if(p->country==2) printf("from JP)\n");
    else if(p->country==3) printf("from CN)\n");
    else if(p->country==4) printf("from FR)\n");
    else printf("from another)\n");

}