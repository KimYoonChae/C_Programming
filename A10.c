#include <stdio.h>
#include <stdlib.h>
struct bmi_struct{
    char name[20]; //공백없이 알파벳으로 구성
    int height, weight;
    float bmi;
    int bmi_level;
};
void makeDataFile();
int loadDataFile(struct bmi_struct* list[]);
//파라미터 : 채워야 하는 비만도 관리 데이터용 구조체 포인터 배열(list)
//리턴값 : 채워진 구조체 데이터 레코드의 갯수
/*수행내용 : 파일(A10,txt)로부터 키와 몸무게의 데이터를 읽어 list 포인터 배열에 각각 
           메모리를 할당하여 키, 몸무게, 비만도, 비만도 등급이 저장된 구조체 
           데이터가 연결되도록 한 후, 완성한 데이터 갯수를 리턴*/
void bmiResolve(struct bmi_struct* sp);
/*
파라미터) sp: 신장과 체중이 입력되어 있는 구조체 변수의 포인터
수행내용) sp 포인터 내의 신장과 체중을 사용하여 비만도와 비만 등급을 계산하여 넣는다.
리턴값) 없음
*/
void printfBmiData(struct bmi_struct* list[], int size);
//파라미터 : 채워야 하는 비만도 관리 데이터용 구조체 포인터 배열(list), 데이터 개수(size)
//리턴값 : 없음
//수행내용 : list 포인터 배열에 들어있는 각 구조체의 데이터를 출력 형식에 맞추어 화면에 출력함
char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};

int main(){
    struct bmi_struct* people[20]; //최대 20명까지 관리
    int count;
    makeDataFile(); //데이터 파일 제작
    count = loadDataFile(people); //데이터파일로부터 이름, 신장, 체중 데이터 입력받기
    printf("Loaded %d\n",count);
    for(int i=0;i<count;i++)
    {
        bmiResolve(people[i]);
    }
    printfBmiData(people,count);
    return 0;
}
void makeDataFile(){
    char str[] = "James 176 80\n\
    Mary 168 54\n\
    David 187 60\n\
    Jane 155 47\n\
    Wayne 170 75\n\
    Elice 173 80\n\
    Julie 165 50\n\
    Eugene 182 73\n\
    Amy 150 48\n\
    Steve 160 66";

    FILE* fp = fopen("A10.txt", "w");
    fprintf(fp, "%s", str);
    fclose(fp);
}
int loadDataFile(struct bmi_struct* list[]){
    FILE* file = fopen("A10.txt", "r");
    if (!file) {
        printf("파일을 열 수 없습니다.\n");
        return 0;
    }

    int i = 0;
    while (i < 20) {
        list[i] = (struct bmi_struct*)malloc(sizeof(struct bmi_struct)); // 메모리 할당
        if (fscanf(file, "%s %d %d", list[i]->name, &list[i]->height, &list[i]->weight) != 3) {
            free(list[i]); // fscanf 실패 시 메모리 해제
            break;
        }
        i++;
    }

    fclose(file);
    return i; // 읽어온 데이터 개수 반환
}





void bmiResolve(struct bmi_struct* sp){
    sp->bmi=sp->weight/((0.01*sp->height)*(0.01*sp->height));
    if(sp->bmi<18.5) sp->bmi_level = 0;
    else if(sp->bmi<23) sp->bmi_level = 1;
    else if(sp->bmi<25) sp->bmi_level = 2;
    else if(sp->bmi<30) sp->bmi_level = 3;
    else  sp->bmi_level = 4;
}

void printfBmiData(struct bmi_struct* list[], int size){
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};
     for(int i=0;i<size;i++)
  {
      printf("%s %dcm %dkg %.1f %s\n",list[i]->name,list[i]->height,list[i]->weight,list[i]->bmi,bmi_string[list[i]->bmi_level]);
  }  
}