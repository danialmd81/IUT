#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

char* AnimeOrgenizer(char* AnimeName)
{
    for(int i=0;i<260;++i)
    {
        AnimeName[i]=tolower(AnimeName[i]);
        // ||AnimeName[i-1]==46
        if(isspace(AnimeName[i-1])||(AnimeName[i-1]==46&&AnimeName[i+1]!='\0')||isdigit(AnimeName[i-1]))
        {
            if(AnimeName[i-1]=='.'&&AnimeName[i]!='m'&&AnimeName[i]!='M'&&AnimeName[i+1]!='k'&&AnimeName[i+2]!='v')
            AnimeName[i-1]=' ';
            AnimeName[i]=toupper(AnimeName[i]);
        }
        
        AnimeName[0]=toupper(AnimeName[0]);
    }
    return AnimeName;
}

int main()
{
    char* OldName = (char*)malloc(512 * sizeof(char));
	char* NewName = (char*)malloc(512 * sizeof(char));
	char* path = (char*)malloc(512 * sizeof(char));
    gets(path);
	DIR* name=opendir(path);
	struct dirent* entry;
    if (name == NULL) 
    {
        return 0;
    }

    while(entry=readdir(name))
    {
		sprintf(OldName, "%s/%s", path, entry->d_name);
		sprintf(NewName, "%s/%s", path, AnimeOrgenizer(entry->d_name));
		int result=rename(OldName, NewName);
        if (result == 0) 
        {
            printf("The file is renamed successfully.\n");
        } 
        else 
        {
            printf("The file could not be renamed.\n");
        }
    }
    closedir(name);
    free(OldName);
    free(NewName);
	free(path);
	return 0;
}