#include <stdio.h>

int largestRectangleArea(int* heights, int heightsSize){
    int i, j, bars, area;
    int calculated;
    int max = 0;
    
    for (i = 0; i < heightsSize; i++) {        
        bars = 1;
        calculated = 0;
        
        j = i - 1;
        while (j >= 0) {
            if (heights[j] == heights[i]) {
                calculated = 1;
                break;
            } else if (heights[j] > heights[i]) {
                bars++;
                j--;
            }
            else {
                break;
            }
        }
        
        if (calculated == 1)
            continue;
        
        j = i + 1;
        while (j < heightsSize) {
            if (heights[j++] >= heights[i])
                bars++;
            else
                break;
        }
        
        area = heights[i] * bars;
        
        if (area > max)
            max = area;
    }
    
    return max;
}

int main ()
{
    int n;
    scanf("%d\n",&n);
    //printf("%d",n);
    int heights1[1000000];
    
    for(int t=0;t<n;t++)
    {
        scanf("%d",&heights1[t]);
        //printf("%d\n",heights1[t]);
    }

    printf("%d\n" , largestRectangleArea(heights1,n));


}
