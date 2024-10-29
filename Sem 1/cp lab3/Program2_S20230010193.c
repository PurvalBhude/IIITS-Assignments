#include<stdio.h>


void main(){
    //defining Ftemp as temperature in fahreheit
    int Ftemp = 27;
    
    //defining Ctemp as temperature in degree celsius
    float Ctemp = (Ftemp - 32)/1.8;
    
    //printing the converted temperature
    printf("Value of 27 fahreheit in degree celsius is %f",Ctemp);

}
