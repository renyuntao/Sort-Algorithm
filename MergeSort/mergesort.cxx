#include<iostream>
using std::cout;
using std::endl;

void merge(int arr[],int length,int tmp[],int k)
{
	int low1,high1,low2,high2;

	low1 = 0;
	int m = low1;


	// Can be divided into two groups
	while(low1+k <= length-1)
	{
		low2 = low1 + k;
		high1 = low2 - 1;
		high2 = (low2+k-1 <= length-1) ? low2+k-1 : length-1;

		int i,j;
		for(i = low1,j = low2; i <= high1 && j <= high2; ++m)
		{
			if(arr[i] < arr[j])
			{
				tmp[m] = arr[i];
				++i;
			}
			else
			{
				tmp[m] = arr[j];
				++j;
			}
		}

		while(i <= high1)
		{
			tmp[m] = arr[i];
			++i;
			++m;
		}

		while(j <= high2)
		{
			tmp[m] = arr[j];
			++j;
			++m;
		}
		
		low1 = high2 + 1;
	}

	// Only have one groups
	for(int i = low1; i < length; ++i)
	{
		tmp[m] = arr[i];
		++m;
	}
}

void mergesort(int arr[],int length)
{
	int *tmp = new int[length];

	int k = 1;
	while(k < length)
	{
		merge(arr,length,tmp,k);
		for(int i = 0; i < length; ++i)
			arr[i] = tmp[i];
		k *= 2;
	}

	delete [] tmp;
}

int main(void)
{
	int arr[] = {1,0,6,9,4,3,-5,8,12,10,-7,-34};
	int len = sizeof(arr) / sizeof(arr[0]);
	mergesort(arr,len);
	for(auto e:arr) cout<<e<<" ";
	cout<<endl;
	return 0;
}
