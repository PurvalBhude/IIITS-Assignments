#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int sumofsquare(int m,int n){
    if(m>n){
        return 0;
    }
    return sumofsquare(m,n-1)+pow(n,2);
}
int gcdusingeucild(int n,int m){
    if(n==0){
        return m;
    }
    if(m==0){
        return n;
    }
    if(m>n){
        return gcdusingeucild(n,m%n);
    }
    else{
        return gcdusingeucild(n%m,m);
    }
}
int power(int n,int m){
    if(m==1){
        return n;
    }
    return power(n,m-1)*n;
}
void permutation(char a[],char b[],int size){

    if (size==strlen(a))
    {
        printf("%s",b);
        return;
    }
    permutation(a,b,size+1);
    permutation(a,b+a[size],size+1);
    
}

bool palindrome_string(char a[],int i,int j){
    if(i==j){
        return true;
    }
    if(a[i]!=a[j]){
        return false;
    }
    if(i<j){
        return palindrome_string(a,i+1,j-1);
    }
    return true;
}
bool palindrome_number(int a,int b,int c){
    if(a==b){
        return true;
    }
    if(c!=0){
        return palindrome_number(a,(b*10)+(c%10),c/10);
    }
    return false;
}

void print1darray(int a[],int size,int i){
    if(size==i){
        return;
    }
    printf("%d ",a[i]);
    print1darray(a,size,i+1);
}
bool primenumber3input(int a,int i,int j){
    if(j==2 && i>a){
        return true;
    }
    if(j>2 && i>a){
        return false;
    }
    if(a%i==0){
        return primenumber3input(a,i+1,j+1);
    }
    else{
        return primenumber3input(a,i+1,j);
    }
    return true;
}
bool primenumber2input(int a, int i){
    while(i < a/2)
    {
        if(a % i == 0)
        {
            return false;
        }
        else{
            return primenumber2input(a, i+1);
        }
    }
    return true;
}
int binarytodecimal(int a,int i){
    if(a==0){
        return 0;
    }
    if(a%10==1){
        return binarytodecimal(a/10,i+1)+pow(2,i);
    }
    return binarytodecimal(a/10,i+1);
}
int findingsumofprimeinnumber(long long int n){
    if(n==0){
        return 0;
    }
    if(n%10==2 || n%10==3 || n%10==5 || n%10==7){
        return findingsumofprimeinnumber(n/10)+(n%10);
    }
    return findingsumofprimeinnumber(n/10);
}

bool find3to1(int n);
void nto1(int n){
    if(n==0){
        return;
    }
    if(find3to1(n)){
        printf("%d  ",n);
    }
    return nto1(n-1);
}
bool find3to1(int n){
    if(n>0){
        if(n%10==3 || n%10==1 || n%10==6 || n%10==9){
            return true;
        }
        find3to1(n/10);
    }
    return false;
}
int main() {
    nto1(20);
    /*if(palindrome_number(121,0,121)){
        printf("it is palindrome");
    }
    else{
        printf("its not palindrome");
    }*/
    /*int n,count;
    scanf("%d",&n);
    int sum=0,i=2;
    while(n>=i){
        if(n%i==0){
            count = 0;
            for(int j=1;j<=i;j++){
                if(i%j==0){
                    count++;
                }
            }
            if(count==2){
                printf("%d ",i);
                n=n/i;
                sum=sum+i;
            }
            else{
                i++;
            }
        }
        else{
            i++;
        }
    }
    printf("\nsum is %d",sum);*/
}