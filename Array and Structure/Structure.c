#include <stdio.h>
#include <stdlib.h>

typedef struct person {
	char name[10];
	int age;
	float salary;
}Person;

int main() {

	int avg = 0;
	int a = 0;

	Person* p1;
	p1 = (Person*)malloc(sizeof(Person) * 3);

	for (int i = 0; i < 3; i++)
	{
		printf("Enter person's name:");
		scanf("%s", p1[i].name);
		printf("Enter person's age:");
		scanf("%d", &p1[i].age);
		printf("Enter person's salary:");
		scanf("%f", &p1[i].salary);
	}
	for (int i = 0; i < 3; i++)
	{
		a += p1[i].age;
		avg = a / 3;
	}
	printf("Average Age: %d\n", avg);

	free(p1);
}