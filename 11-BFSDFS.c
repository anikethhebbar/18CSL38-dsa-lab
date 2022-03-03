#include <stdio.h>
#include <stdlib.h>
int n, a[20][20], visited1[20], visited2[20], source;
void read_data()
{
    int i, j;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}
void print_data(int visited[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            printf("\nVertex %d is not reachable\n", i);
        else
            printf("\nVertex %d is reachable\n", i);
    }
}
void BFS()
{
    int f = 0, r = 0, q[20], i, j;
    q[r] = source;
    visited1[source] = 1;
    while (f <= r)
    {
        i = q[f++];
        printf("--%d--", i);
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 1 && visited1[j] == 0)
            {
                visited1[j] = 1;
                q[++r] = j;
            }
        }
    }
}
void DFS(int src, int *cnt)
{
    int i, j;
    printf("--%d--", src);
    visited2[src] = 1;
    for (j = 0; j < n; j++)
    {
        if (a[src][j] == 1 && visited2[j] == 0)
        {
            (*cnt)++;
            DFS(j, cnt);
        }
    }
}
int main()
{
    int i, choice, a, *count = &a;
    read_data();
    printf("\t\t**ADJACENCY MATRIX FOR CITIES HAS CREATED SUCCESSFULLY**\n");
    while (1)
    {
        printf("\n1.BFS\n2.DFS\n3.Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (i = 0; i < n; i++)
                visited1[i] = 0;
            printf("Enter the source vertex between 0 to %d\n", n - 1);
            scanf("%d", &source);
            BFS();
            print_data(visited1);
            break;
        case 2:
            for (i = 0; i < n; i++)
                visited2[i] = 0;
            printf("Enter the source vertex between 0 to %d\n", n - 1);
            scanf("%d", &source);
            a = 0;
            DFS(source, count);
            print_data(visited2);
            if (*count == n - 1)
                printf("Graph is connected\n");
            else
                printf("Graph is not connected\n");
            break;
        case 3:
            exit(0);
        default:
            printf("\nEnter proper Choice");
        }
    }
    return 0;
}
