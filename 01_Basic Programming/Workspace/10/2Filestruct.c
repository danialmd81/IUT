#include <stdio.h>
typedef struct input 
{
    int id;
    char name[20];
}input;
int main()
{
    input a;
    int n;
    scanf("%d",&n);
    FILE * file = fopen ("data.bin", "rb");
    if(file==NULL)
    {
        return 0;
    }
    fseek (file, (n-1)*sizeof(input), SEEK_SET);
	fread(&a,sizeof(input),1,file);
	printf ("%d:%s\n",a.id,a.name);	
	fclose (file);
    return 0;
}