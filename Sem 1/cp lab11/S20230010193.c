#include <stdio.h>
#include <math.h>
#include <string.h>

/*
name: Purval Madhukar Bhude
Roll no : S20230010193
subject Cp
Assignment 11 graded assignment 03 (on structures)
*/
//Question1
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

//Question 2
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

//Question 3
struct address{
    char street[20];
    char city[50];
    char state[50];
    int zipcode;
};

struct contact{
    char name[50];
    char email[20];
    struct address postaladdress;
};

void search(struct contact s[],int zipcode){
    int i=0;
    while(i<10){
        if(s[i].postaladdress.zipcode==zipcode){
            break;
        }
        i++;
    }
    printf("name: %s\n",s[i].name);
    printf("email: %s\n",s[i].email);
    printf("address\n");
    printf("street: %s\n",s[i].postaladdress.street);
    printf("city: %s\n",s[i].postaladdress.city);
    printf("state: %s\n",s[i].postaladdress.state);
    printf("zipcode: %d\n",s[i].postaladdress.zipcode);
}

//Question 4
struct details{
    char name[50];
    int rollno;
    char branch[10];
    int phonenumber;
};


//Question 5
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
    //Question 1
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

    //Question 2
    struct time start;
    struct time stop;
    printf("enter start time(hour/min/sec): ");
    scanf("%d %d %d",&start.hour,&start.min,&start.sec);
    printf("enter stop time(hour/min/sec): ");
    scanf("%d %d %d",&stop.hour,&stop.min,&stop.sec);

    difference(start,stop);

    //Question 3
    struct contact q[10];
    for(int i=0;i<10;i++){
        printf("contact no %d\n",i+1);
        printf("name: ");
        scanf("%s",q[i].name);
        printf("email: ");
        scanf("%s",q[i].email);
        printf("address\n");
        printf("street: ");
        scanf("%s",q[i].postaladdress.street);
        printf("city: ");
        scanf("%s",q[i].postaladdress.city);
        printf("state: ");
        scanf("%s",q[i].postaladdress.state);
        printf("zipcode: ");
        scanf("%d",&q[i].postaladdress.zipcode);
    }
    printf("enter zipcode to search person: ");
    int zipcode;
    scanf("%d",&zipcode);
    search(q,zipcode);

    //Question 4
    struct details w[10];
    for(int i=0;i<10;i++){
        printf("student %d\n",i+1);
        printf("name: ");
        scanf("%s",w[i].name);
        printf("rollno: ");
        scanf("%d",&w[i].rollno);
        printf("branch: ");
        scanf("%s",w[i].branch);
        printf("contact number: ");
        scanf("%d",&w[i].phonenumber);
        printf("\n");
    }

    for(int i=1;i<10;i=i+2){
        printf("changing branch of student %d\n",i+1);
        printf("branch: ");
        scanf("%s",w[i].branch);
        printf("\n");
    }

    //Question 5
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