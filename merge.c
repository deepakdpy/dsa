#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
    mergeSort(a, 0, n - 1);
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