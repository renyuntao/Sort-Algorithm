#include<iostream>

template<typename T>
int partition(T arr[],int low,int high)
{
	T pivot = arr[low];
	int p = low + 1;
	int r = high;
	while(1)
	{
		while(r != low && arr[r] > pivot) --r;    //from right to left
		while(p != high && arr[p] <= pivot) ++p;  //from left to right
		if(p < r)
		{
			T tmp = arr[p];
			arr[p] = arr[r];
			arr[r] = tmp;
		}
		else
			break;
	}
	return r;
}

template<typename T>
void quicksort(T arr[],int low,int high)
{
	if(low < high)
	{
		int j = partition(arr,low,high);
		T tmp = arr[low];
		arr[low] = arr[j];
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
