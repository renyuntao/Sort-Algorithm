#include<iostream>
using std::cout;
using std::endl;

template<typename T>
void bubbleSort(T arr[],int length)
{
	for(int i = 0;i < length - 1;++i)      
	{
		bool sorted = true;
		for(int j = 0;j < length-1-i;++j)
		{
			// Swap
			if(arr[j] > arr[j+1])   
			{
				T tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				sorted = false;
			}
		}
		if(sorted == true)
			break;
	}
}

int main()
{
	int arr[] = {-5,9,1,0,3,-2,12,8};
	int length = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,length);
	for(auto e:arr) cout<<e<<" ";
	cout<<endl;
	return 0;
}
