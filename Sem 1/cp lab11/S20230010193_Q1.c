#include <stdio.h>

struct student
{
    int rollno;
    char name[100];
    float marks;
};

void updatemarks(struct student *s,float updatedmark){
    printf("\nbefore update mark: %f",s->marks);
    s->marks = updatedmark;
    printf("\nupdated  mark: %f\n",s->marks);
}

void topper(struct student s[],int n){
    int max = s[0].marks;
    for(int i=1;i<n;i++){
        if(max<s[i].marks){
            max = s[i].marks;
        }
    }
    printf("maximum marks: %d",max);
}
int main(){
    struct student s[3];
    for(int i=0;i<3;i++){
        printf("student %d\n",i+1);
        printf("name: ");
        scanf("%s",s[i].name);
        printf("rollno: ");
        scanf(" %d",&s[i].rollno);
        printf("marks:");
        scanf("%f",&s[i].marks);
    }
    printf("printing details\n");
    for(int i=0;i<3;i++){
        printf("student %d\n",i+1);
        printf("name: %s",s[i].name);
        printf("\nrollno: %d",s[i].rollno);
        printf("\nmarks: %f",s[i].marks);
        printf("\n");
    }

    updatemarks(&s[2],79);

    topper(s,3);
}