#include<iostream>
using namespace std; 

// solution structure 
class Interval { 
public: 
	int buy; 
	int sell; 
}; 

void stockBuySell(int price[], int n) 
{ 
	if (n == 1) 
		return; 

	int count = 0; 

	Interval sol[n / 2 + 1]; 
	int i =0;

	while(i<n-1)
	{
		while(i<n-1&&price[i+1]<=price[i])
		i++;

		if(i==n-1)
		break;

		sol[count].buy = i++;

		while(i<n&&(price[i-1]<=price[i]))
		i++;

		sol[count].sell=i-1;

		count++;
	}


	if (count == 0) 
		cout << "There is no day when buying"<< " the stock will make profit \n "; 
	else 
	{ 	
		int sum_profit=0;
		for (int i = 0; i < count; i++) 
		{
			cout << "Buy on day: " << sol[i].buy << "\t Sell on day: " << sol[i].sell << endl; 
			sum_profit=sum_profit+price[sol[i].sell]-price[sol[i].buy];
		}
		cout<<"\ntotal profit"<<sum_profit;
	}
} 

// Driver code 
int main() 
{ 
	// stock prices on consecutive days 
	int price[] = { 180, 100, 260, 310, 40, 535, 695,1020}; 
	int n = sizeof(price) / sizeof(price[0]); 

	// fucntion call 
	stockBuySell(price, n); 

	return 0; 
} 
