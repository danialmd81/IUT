#include<stdio.h>

int main()
{
    int n1, n2, n3;
    char H1,H2,H3;
    scanf("%d %d %d %c%c%c", &n1, &n2, &n3, &H1, &H2, &H3);
    if (n1<n2&&n1<n3&&n2<n3)  //n1<n2<n3
{
if(H1=='A'&&H2=='B'&&H3=='C'){printf("%d %d %d",n1,n2,n3);}
if(H1=='A'&&H2=='C'&&H3=='B'){printf("%d %d %d",n1,n3,n2);}
if(H1=='B'&&H2=='A'&&H3=='C'){printf("%d %d %d",n2,n1,n3);}
if(H1=='B'&&H2=='C'&&H3=='A'){printf("%d %d %d",n2,n3,n1);}
if(H1=='C'&&H2=='A'&&H3=='B'){printf("%d %d %d",n3,n1,n2);}
if(H1=='C'&&H2=='B'&&H3=='A'){printf("%d %d %d",n3,n2,n1);}
}
if (n1<n2&&n1<n3&&n3<n2)  //n1<n3<n2
{
if(H1=='A'&&H2=='B'&&H3=='C'){printf("%d %d %d",n1,n3,n2);}
if(H1=='A'&&H2=='C'&&H3=='B'){printf("%d %d %d",n1,n2,n3);}
if(H1=='B'&&H2=='A'&&H3=='C'){printf("%d %d %d",n3,n1,n2);}
if(H1=='B'&&H2=='C'&&H3=='A'){printf("%d %d %d",n3,n2,n1);}
if(H1=='C'&&H2=='A'&&H3=='B'){printf("%d %d %d",n2,n1,n3);}
if(H1=='C'&&H2=='B'&&H3=='A'){printf("%d %d %d",n2,n3,n1);}
}
if (n2<n1&&n2<n3&&n1<n3)  //n2<n1<n3
{

if(H1=='A'&&H2=='B'&&H3=='C'){printf("%d %d %d",n2,n1,n3);}
if(H1=='A'&&H2=='C'&&H3=='B'){printf("%d %d %d",n2,n3,n1);}
if(H1=='B'&&H2=='A'&&H3=='C'){printf("%d %d %d",n1,n2,n3);}
if(H1=='B'&&H2=='C'&&H3=='A'){printf("%d %d %d",n1,n3,n2);}
if(H1=='C'&&H2=='A'&&H3=='B'){printf("%d %d %d",n3,n2,n1);}
if(H1=='C'&&H2=='B'&&H3=='A'){printf("%d %d %d",n3,n1,n2);}
}
if (n2<n1&&n3<n1&&n2<n3)  //n2<n3<n1
{

if(H1=='A'&&H2=='B'&&H3=='C'){printf("%d %d %d",n2,n3,n1);}
if(H1=='A'&&H2=='C'&&H3=='B'){printf("%d %d %d",n2,n3,n2);}
if(H1=='B'&&H2=='A'&&H3=='C'){printf("%d %d %d",n3,n2,n1);}
if(H1=='B'&&H2=='C'&&H3=='A'){printf("%d %d %d",n3,n1,n2);}
if(H1=='C'&&H2=='A'&&H3=='B'){printf("%d %d %d",n1,n2,n3);}
if(H1=='C'&&H2=='B'&&H3=='A'){printf("%d %d %d",n1,n3,n2);}
}
if (n3<n2&&n3<n1&&n2<n1)  //n3<n2<n1
{

if(H1=='A'&&H2=='B'&&H3=='C'){printf("%d %d %d",n3,n2,n1);}
if(H1=='A'&&H2=='C'&&H3=='B'){printf("%d %d %d",n3,n1,n2);}
if(H1=='B'&&H2=='A'&&H3=='C'){printf("%d %d %d",n2,n3,n1);}
if(H1=='B'&&H2=='C'&&H3=='A'){printf("%d %d %d",n2,n1,n3);}
if(H1=='C'&&H2=='A'&&H3=='B'){printf("%d %d %d",n1,n3,n2);}
if(H1=='C'&&H2=='B'&&H3=='A'){printf("%d %d %d",n1,n2,n3);}
}
if (n3<n2&&n3<n1&&n1<n2)  //n3<n1<n2
{

if(H1=='A'&&H2=='B'&&H3=='C'){printf("%d %d %d",n3,n1,n2);}
if(H1=='A'&&H2=='C'&&H3=='B'){printf("%d %d %d",n3,n2,n1);}
if(H1=='B'&&H2=='A'&&H3=='C'){printf("%d %d %d",n1,n3,n2);}
if(H1=='B'&&H2=='C'&&H3=='A'){printf("%d %d %d",n1,n2,n3);}
if(H1=='C'&&H2=='A'&&H3=='B'){printf("%d %d %d",n2,n3,n1);}
if(H1=='C'&&H2=='B'&&H3=='A'){printf("%d %d %d",n2,n1,n3);}
}



}






