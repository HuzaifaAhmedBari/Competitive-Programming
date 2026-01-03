#include <stdio.h>

int main()
{
    FILE *file1 = fopen("File1.txt", "w");
    if(file1==NULL)
    {
    	printf("1:Not Found");
	}
    fprintf(file1, "Huzaifa");
    fclose(file1);

    FILE *file2 = fopen("File2.txt", "w");
    if(file2==NULL)
    {
    	printf("2:Not Found");
	}
    fprintf(file2, "Bari");
    fclose(file2);

	char buffer[251];
    FILE *file1_read = fopen("File1.txt", "r");
    FILE *file2_read = fopen("File2.txt", "r");
    FILE *file3 = fopen("File3.txt", "w+");

    char name[100];
    fscanf(file1_read, "%s", name);
    fprintf(file3, "%s", name);
    if(file3==NULL)
    {
    	printf("3:Not Found");
	}

    fscanf(file2_read, "%s", name);
    fprintf(file3, " %s", name);
    rewind(file3);
    fgets(buffer, 250, file3);
    printf("%s", buffer);

    fclose(file1_read);
    fclose(file2_read);
    fclose(file3);
} 
