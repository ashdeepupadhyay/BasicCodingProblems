#include<iostream>
#include<limits>
#include<math.h>
using namespace std; 

int findWater(int arr[], int size) 
{ 
    int left[size];
    int right[size];
    int sum_water=0;
    left[0]=arr[0];

    for (int i=1;i<size;i++)
    {
        left[i]=max(left[i-1],arr[i]);
    }

    right[size-1]=arr[size-1];
    for (int i=size-2;i>=0;i--)
    {
        right[i]=max(right[i+1],arr[i]);
    }

    for (int i=0;i<size;i++)
    {
        sum_water+=min(left[i],right[i])-arr[i];
    }
	
    return sum_water;
} 

int main() 
{ 
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Maximum water that can be accumulated is "<< findWater(arr, n); 
	return 0; 
}	 
