#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
///Selection Sort Algorithm
void selectionSort(int *a, int n) 
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        j = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

// Display the array
void display(int *a, int n)
{
    printf("\n");
    for (int i = 0; i<n; i++)
    {
        printf("%d \t", a[i]);
    }
    printf("\n");
}

//Creating array of random numbers
int *createArray(int *a, int n)
{
    time_t seed = time(NULL); //seeding the random function
    srand(seed);              //seeding the random function
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    return a;
}
int main()
{
    int n;
    // printf("Enter the number of elements:");
    // scanf("%d", &n);
    FILE * fp;
    fp=fopen("in.txt","r");
    fscanf(fp,"%d", &n);
    fclose(fp);
    // int dis;
    // printf("Do you want to display array:");
    // scanf("%d", &dis);
    struct timeval start, end; //declare two time structures for start and end time
    int *a;
    a = createArray(a, n);
    // if (dis)
    // {
    //     display(a, n);
    // }
    gettimeofday(&start, NULL); //Putting the start time in start
    selectionSort(a, n);
    gettimeofday(&end, NULL); //putting end time in end
    // if (dis)
    // {
    //     display(a, n);
    // }
    double exec_time = 1000000 * ((end.tv_sec - start.tv_sec)) + (end.tv_usec - start.tv_usec); //Getting the execution time(tsec in seconds and tusec in microseconds)
    // printf("Executed in :%f microseconds or %f seconds", exec_time, exec_time / 1e6);
    printf("%f",exec_time/1e6);

    return 0;
}
