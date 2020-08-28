#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int getMax(int *arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int *arr, int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
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
    FILE *fp;
    fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &n);
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
    radixSort(a, n);
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