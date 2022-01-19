#include <stdio.h>
#include <stdlib.h>
int a[20], N, ELEM, POS, i;
void create();
void display();
void insert();
void delete_ele();
int main()
{
	int choice;
	while (1)
	{
		printf("\n\n---- A PROGRAM TO PERFORM ARRAY OPERATIONS----");
		printf("\n1.CREATE\n");
		printf("2.DISPLAY\n");
		printf("3.INSERT\n");
		printf("4.DELETE\n");
		printf("5.EXIT\n");
		printf("\nENTER YOUR CHOICE\t");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			insert();
			break;
		case 4:
			delete_ele();
			break;
		case 5:
			exit(0);
		default:
			printf("\nINVALID CHOICE\n");
			break;
		}
	}
	return 0;
}
void create()
{
	printf("\nEnter the size of the array elements:\t");
	scanf("%d", &N);
	printf("\nEnter the elements for the array:\n");
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);
}
void display()
{
	if (N == 0)
	{
		printf("\nArray is empty-Nothing to display:\n");
		return;
	}
	printf("\n The array elements are:\n");
	for (i = 0; i < N; i++)
		printf("%d\t", a[i]);
}
void insert()
{
	printf("\nEnter the position between 1 and %d to insert a new element:\t", N);
	scanf("%d", &POS);
	POS = POS - 1;
	if (POS >= 0 && POS <= N)
	{
		printf("\nEnter the element to be inserted:\t");
		scanf("%d", &ELEM);
		for (i = N - 1; i >= POS; i--)
			a[i + 1] = a[i];
		a[POS] = ELEM;
		N = N + 1;
	}
}
void delete_ele()
{
	if (N == 0)
	{
		printf("\nArray Empty deletion not possible\n");
		return;
	}
	printf("\nEnter the position between 1 and %d of the element to be deleted:\t", N);
	scanf("%d", &POS);
	POS = POS - 1;
	if (POS >= 0 && POS < N)
	{
		ELEM = a[POS];
		for (i = POS; i < N - 1; i++)
			a[i] = a[i + 1];
		printf("\nThe Deleted elements is =%d\n", ELEM);
		N = N - 1;
	}
}