#include <stdio.h>

struct time{
    int hour;
    int min;
    int sec;
};

int converttosec(struct time a){
    int ans = (a.hour*60*60)+(a.min*60)+(a.sec);
    return ans;
}

void converttonormal(int ans){
    int hour = ans/(60*60);
    int min = (ans - (hour*(60*60)))/60;
    int sec = ans - ((hour*(60*60))+(min*60));
    printf("difference is (hour/min/sec): %d %d %d",hour,min,sec);
}
void difference(struct time a,struct time b){
    int A = converttosec(a);
    int B = converttosec(b);
    int ans;
    if(A>B){
        ans = A-B;
    }
    else{
        ans = B-A;
    }
    converttonormal(ans);
}
int main(){
    struct time start;
    struct time stop;
    printf("enter start time(hour/min/sec): ");
    scanf("%d %d %d",&start.hour,&start.min,&start.sec);
    printf("enter stop time(hour/min/sec): ");
    scanf("%d %d %d",&stop.hour,&stop.min,&stop.sec);

    difference(start,stop);
}