#include<stdio.h>
int main(){

    // 12 3 5 11 2

    int n,temp;
    printf("Enter the array size: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for (int i = 0; i < n-1; i++){

        for(int j = 0; j < n; j++){

            if (arr[j] > arr[j+1])
        {
               temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
        }
               
    }

    }


    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}