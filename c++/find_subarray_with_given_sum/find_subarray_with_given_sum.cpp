/* Given an unsorted array of non-negative integers.Find if there is a subarray with given sum*/
#include<stdio.h> 
#include<iostream>
using namespace std;

int subArraySum(int arr[], int n, int sum) 
{ 
	
    int i=0;
    int start=0;
    int curr_sum=arr[i];
    for (i = 1; i <= n; i++) //if i<n then uncomment last section
    {
        while (curr_sum>sum &&start<i-1)
        {
            curr_sum-=arr[start];
            start++;
        }

        if(curr_sum==sum)
        {
            printf ("Sum found between indexes %d and %d", start, i-1); 
			return 1; 
        }
        
        if(i<n)
        {
            curr_sum+=arr[i];
        }
        
    }
    /*
    if(curr_sum==sum)
    {
        printf ("Sum found between indexes %d and %d", start, i-1); 
		return 1; 
    }
*/
	printf("No subarray found"); 
	return 0; 
} 

// Driver program to test above function 
int main() 
{ 
	//int arr[] = {15, 2, 4, 8, 9, 5, 10, 23}; 
    int arr[]={1,4,20,3,10,5};
	int n = sizeof(arr)/sizeof(arr[0]); 
	int sum = 15; 
	subArraySum(arr, n, sum); 
	return 0; 
} 
