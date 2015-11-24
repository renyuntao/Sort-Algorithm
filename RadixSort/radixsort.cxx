#include<iostream>
#include<vector>
#include<queue>
using std::cout;
using std::endl;

/*
 * The Data that feed to the Radix Sort 
 * should >= 0.
 * d:radix;  m:Maximum length of number from arr
 */
void radixsort(int arr[],int len,int d,int m)
{
	std::vector<std::queue<int>> v(d);
	int k;

	for(int i = 0; i < m; ++i)
	{
		if(i == 0)
			k = 1;
		else
			k *= d;

		for(int j = 0; j < len; ++j)
		{
			int tmp = arr[j]/k - d*(arr[j]/(k*d));
			v[tmp].push(arr[j]);
		}

		for(int j = 0, q = 0; j < d; ++j)
		{
			while(!v[j].empty())
			{
				arr[q++] = v[j].front();
				v[j].pop();
			}
		}
	}
}

int main(void)
{
	int arr[] = {1,0,6,9,14,3,12,34,13,56};
	int len = sizeof(arr) / sizeof(arr[0]);
	radixsort(arr,len,10,2);
	for(auto e:arr) cout<<e<<" ";
	cout<<endl;
	return 0;
}
