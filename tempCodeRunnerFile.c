
    int height, weight;
    float bmi;
    
    scanf("%d %d",&height,&weight);
    bmi=weight/((height*0.01)*(0.01*height));
    printf("%.1f",bmi);
    return  0;
}