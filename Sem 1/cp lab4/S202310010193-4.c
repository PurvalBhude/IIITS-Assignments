1)
#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
    a=4;
    b=6;
    c=3;
    d=4;
    e=8;
    f=8;
    g=2;
    int ans = a+b*c/d-e+(++f-a--*b-d);
    printf("a+b*c/d-e+(++f-a--*b-d) answer is %d",ans);
}

2)
#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
    a=4;
    b=6;
    c=3;
    d=4;
    e=8;
    f=8;
    g=2;
    int ans = a+b*(c/d)-e+(++f-a--*b-d);
    printf("a+b*(c/d)-e+(++f-a--*b-d) answer is %d",ans);
}

3)
#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
    a=4;
    b=6;
    c=3;
    d=4;
    e=8;
    f=8;
    g=2;
    int ans = (a&b)&(c|d)^(e^f);
    printf("(a&b)&(c|d)^(e^f) answer is %d",ans);
}

4)
#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
    a=4;
    b=6;
    c=3;
    d=4;
    e=8;
    f=8;
    g=2;
    int ans = (a&b)&(c|d)^(e^f)>>1+1;
    printf("(a&b)&(c|d)^(e^f)>>1+1 answer is %d",ans);
}

5)
#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
    a=4;
    b=6;
    c=3;
    d=4;
    e=8;
    f=8;
    g=2;
    int ans = a^f&c|d&e^f<<1;
    printf("a^f&c|d&e^f<<1 answer is %d",ans);
}

6)
#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
    a=4;
    b=6;
    c=3;
    d=4;
    e=8;
    f=8;
    g=2;
    int ans = g^f&c|a&e^b>>1;
    printf("g^f&c|a&e^b>>1 answer is %d",ans);
}

7)
#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
    a=4;
    b=6;
    c=3;
    d=4;
    e=8;
    f=8;
    g=2;
    int ans = a^e&f|c&g^b<<1+1;
    printf("a^e&f|c&g^b<<1+1 answer is %d",ans);
}

8)
#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
    a=4;
    b=6;
    c=3;
    d=4;
    e=8;
    f=8;
    g=2;
    int ans = c^f&b|d&e^a>>1+1;
    printf("c^f&b|d&e^a>>1+1 answer is %d",ans);
}

