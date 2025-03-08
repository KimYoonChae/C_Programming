#include <stdio.h>
//비만은 총몇명인가?
void makeDataFile();
int bmiLevel(int height, int weight);

int main(){
    int height[10], weight[10], bmi_Level[10]={0},overweightcount=0,all=0;
    float bmi[10];
    makeDataFile();
    FILE*file;
    file=fopen("A07.txt","r");
    int i=0;
    while(!feof(file)){
         fscanf(file,"%d %d",&height[i], &weight[i]);
         i++;
         all++;
    }

  fclose(file);

  for(int i=0;i<all;i++)
  {
      if(3<=bmiLevel(height[i],weight[i])) 
      {
        overweightcount++;
        bmi_Level[i]++;
      }
      printf("Person %d : %d %d\n",i+1,height[i],weight[i]);
  }
    for(int i=0;i<all;i++)
  {
      if(bmi_Level[i]==1) printf("%d ",i+1); 
  }
  printf("\n");
  printf("총 %d명 중에 %d명이 비만입니다.\n",all, overweightcount);
  

    return 0;
}

void makeDataFile(){
    char str[] = "165 56\n\
    176 90\n\
    187 60\n\
    155 47\n\
    170 75\n\
    173 80\n\
    165 50\n\
    182 73\n\
    158 48\n\
    170 66";
    FILE* fp =fopen("A07.txt","w");
    fprintf(fp, "%s", str);
    fclose(fp);
}

int bmiLevel(int height, int weight){
    float bmi;
    bmi=weight/((height*0.01)*(0.01*height));
    if(bmi<18.5) return 0;
    else if(bmi<23) return 1;
    else if(bmi<25) return 2;
    else if(bmi<30) return 3;
    else  return 4;
}