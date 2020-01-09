#include<iostream>
using namespace std;

void reverse(int arr[],int start,int end)
{
    int temp;
    while(start<end)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void rotateByD(int *arr,int d,int n)
{
    reverse(arr,0,d-1);
    for(int i = 0; i < n; i++)
     cout << arr[i] << " ";
         cout<<"\n";

    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main () {
    
	int arr[] = {2, 8, 7, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++)
     cout << arr[i] << " ";
    cout<<"\n";
    int d = 3;
    rotateByD(arr, d, n);
        cout<<"\n";

    for(int i = 0; i < n; i++)
     cout << arr[i] << " ";
    return 0;
}