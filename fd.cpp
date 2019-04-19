#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char p[10][5],temp[5];
	int i,j,process_time[10],wt[10],total_waittime=0,pr[10],temp1,n;
	float average_time;
	printf("***************************************************************");
	printf("\nENTER THE NUMBER OF STUDENTS:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n\t\tENTER NAME OF STUDENT %d:",i+1);
  		scanf("%s",&p[i]);
		printf("\n\t\tENTER THE PROCESS TIME:");
		scanf("%d",&process_time[i]);
		printf("\n\t\tENTER THE NUMBER OF GIFTS:");
		scanf("%d",&pr[i]);
	}
  	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(pr[i]>pr[j])
			{
				temp1=pr[i];
				pr[i]=pr[j];
				pr[j]=temp1;
				temp1=process_time[i];
				process_time[i]=process_time[j];
				process_time[j]=temp1;
				strcpy(temp,p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],temp);
			}
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{   
	wt[i]=0;
	for(j=0;j<i;j++)
		wt[i]=wt[i]+process_time[j];
		total_waittime=total_waittime+wt[i];
	}
	average_time=(float)total_waittime/n;
	printf("STUDENT NAME\t PROCESS TIME\t NUMBER OF GIFTS\tWAITING TIME\n");
	for(i=0;i<n;i++)
	{
	   printf(" %s\t %d\t %d\t \t%d\n" ,p[i],process_time[i],pr[i],wt[i]);
	}
	printf("\n\t\tTOTAL WAITING TIME=%d",total_waittime);
	printf("\n\t\tAVERAGE WAITING TIME=%f",average_time);
	getch();
}


