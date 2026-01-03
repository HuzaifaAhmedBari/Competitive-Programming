#include <stdio.h>
#include <string.h>

void addCategories(int n) {
	int i;
    char categ[1000];
    FILE* fptr = fopen("categories.txt", "a");

    if (fptr == NULL) {
        printf("Could not open file.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter Name of category %d\n", i + 1);
        fgets(categ, sizeof(categ), stdin);
        categ[strcspn(categ, "\n")] = 0; 
        fprintf(fptr, "%s %d\n", categ,i + 1);
    }

    fclose(fptr);
}

int main() {
    int n;
    printf("Enter number of categories: ");
    scanf("%d", &n);
    getchar();  // Consume newline left in input buffer
    addCategories(n);
    return 0;
}
