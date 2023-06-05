#include<stdio.h>
int main(){

    int n;
    printf("Enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    
    
    printf("\nEnter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("\n");
    printf("Enter the key to search: ");
    scanf("%d",&key);

    printf("\n");
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            printf("%d is in position %d\n", key,i+1);
            found=1;
            break;
        }
       
    }
    printf("\n");
    if (!found)
    {
        printf("%d is not available\n",key);
    }

  
    return 0;
}



