#include<stdio.h>
int main(){

    int n,i;
    scanf("%d",&n);

    int arr[21];
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    

    int min=i;

    for ( i = 0; i < n-1; i++)
    {
        min= i;

        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[min])
                min = j;

            if (min!=i)
            {
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
            
            
        }
        
    }
    
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}