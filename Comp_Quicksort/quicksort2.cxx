#include<iostream>
#include<random>
using std::endl;
using std::cout;

int partition(int arr[],int low,int high)
{
	int tmp = arr[low];
	int i = low;
	int j = high;
	while(i < j)
	{
		while(i < j && arr[j] > tmp) --j;    //from right to left
		if(i < j)
		{
			arr[i] = arr[j];
			++i;
		}
		while(i < j && arr[i] <= tmp) ++i;    //from left to right
		if(i < j)
		{
			arr[j] = arr[i];
			--j;
		}
	}
	return j;
}

void quicksort(int arr[],int low,int high)
{
	if(low < high)
	{
		int t = arr[low];
		int j = partition(arr,low,high);
		arr[j] = t;
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
