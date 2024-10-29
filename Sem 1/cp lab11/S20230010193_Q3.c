#include <stdio.h>

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

int main(){
    struct contact s[10];
    for(int i=0;i<10;i++){
        printf("contact no %d\n",i+1);
        printf("name: ");
        scanf("%s",s[i].name);
        printf("email: ");
        scanf("%s",s[i].email);
        printf("address\n");
        printf("street: ");
        scanf("%s",s[i].postaladdress.street);
        printf("city: ");
        scanf("%s",s[i].postaladdress.city);
        printf("state: ");
        scanf("%s",s[i].postaladdress.state);
        printf("zipcode: ");
        scanf("%d",&s[i].postaladdress.zipcode);
    }
    printf("enter zipcode to search person: ");
    int zipcode;
    scanf("%d",&zipcode);
    search(s,zipcode);
}