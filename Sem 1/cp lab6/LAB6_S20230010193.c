#include<stdio.h>

int main(){
    //Q1
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    int rev = 0;
    int new_n = n;
    while(n!=0){
        int k = n%10;
        rev = (rev*10)+k;
        n=n/10;
    }
    if(new_n==rev){
        printf("Number is Palindrome");
    }
    else{
        printf("Number is not Palindrome");
    }

    //Q2
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    printf("Factors: ");
    for(int i=1;i<=n;i++){
        if(n%i==0){
            printf("%d ",i);
        }
    }

    //Q3
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    printf("Factorial: ");
    int factorial = 1;
    for(int i=2;i<=n;i++){
        factorial = factorial*i;
    }
    printf("%d",factorial);

    //Q4
    int n1;
    printf("Enter Number1: ");
    scanf("%d",&n1);
    int n2;
    printf("Enter Number2: ");
    scanf("%d",&n2);
    printf("GCD: ");

    if(n1>n2){
        for(int i=n2;i>0;i--){
        if(n1%i==0&&n2%i==0){
            printf("%d",i);
            break;
        }
    }
    }
    else{
        for(int i=n1;i>0;i--){
        if(n1%i==0&&n2%i==0){
            printf("%d",i);
            break;
        }
    }
    }

    //Q5
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    printf("Prime Number: ");
    int i =2;
    while(i<=n){
        int count = 0;
        int j=2;
        while(j<i){
            if(i%j==0){
                count++;
            }
            j++;
        }
        if(count == 0){
            printf("%d ",i);
        }
        i++;
    }

    //Q6
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    int sum,term1,term2;
    term1=0;
    term2=1;
    printf("Fibonacci series: %d %d ",term1,term2);
    int i=3;
    while(i<=n){
        sum = term1+term2;
        term1=term2;
        term2=sum;
        printf("%d ",sum);
        i++;
    }

    //Q7
    int n;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int odd = 0;
    int even = 0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    printf("Number of Odd: %d",odd);
    printf("\n");
    printf("Number of Even: %d",even);

    //Q8
    int a1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    printf("Matrix1: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",a1[i][j]);
        }
        printf("\n");
    }
    int a2[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    printf("Matrix2: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",a2[i][j]);
        }
        printf("\n");
    }
    int ans[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans[i][j] = (a1[i][0]*a2[0][j])+(a1[i][1]*a2[1][j])+(a1[i][2]*a2[2][j]);
        }
    }
    printf("\n");
    printf("Answer matrix:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }

    //Q9
    char str[] = "Purval Madhukar Bhude";
    printf("String: ");
    printf("%s",str);
    printf("\n");
    int i=1;
    while(str[i]!='\0'){
        i++;
    }
    printf("using loop string size: %d\n",i);
    printf("using string.h library string size: %d",strlen(str));

    //Q10
    char str1[] = "Purval Madhukar Bhude";
    printf("String1: ");
    printf("%s",str1);
    printf("\n");
    char str2[] = "He studies in IIIT Sricity";
    printf("String2: ");
    printf("%s",str2);
    printf("\n");
    printf("on comparing str1 and str2 using strcmp: %d\n",strcmp(str1,str2));
    int i = 0;
    int count = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            count++;
        }
        i++;
    }
    if(count!=0){
        printf("on comparing str1 and str2 using loop: 1\n");
    }
    else{
        printf("on comparing str1 and str2 using loop: 0\n");
    }
    
}