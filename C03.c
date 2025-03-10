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

void CountGender(struct st_person* data[], int size);
//파라미터: 학생 정보 데이터 포인터 배열,데이터 개수, 성별 인덱스
//리턴값: 해당 성별 인원 수
//수행내용: 모든 학생 정보 데이터에서 특정 성별인 인원 수를 구한다.

void CountCountryGenderAge(struct st_person* data[], int size);


int main(){
   struct st_person* pdata[20];
   char country[5]; //국적 입력을 위한 문자열
   int count_gender[2]={0};//성별 인원수
   int count;
   scanf("%d",&count);
   for(int i=0;i<count;i++){
    pdata[i] = (struct st_person*)malloc(sizeof(struct st_person));
    scanf("%s %d %s %d",pdata[i]->name,&pdata[i]->gender,country,&pdata[i]->birthday);
    pdata[i]->country=getCountry(country);
   }

   for(int i=0;i<count;i++){
  
   printf("%d. ",i+1);
   printinfo(pdata[i]);
   }
   CountGender(pdata,count);
   CountCountryGenderAge(pdata,count);
   
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
    if(p->gender==0) {printf("(%s, ",sex[1]);}
    else if(p->gender==1) printf("(%s, ",sex[0]);
    printf("age: %d, ",(age=(2025-p->birthday)));
    if(p->country==0) printf("from KR)\n");
    else if(p->country==1) printf("from US)\n");
    else if(p->country==2) printf("from JP)\n");
    else if(p->country==3) printf("from CN)\n");
    else if(p->country==4) printf("from FR)\n");
    else printf("from another)\n");

}

void CountGender(struct st_person* data[], int size){
    int count_sex[2]={0};
    for(int i=0;i<size;i++){
        if(data[i]->gender==0)  count_sex[1]++;
        else  if(data[i]->gender==1)  count_sex[0]++;
    }
   printf("Male:%d, Female:%d\n",count_sex[0],count_sex[1]);
}

void CountCountryGenderAge(struct st_person* data[], int size){
    int count_sex[2][6]={0};
    int sum_age[6]={0};
    float avg_age[6]={0.0};
    int total_count[6]={0};
    char country[6][10]={"KR","US","JP","CN","FR","--"};
    int age; 
    for(int i=0;i<size;i++){
        age=(2025-data[i]->birthday);
        if(data[i]->country==0){
            if(data[i]->gender==0) count_sex[1][0]++;
            else if(data[i]->gender==1) count_sex[0][0]++;
            total_count[0]=(count_sex[1][0]+count_sex[0][0]);
            sum_age[0]+=age;
        }
        else if(data[i]->country==1){
            if(data[i]->gender==0) count_sex[1][1]++;
            else if(data[i]->gender==1) count_sex[0][1]++;
            total_count[1]=(count_sex[1][1]+count_sex[0][1]);
            sum_age[1]+=age;
        }
        else if(data[i]->country==2){
            if(data[i]->gender==0) count_sex[1][2]++;
            else if(data[i]->gender==1) count_sex[0][2]++;
            total_count[2]=(count_sex[1][2]+count_sex[0][2]);
            sum_age[2]+=age;
        }
        else if(data[i]->country==3){
            if(data[i]->gender==0) count_sex[1][3]++;
            else if(data[i]->gender==1) count_sex[0][3]++;
            total_count[3]=(count_sex[1][3]+count_sex[0][3]);
            sum_age[3]+=age;
        }
        else if(data[i]->country==4){
            if(data[i]->gender==0) count_sex[1][4]++;
            else if(data[i]->gender==1) count_sex[0][4]++;
            total_count[4]=(count_sex[1][4]+count_sex[0][4]);
            sum_age[4]+=age;
        }
        else if(data[i]->country==5){
            if(data[i]->gender==0) count_sex[1][5]++;
            else if(data[i]->gender==1) count_sex[0][5]++;
            total_count[5]=(count_sex[1][5]+count_sex[0][5]);
            sum_age[5]+=age;
        }
    }
    for(int i=0;i<5;i++){
        avg_age[i]=sum_age[i]/total_count[i];
    }

    for(int i=0;i<5;i++){
        printf("[%s] Female: %d, Male: %d, average age: %.1f\n",country[i],count_sex[0][i],count_sex[1][i],avg_age[i]);
    }
    
    }