#include<stdio.h>
#include<stdlib.h>

void inputEmployees(int **ratings, int numEmployees, int numPeriods)
{
	int i, j;
	for(i=0; i<numEmployees; i++)
	{
		for(j=0; j<numPeriods; j++)
		{
			printf("Enter Rating %d of Employee %d : ", j+1, i+1);
			while(scanf("%d", *(ratings+i) + j) == 0 || *(*(ratings+i) + j) < 0 || *(*(ratings+i) + j) > 10)
			{
				printf("Please Enter the Rating Between 0 and 10 (inclusive) : ");
			}
		}
	}
}
struct Employee
{
	int *ratings;
	int totalscore;
};
int main()
{
	int n, nep, i;
	printf("Enter the Number of Employees : ");
	scanf("%d", &n);
	printf("Enter the Number of Evaluation Periods : ");
	scanf("%d", &nep);
	
	struct Employee *emp = (struct Employee *)malloc(n * sizeof(struct Employee));
	
	for(i=0; i<n; i++)
	{
		emp[i].ratings = (int *)calloc(nep, sizeof(int));
	}
	int **arr = (int **)malloc(n * sizeof(int *));
	for(i=0; i<n; i++)
	{
		arr[i] = emp[i].ratings;
	}
	
	inputEmployees(arr, n, nep);
	
	for(i=0; i<n; i++)
	{
		free(emp[i].ratings);
	}
	free(emp);
	free(arr);
	return 0;
}
