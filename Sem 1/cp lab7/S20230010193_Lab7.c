#include<stdio.h>
#include<math.h>
int main(){
    
}

int GCD_TwoNum(int a,int b){
    if(a>b){
        for(int i=b;i>0;i--){
            if(a%i==0 && b%i==0){
                return i;
            }
        }
    }
    else{
        for(int i=a;i>0;i--){
            if(a%i==0 && b%i==0){
                return i;
            }
        }
    }
}

void GCD_FourNum_Q1(int a,int b,int c,int d){
    int gcdab = GCD_TwoNum(a,b);
    int gcdcd = GCD_TwoNum(c,d);
    int ans = GCD_TwoNum(gcdab,gcdcd);
    printf("GCD of this number: %d",ans);
}

void armstrong_Q2(int n){
    int sum = 0;
    int a = n;
    int b = n;
    int j = 0;
    while (a > 0) {
        a /= 10;
        j++;
    }
    while (n > 0) {
        int k = n % 10;
        sum += pow(k,j);
        n /= 10;
    }
    if(b==sum){
        printf("it is armstrong number");
    }
    else{
        printf("it is not armstrong number");
    }
}

void Palindrome_Q3(char str[],int n){
    for(int i=0;i<n;i++){
        if(str[i]!=str[n-i-1]){
            printf("It is not palindrome");
            return;
            break;
        }
    }
    printf("it is palindrome");
    return;
}

int isPerfect(int n) {
    int sum = 1;
    for (int i=2;i*i<=n;i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum = sum + (n/i);
            }
        }
    }
    return (sum == n);
}
int sumPerfect_Q4(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isPerfect(arr[i])) {
            sum = sum + arr[i];
        }
    }
    printf("Sum of Perfect Number: %d",sum);
    return 0;
}

int ClosestNumber_Q5(int arr[],int n,int a) {
    int c= arr[0];
    int m= abs(arr[0]-a);
    for (int i=1;i<n;i++) {
        int d=arr[i] -a;
        if (d<0) {
            d=-d;
        }
        if (d<m) {
            m=d;
            c= arr[i];
        }
    }
    printf("closest number: %d",c);
    return 0;
}


int kth_Q6(int arr[], int n, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    printf("Kth smallest number in array: %d", arr[k - 1]);
}


void factors_Q7(){
    int a;
    printf("Enter Number:");
    scanf("%d",&a);
    printf("Factors :");
    for(int i=1;i<=a;i++){
        if(a%i==0){
            printf("%d ",i);
        }
    }
}

int isPrime(int n) {
    int count = 0;
    for (int i = 2; i<n; i++) {
    if (n % i == 0) {
      count++;
    }
    }
    if(count==0)
        return 1;
    else
        return 0;
}

void sumofprime_Q8(int n) {
  for (int i = 2; i <= n / 2; i++) {
    if (isPrime(i) && isPrime(n - i)) {
        printf("It can Be represented in sum of prime\n");
        printf("%d + %d = %d",i,n-i,n);
        return 1;
    }
  }
  printf("IT can not be represented in sum of prime");
  return 0;
}

void SumofEven_Q9(int n){
    int sum=0;
    while(n>0){
        int i = n%10;
        if(i%2==0){
            sum = sum + i;
        }
        n=n/10;
    }
    printf("sum of even digit in number:%d",sum);
}

void countQ10(char string[]){
    int vowels = 0;
    int consonants = 0;
    int symbols = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' ||string[i] == 'o' || string[i] == 'u' || string[i] == 'A' ||string[i] == 'E' || string[i] == 'I' || string[i] == 'O' ||string[i] == 'U') {
            vowels++;
        }
        else if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) {
            consonants++;
        }
        else {
            symbols++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Symbols: %d\n", symbols);
}

void reverse_Q11(char str[],int k){
    for(int i=0;i<k/2;i++){
        str[i] = (str[i]^str[k-i-1]);
        str[k-i-1] = (str[i]^str[k-i-1]);
        str[i] = (str[i]^str[k-i-1]);
    }
    printf("The reverse character array is %s",str);
}
