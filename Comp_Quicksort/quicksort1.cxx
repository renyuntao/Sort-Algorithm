#include<iostream>
#include<ctime>
#include<random>
using std::cout;
using std::endl;

int partition(int arr[],int low,int high)
{
	int i = low + 1;
	int j = high;
	int tmp = arr[low];
	while(1)
	{
		while(j != low && arr[j] > tmp) --j;   //from right to left
		while(i != high && arr[i] <= tmp) ++i;  //from left to right
		if(i < j)
		{
			int t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
		}
		else
			break;
	}
	return j;
}

void quicksort(int arr[],int low,int high)
{
	if(low < high)
	{
		int j = partition(arr,low,high);
		int t = arr[j];
		arr[j] = arr[low];
		arr[low] = t;
		if(low < j)
			quicksort(arr,low,j-1);
		if(high > j)
			quicksort(arr,j+1,high);
	}
}

int main()
{
	int *arr = new int[5000000];
	std::default_random_engine e(14874563);
	std::uniform_int_distribution<unsigned> u(1,10000);
	for(int i = 0;i < 4999999;++i)
	{
		arr[i] = u(e);
	}
	clock_t start = clock();
	quicksort(arr,0,4999999);
	clock_t end = clock();
	cout<<"time:"<<static_cast<float>(end-start)/CLOCKS_PER_SEC<<endl;
	delete [] arr;
	return 0;
}
