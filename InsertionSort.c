#include <stdio.h>
int main()
{
    int array[10];
    int key, n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 1; i < n; i++)
    {
        key = array[i];
        int j = i - 1;
     //   printf("%d %d \n", key,j);


        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
       // printf("%d \n", array[j + 1]);
    }

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}