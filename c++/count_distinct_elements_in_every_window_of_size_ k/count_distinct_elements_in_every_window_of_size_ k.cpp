// program to count distinct elements in every window of size k 
#include <iostream> 
#include <map> 
using namespace std; 

void countDistinct(int arr[], int k, int n) 
{ 
	// Creates an empty hashmap hm 
	map<int, int> hm; 
    map<int, int>::iterator itr; 

	// initialize distinct element count for current window 
	int dist_count = 0; 

	// Traverse the first window and store count 
	// of every element in hash map 
	for (int i = 0; i < k; i++) 
	{ 
      /*  
      if (hm[arr[i]] == 0) 
	  { 
		dist_count++; 
	  } 
      */
      //or
      map<int,int>::iterator it = hm.find(arr[i]);
	  if(it == hm.end())//check if key is not there
	  {
        	dist_count++; 
      }
	  
      hm[arr[i]] += 1; 
	} 
	
   //print map 
   /*
   for (itr = hm.begin(); itr != hm.end(); ++itr)
   { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    }
    */ 
    cout << dist_count <<"****"<<hm.size()<< endl; 

    for (int i = k; i < n; i++) 
    {  
	    if (hm[arr[i-k]] == 1) 
	    { 
		    dist_count--; 
	    } 

	    hm[arr[i-k]] -= 1;
  
  	    if(hm[arr[i-k]]==0)
        {
    	    hm.erase(arr[i-k]);
        }

	    if (hm[arr[i]] == 0) 
	    { 
	        dist_count++; 
	    } 
	    hm[arr[i]] += 1; 

        cout << dist_count << "************"<<hm.size()<<endl; 
    } 
} 

int main() 
{ 
    int arr[] = {1, 2, 1, 3, 4, 2, 3}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    int k = 4; 
    countDistinct(arr, k, size); 

    return 0; 
} 
