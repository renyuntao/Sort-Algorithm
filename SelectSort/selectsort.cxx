#include<iostream>
using std::cout;
using std::endl;

/*
 * Select Sort
 *
 */
void selectsort(int arr[],int length)
{
	if(!arr || length < 2)
		return;
	for(int i = 0; i < length - 1; ++i)
	{
		int small = i;
		for(int j = i + 1; j < length; ++j)
		{
			if(arr[j] < arr[small])
				small = j;
		}
		if(small != i)
		{
			int tmp = arr[i];
			arr[i] = arr[small];
			arr[small] = tmp;
		}
	}
}

int main(void)
{
	int arr[] = {1,0,6,9,4,3,-5,-76,8,10};
	int len = sizeof(arr) / sizeof(arr[0]);
	selectsort(arr,len);
	for(auto e:arr) cout<<e<<" ";
	cout<<endl;
	return 0;
}
