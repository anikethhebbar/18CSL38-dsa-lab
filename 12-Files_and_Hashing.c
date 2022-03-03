#include <stdio.h>
#include <string.h>
#define MAX_ADDR 100
struct emmployee
{
    int empid;
    int age;
    char name[20];
} ht[MAX_ADDR], temp;
int hash(int key)
{
    return key % MAX_ADDR;
}
int main()
{
    int n, i, index, count = 0;
    FILE *fp;
    printf("Enter the number of Employees\n");
    scanf("%d", &n);
    fp = fopen("source.txt", "w");
    for (i = 0; i < n; i++)
    {
        printf("Enter the 4-digit key, age and name of an employee %d:\n", i + 1);
        scanf("%d", &temp.empid);
        scanf("%d", &temp.age);
        fflush(stdin);
        gets(temp.name);
        fprintf(fp, "%d\t%d\t%s\n", temp.empid, temp.age, temp.name);
    }
    fclose(fp);
    for (i = 0; i < MAX_ADDR; i++)
        ht[i].empid = -1;
    fp = fopen("source.txt", "r");
    while (fscanf(fp, "%d%d%s", &temp.empid, &temp.age, temp.name) != EOF)
    {
        if (count == MAX_ADDR)
        {
            printf("No space is available\n");
            break;
        }
        index = hash(temp.empid);
        if (ht[index].empid == -1)
        {
            ht[index].empid = temp.empid;
            ht[index].age = temp.age;
            strcpy(ht[index].name, temp.name);
            count++;
        }
        else //Collision Resolution (Linear Probing)
        {
            printf("Collision found for employee id %d\n", temp.empid);
            for (i = 1; i < MAX_ADDR; i++) //start from 1
            {
                index = (hash(temp.empid) + i) % MAX_ADDR;
                if (ht[index].empid == -1) //Found free location
                {
                    ht[index].empid = temp.empid;
                    ht[index].age = temp.age;
                    strcpy(ht[index].name, temp.name);
                    count++;
                    printf("Collision Resolved for empid %d\n", temp.empid);
                    break;
                }
            }
        }
    }
    fclose(fp);
    printf("Hash Address \t Empid \t Age \t Name\n");
    for (i = 0; i < MAX_ADDR; i++)
    {
        if (ht[i].empid != -1)
            printf("%d\t%d\t%d\t%s\n", i, ht[i].empid, ht[i].age, ht[i].name);
    }
    return 0;
}
