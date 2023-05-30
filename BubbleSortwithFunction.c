#include<stdio.h>

void sort(int n, int arr[]){

    for (int i = 0; i < n-1; i++){

        for(int j = 0; j < n; j++){

            if (arr[j] > arr[j+1])
        {
            int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
        }
               
    }

    }


    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}

int main(){

    // 12 3 5 11 2

    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    sort(n,arr);

    

    return 0;
}