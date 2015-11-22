#include<iostream>
using std::cout;
using std::endl;

void createMaxHeap(int arr[],int length,int root)
{
	int i = root;
	int j = 2 * i + 1;
	int tmp = arr[i];

	while(j < length)
	{
		int max = tmp;
		int p = i;
		if(arr[j] > max)
		{
			p = j;
			max = arr[j];
		}
		if(j+1 < length && arr[j + 1] > max)
		{
			p = j + 1;
		}

		// parent node's value is greater than child node's value
		if(p == i)
			break;
		else
		{
			arr[i] = arr[p];
			i = p;
			j = 2 * i + 1;
		}
	}

	arr[i] = tmp;
}

void InitMaxHeap(int arr[],int length)
{
	for(int k = (length-1)/2; k >= 0; --k)
	{
		createMaxHeap(arr,length,k);
	}
}

/*
 * Heap Sort
 *
 */ 
void heapsort(int arr[],int length)
{
	InitMaxHeap(arr,length);

	for(int i = length-1; i > 0; --i)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		// adjust the root and keep the arr is a Max Heap
		createMaxHeap(arr,i,0);
	}
}

int main(void)
{
	int arr[] = {1,0,6,9,4,2,-3,7,-12,94,-100,83};
	int len = sizeof(arr) / sizeof(arr[0]);
	heapsort(arr,len);
	for(auto e:arr) cout<<e<<" ";
	cout<<endl;
	return 0;
}
