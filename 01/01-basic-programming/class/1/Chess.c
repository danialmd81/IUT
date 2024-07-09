#include <stdio.h>

int main()
{
	int i1,i2,i3,i4,i5,j1,j2,j3,j4,j5;
	scanf("%d%d%d%d%d%d%d%d%d%d",&i1,&j1,&i2,&j2,&i3,&j3,&i4,&j4,&i5,&j5);
	if((i1-i2!=0 && j1-j2==0)||(j1-j2!=0 && i1-i2==0)||(i1-i2==j1-j2 || -(i1-i2)==j1-j2))
	{
		printf("Yes");
	}
	else if((i1-i3!=0 && j1-j3==0)||(j1-j3!=0 && i1-i3==0)||(i1-i3==j1-j3 || -(i1-i3)==j1-j3))
	{
		printf("Yes");
	}
	else if((i1-i4!=0 && j1-j4==0)||(j1-j4!=0 && i1-i4==0)||(i1-i4==j1-j4 || -(i1-i4)==j1-j4))
	{
		printf("Yes");
	}
	else if((i1-i5!=0 && j1-j5==0)||(j1-j5!=0 && i1-i5==0)||(i1-i5==j1-j5 || -(i1-i5)==j1-j5))
	{
		printf("Yes");
	}
	else if((i3-i2!=0 && j3-j2==0)||(j3-j2!=0 && i3-i2==0)||(i3-i2==j3-j2 || -(i3-i2)==j3-j2))
	{
		printf("Yes");
	}
	else if((i4-i2!=0 && j4-j2==0)||(j4-j2!=0 && i4-i2==0)||(i4-i2==j4-j2 || -(i4-i2)==j4-j2))
	{
		printf("Yes");
	}
	else if((i5-i2!=0 && j5-j2==0)||(j5-j2!=0 && i5-i2==0)||(i5-i2==j5-j2 || -(i5-i2)==j5-j2))
	{
		printf("Yes");
	}
	else if((i3-i4!=0 && j3-j4==0)||(j3-j4!=0 && i3-i4==0)||(i3-i4==j3-j4 || -(i3-i4)==j3-j4))
	{
		printf("Yes");
	}
		else if((i3-i5!=0 && j3-j5==0)||(j3-j5!=0 && i3-i5==0)||(i3-i5==j3-j5 || -(i3-i5)==j3-j5))
	{
		printf("Yes");
	}
	else if((i4-i5!=0 && j4-j5==0)||(j4-j5!=0 && i4-i5==0)||(i4-i5==j4-j5 || -(i4-i5)==j4-j5))
	{	printf("Yes");
	}
	else
	{
		printf("No");
	}
}