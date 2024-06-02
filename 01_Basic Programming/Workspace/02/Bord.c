#include<stdio.h>
#include<math.h>
int main()
{
	double h, y0, vy, vx, d, t, t2, x, x2, temp, z, z2;
	scanf("%lf %lf %lf %lf", &vx, &vy, &y0, &h);
	d = vy * vy - 20 * (h - y0);
	t = (vy + sqrt(d)) /(10);
	t2= (vy-sqrt (d))/(10);
	x=(vx*t*100)/100.0;
	x2=(vx*t2*100)/100.0;
    z=fabs(x);
    z2=fabs(x2);
    if (d < 0 || t<0 && t2<0 )
    printf("impossible");
    else
    if (d == 0) 
    {
        printf("%.2f",z2);
        }
        else 
        {
            if(t>0&&t2<0)
            {
                printf("%.2f",z);
            }
            if(t2>0&&t<0)
            {
               printf("%.2f",z2); 
            }
            if(t>0&&t2>0)
            {
                if(z>z2){
                printf("%.2f\n%.2f",z2,z );
                }
                else{
                    printf("%.2f\n%.2f",z,z2);
                    }
            }
            
            
        }
}