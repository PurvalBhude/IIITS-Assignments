#include <stdio.h>
#include <math.h>
struct coordinate{
    int x;
    int y;
};

void distance(struct coordinate A,struct coordinate B){
    int distance = sqrt(((A.x-B.x)*(A.x-B.x))+((A.y-B.y)*(A.y-B.y)));
    printf("distance between point A and B: %d\n",distance);
}

void midpt(struct coordinate A,struct coordinate B){
    int xmid = (A.x+B.x)/2;
    int ymid = (A.y+B.y)/2;
    printf("midpoint of A and B is (%d,%d)\n",xmid,ymid);
}

void AreaofTriangle(struct coordinate A,struct coordinate B,struct coordinate C){
    int area;
    int pre = (A.x*(B.y-C.y))+(B.x*(A.y-C.y))+(C.x*(A.y-C.y));
    if(pre<0){
        area=(-0.5)*pre;
    }
    else{
        area=(0.5)*pre;
    }
    printf("area of traingle using A B C points: %d",area);
}
int main(){
    struct coordinate A;
    struct coordinate B;
    struct coordinate C;
    printf("enter coodrinate of A\n");
    printf("X: ");
    scanf("%d",&A.x);
    printf("Y: ");
    scanf("%d",&A.y);
    printf("\n");
    printf("enter coodrinate of B\n");
    printf("X: ");
    scanf("%d",&B.x);
    printf("Y: ");
    scanf("%d",&B.y);
    printf("\n");
    printf("enter coodrinate of C\n");
    printf("X: ");
    scanf("%d",&C.x);
    printf("Y: ");
    scanf("%d",&C.y);
    printf("\n");
    distance(A,B);
    midpt(A,B);
    AreaofTriangle(A,B,C);
}