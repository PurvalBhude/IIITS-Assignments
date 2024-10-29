#include<stdio.h>
int main(){
    int ram,shyam,manu;
    printf("ram age: ");
    scanf("%d",&ram);
    printf("shyam age: ");
    scanf("%d",&shyam);
    printf("manu age: ");
    scanf("%d",&manu);

    (ram>shyam && ram<manu)?printf("ram is elder than shyam but younger than manu"):((ram<shyam && ram>manu)?printf("ram is elder than manu but younger than shyam"):((shyam>ram && ram<manu)?printf("shyam is elder than ram but younger than manu"):((shyam<ram && shyam>manu)?printf("shyam is elder than manu but younger than ram"):((manu>ram && manu<shyam)?printf("manu is elder than ram but younger than shyam"):((manu<ram && manu>shyam)?printf("manu is elder than shyam but younger than ram"):printf("there is no comparision between their ages "))))));

}