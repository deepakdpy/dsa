#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int *a, int n, int i)
{
    int largest = i;   
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);

        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);

        heapify(a, i, 0);
    }
}

// Display the array
void display(int *a, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

//Creating array of random numbers
int *createarray(int *a, int n)
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
    FILE *fp;
    fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &n);
    fclose(fp);
    // int dis;
    // printf("Do you want to display array:");
    // scanf("%d", &dis);
    struct timeval start, end; //declare two time structures for start and end time
    int *a;
    a = createarray(a, n);
    // if (dis)
    // {
    //     display(a, n);
    // }
    gettimeofday(&start, NULL); //Putting the start time in start
    heapSort(a, n);
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