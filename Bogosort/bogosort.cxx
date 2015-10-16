#include<iostream>
#include<algorithm>
using std::cout;
using std::endl;

inline bool inOrder(int *arr,size_t len)
{
	for(int i = 0;i < len-1;++i)
	{
		if(arr[i] > arr[i+1])
			return false;
	}
	return true;
}

int main()
{
	int arr[] {5,0,3,8,-1,9,20,18,-8};
	auto len = sizeof(arr)/sizeof(int);
	while(!inOrder(arr,len))
	{
		std::random_shuffle(std::begin(arr),std::end(arr));
	}
	for(auto e:arr) cout<<e<<" ";
	cout<<endl;
	return 0;
}
