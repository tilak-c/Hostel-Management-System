#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void dele_char(char *s,char ch)
{
    int i,j;

    for(i=0;*(s+i)!='\0';i++)
    {
        if(*(s+i)==ch)
        {
            for(j=i;*(s+j)!='\0';j++)
            *(s+j)=*(s+j+1);
            i--;
        }
    }
}
main()
{
	char p[1001][1000],j[1001][1000];
	int l,k=0,toDel=3;
	FILE *fp=fopen("checkRooms.txt","w");
	if(fp==NULL)
	{
		printf("Error!");
	}
	for(int i=101;i<510;i++)
	{
		if(i%10==0)
		{
			i=i+90;
			continue;
		}
		itoa(i,p[k],10);
		strcat(p[k],"A\n");
		strcat(j[k],p[k]);
				
		dele_char(p[k],'A');
		dele_char(p[k],'\n');
		strcat(p[k],"B\n");

		strcat(j[k],p[k]);
		dele_char(p[k],'B');
		dele_char(p[k],'\n');
		strcat(p[k],"C\n");
		
		strcat(j[k],p[k]);
		dele_char(p[k],'C');
		dele_char(p[k],'\n');
		k++;
		
	}
	for(int i=0;i<50;i++)
	{
		fprintf(fp,"%s",j[i]);
	}
	fclose(fp);
	
}