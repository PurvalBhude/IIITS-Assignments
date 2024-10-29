#include <stdio.h>

struct details{
    char name[50];
    int rollno;
    char branch[10];
    int phonenumber;
};

int main(){
    struct details s[10];
    for(int i=0;i<10;i++){
        printf("student %d\n",i+1);
        printf("name: ");
        scanf("%s",s[i].name);
        printf("rollno: ");
        scanf("%d",&s[i].rollno);
        printf("branch: ");
        scanf("%s",s[i].branch);
        printf("contact number: ");
        scanf("%d",&s[i].phonenumber);
        printf("\n");
    }

    for(int i=1;i<10;i=i+2){
        printf("changing branch of student %d\n",i+1);
        printf("branch: ");
        scanf("%s",s[i].branch);
        printf("\n");
    }
}