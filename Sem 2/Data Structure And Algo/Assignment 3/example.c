#include <stdio.h>

void main(){
    // short int v = -123456;
    // unsigned short uv = (unsigned short) v;
    // printf("v = %d , uv = %d\n",v,uv);

    // int x = -1;
    // unsigned u = 2147483648;
    // printf("x = %u = %d\n",x,x);
    // printf("u = %u = %d\n",u,u);

    printf("%d\n",(0==0U));
    printf("%d\n",(-1<0));
    printf("%d\n",(-1<0U));
    printf("%d\n",(2147483647 > -2147483647-1));
    printf("%d\n",(2147483647U > -21147483647-1));
    printf("%d\n",(2147483647 > (int)2147483647));
    printf("%d\n",(-1>-2));
    printf("%d\n",((unsigned)-1 > -2));
    
    return;
}