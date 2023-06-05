#include<stdio.h>
int main(){

    int min,max,key,mid;

    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);

    printf("\n");

    printf("Input array elements: ");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Enter the key to search: ");
    scanf("%d", &key);

    min=0;
    max=n-1;
    mid=(min+max)/2;

    
   printf("\n");
while (min <= max) {
    if (arr[mid] < key)
      min = mid + 1;

    else if (arr[mid] == key) {
      printf("%d found at location %d.\n", key, mid+1);
      break;
    }

    else
      max = mid - 1;

    mid = (min + max)/2;
  }
  if (min > max)
    printf("Not found! %d isn't present in the list.\n", key);


    return 0;
}

