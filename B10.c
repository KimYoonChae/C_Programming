#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_jumsu {
    char name[20];
    int jumsu[3];
    int sum;
    float avg;
    char grade;
};

char getGrade(float score);
void makeJumsu(struct st_jumsu* p);
int getClassSum(struct st_jumsu* data[], int size, int index);

int main() {
    struct st_jumsu* jdata[20];  // 최대 20명의 점수 데이터
    int sum_class[3];            // 과목별 총점
    float average_class[3];       // 과목별 평균
    char class_name[3][20] = {"Korean", "English", "Math"};
    int count;
    int best_score[3]={0};
    char best_name[3][20];
    int jumsu_count[5]={0};

    scanf("%d", &count);

    // 동적 메모리 할당 및 입력
    /*
    코드에서 malloc()을 사용하여 jdata[i]에 메모리를 할당하는 이유는 구조체 데이터를 저장할 공간을 동적으로 할당하기 위해서입니다.
malloc()을 사용하지 않을 경우 문제점
struct st_jumsu* jdata[20]; 
이 선언은 포인터 배열을 생성하지만, 구조체 자체의 메모리는 할당되지 않음.
jdata[i]는 단순히 포인터일 뿐, 구조체 데이터(name, jumsu[], sum, avg, grade)를 저장할 공간이 없음.
따라서 jdata[i]->name 또는 jdata[i]->jumsu[0] 같은 접근을 시도하면 Segmentation fault(잘못된 메모리 접근)가 발생.

sizeof(struct st_jumsu)만큼 메모리를 할당하여 구조체 데이터를 저장할 공간을 확보.
이제 jdata[i]->name, jdata[i]->jumsu[], jdata[i]->sum 등을 사용할 수 있음.

    */
    for (int i = 0; i < count; i++) {
        jdata[i] = (struct st_jumsu*)malloc(sizeof(struct st_jumsu));
        if (jdata[i] == NULL) {
            printf("메모리 할당 실패!\n");
            return 1;
        }
        scanf("%s", jdata[i]->name);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &jdata[i]->jumsu[j]);  // 공백 제거
        }
    }

    // 각 학생의 점수 처리
    for (int i = 0; i < count; i++) {
        jdata[i]->sum = jdata[i]->jumsu[0] + jdata[i]->jumsu[1] + jdata[i]->jumsu[2];
        if(jdata[i]->jumsu[0]>=best_score[0]) {best_score[0]=(jdata[i]->jumsu[0]); strcpy(best_name[0],jdata[i]->name);}
        if(jdata[i]->jumsu[1]>=best_score[1]) {best_score[1]=(jdata[i]->jumsu[1]);strcpy(best_name[1],jdata[i]->name);}
        if(jdata[i]->jumsu[2]>=best_score[2]) {best_score[2]=(jdata[i]->jumsu[2]);strcpy(best_name[2],jdata[i]->name);}
        jdata[i]->avg = jdata[i]->sum / 3.0;
        jdata[i]->grade = getGrade(jdata[i]->avg);
        makeJumsu(jdata[i]);
    }

    // 과목별 총점 및 평균 계산
    for (int i = 0; i < 3; i++) {
        sum_class[i] = getClassSum(jdata, count, i);
        average_class[i] = sum_class[i] / (float)count;  // 형변환 추가
        printf("%d. %s %d %.1f\n", i+1,class_name[i], sum_class[i], average_class[i]);
    }
    for(int i=0;i<3;i++){
            printf("[%s] %s %d\n",class_name[i],best_name[i],best_score[i]);
        }

    for(int i=0;i<count;i++){
        if(jdata[i]->avg>=90) jumsu_count[0]++;
        else if(jdata[i]->avg>=80) jumsu_count[1]++;
        else if(jdata[i]->avg>=70) jumsu_count[2]++;
        else if(jdata[i]->avg>=60) jumsu_count[3]++;
        else jumsu_count[4]++;
   }
   char grade[5]={'A','B','C','D','F'};
   for(int i=0;i<5;i++){
    printf("[%c] %d\n",grade[i],jumsu_count[i]);
   }
    // 동적 할당 해제
    for (int i = 0; i < count; i++) {
        free(jdata[i]);
    }

  
   

    return 0;
}

char getGrade(float score) {
    if (score >= 90) return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 60) return 'D';
    else return 'F';
}

void makeJumsu(struct st_jumsu* p) {
    printf("%s %d %.1f %c\n", p->name, p->sum, p->avg, p->grade);
}

int getClassSum(struct st_jumsu* data[], int size, int index) {
    int subject_sum = 0;
    for (int i = 0; i < size; i++) {
        subject_sum += data[i]->jumsu[index];
    }
    return subject_sum;
}
