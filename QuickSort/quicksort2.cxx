#include<iostream>

template<typename T>
int partition(T arr[],int low,int high)
{
	T tmp = arr[low];
	int i = low;
	int j = high;
	while(i < j)
	{
		while(i < j && arr[j] > tmp) --j;   //from right to left
		if(i < j)
		{
			arr[i] = arr[j];
			++i;
		}
		while(i < j && arr[i] <= tmp) ++i;   //from left to right
		if(i < j)
		{
			arr[j] = arr[i];
			--j;
		}
	}
	return j;
}

template<typename T>
void quicksort(T arr[],int low,int high)
{
	if(low < high)
	{
		T tmp = arr[low];
		int j = partition(arr,low,high);
		arr[j] = tmp;
		if(low < j)
			quicksort(arr,low,j-1);
		if(j < high)
			quicksort(arr,j+1,high);
	}
}

int main()
{
	char arr[] = {'h','e','l','l','o',' ','w','o','r','l','d'};
	quicksort(arr,0,10);
	for(auto e:arr) std::cout<<e<<" ";
	std::cout<<std::endl;
	return 0;
}
