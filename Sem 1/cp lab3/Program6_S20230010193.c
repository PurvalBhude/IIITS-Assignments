#include<stdio.h>
#include<math.h>


void main(){
    //v^2 = 2gs us formula for this question
    int height = 100;
    float velocity = sqrt(2*height*9.8);

    float distance =100;

    // now using for loop calculating velocity and distance after touching to ground 3times

    for(int i = 1; i<4 ; i++){
        velocity = velocity/2;
        printf("for %d time touch velocity is %f\n",i,velocity);
        distance = distance + 2*((velocity*velocity)/19.6);
    }

    printf("total distance covered  after touching the ground 3 times is %f",distance);

}