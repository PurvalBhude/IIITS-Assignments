int n;
printf("enter the size of array: ");
scanf("%d",&n);
int *q = (int*) malloc(sizeof(int)*n);
printf("Enter the values in array: \n");
for(int i=0;i<n;i++){
    scanf("%d",&q[i]);
}
int a,b;
printf("Enter the value of i and j for which you what value of A[i,j] :");
scanf("%d %d",&a,&b);
findAij(q,n,a,b);