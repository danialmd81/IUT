#include <stdio.h>
int main(){
    int a[100][100],ai,aj,b[100][100],bi,bj,c[100][100],i,j,k;
    scanf("%d %d %d",&ai,&aj,&bj);
    bi=aj;
    for(i=0;i<ai;i++){
        for(j=0;j<aj;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for( i=0;i<bi;i++){
        for( j=0;j<bj;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<ai;i++){
        for( j=0;j<bj;j++){
            c[i][j]=0;
            for(k=0;k<aj;k++)
            c[i][j]+=a[i][k]*b[k][j];        }
    }
    for (i = 0; i < ai; i++) {
            for (j = 0; j < bj; j++) {
                printf("%d ", c[i][j]);
            }
            printf("\n");
}
}