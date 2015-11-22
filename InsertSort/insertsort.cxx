#include<iostream>
using namespace std;

/*
 * Insert Sort
 *
 */
void insertsort(int arr[],int length)
{
	for(int i = 1; i < length; ++i)
	{
		int tmp = arr[i];
		int j = i - 1;
		while(j > -1 && arr[j] > tmp)
		{
			arr[j+1] = arr[j];
			--j;
		}
		arr[++j] = tmp;
	}
}

int main()
{
	int arr[] = {-1,4,2,3,5,8,-9,10,100,43};
	int len = sizeof(arr) / sizeof(arr[0]);
	insertsort(arr,len);
	for(auto e:arr) cout<<e<<" ";
	cout<<endl;
	return 0;
}
