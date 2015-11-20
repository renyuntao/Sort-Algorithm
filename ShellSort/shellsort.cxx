#include<iostream>
using namespace std;

/*
 * Shell Sort
 */
void shellsort(int arr[],int length)
{
	int span = length >> 1;
	while(span > 0)
	{
		for(int k = 0; k < span; ++k)
		{
			// Insert Sort
			for(int i = k; i < length - span; i += span)
			{
				int tmp = arr[i+span];
				int j = i;
				while(j > -1 && arr[j] > tmp)
				{
					arr[j+span] = arr[j];
					j -= span;
				}
				arr[j+span] = tmp;
			}
		}
		span >>= 1;
	}
}

int main()
{
	int arr[] = {1,0,4,9,-3,-5,8,12,65,29,-14};
	int len = sizeof(arr) / sizeof(arr[0]);
	shellsort(arr,len);
	for(auto e:arr) cout<<e<<" ";
	cout<<endl;
	return 0;
}

