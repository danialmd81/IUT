#include <stdio.h>
#include <math.h>

int main(){
int x1, x2, x3, y1, y2, y3, n, i;
int a, b, c;
int kochik, vasat, bozorg;
 scanf("%d", &n);
for(i=0; i<n; i++){
 scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
 a=(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
 b=(((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3)));
 c=(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
if (a>=b){
 if (c>=a){
 bozorg=c;
 vasat=a;
 kochik=b;
}
 else if((c<=a)&&(c>=b))
 {
 bozorg=a;
 vasat=c;
 kochik=b;
}
 else{
 bozorg=a;
 vasat=b;
 kochik=c;
}
}
 else{
 if (c>=b){
 bozorg=c;
 vasat=b;
 kochik=a;
}
 else if ((c<=b)&&(c>=a)){
 bozorg=b;
 vasat=c;
 kochik=a;
}
 else{
 bozorg=b;
 vasat=a;
 kochik=c;
}
}
 if((x1-x2)*(y1-y3)==(x1-x3)*(y1-y2))
 printf("not a triangle\n");
 else if ((a==b) && (b==c))
 printf("equilateral acute triangle\n");
 else{
 if((bozorg==vasat)||(vasat==kochik)||(bozorg==kochik)){
 if ((bozorg)<((vasat)+(kochik)))
 printf("isosceles acute triangle\n");
 else if ((bozorg)>((vasat)+(kochik)))
 printf("isosceles obtuse triangle\n");
 else
 printf("isosceles right triangle\n");
 }
 else{

 if ((bozorg)<((vasat)+(kochik)))
 printf("scalene acute triangle\n");
 else if ((bozorg)>((vasat)+(kochik)))
 printf("scalene obtuse triangle\n");
 else
 printf("scalene right triangle\n");
}
}
}
return 0;
}