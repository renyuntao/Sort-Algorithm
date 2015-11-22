#include<iostream>
#include<ctime>
#include<utility>
#include<random>
using std::cout;
using std::cin;
using std::endl;


void quicksort(int a[],int lo,int hi)
{
	int i = lo, j = (lo + hi) / 2, k = hi;
	int pivot;
	if(a[k] < a[i])             // Median of 3
		std::swap(a[k],a[i]);
	if(a[j] < a[i])
		std::swap(a[j],a[i]);
	if(a[k] < a[j])
		std::swap(a[k],a[j]);
	pivot = a[j];
	while(i <= k)               // Partition
	{
		while(a[i] < pivot)  ++i;    // Note: no '='
		while(a[k] > pivot) --k;     // Note: no '='
		if(i <= k)
		{
			std::swap(a[i],a[k]);
			++i;
			--k;
		}
	}
	if(lo < k)                 // recurse
		quicksort(a,lo,k);
	if(i < hi)
		quicksort(a,i,hi);
}

void generateRandData(int *randArr,int size,int seed)
{
	std::uniform_int_distribution<unsigned> u(0,10000);
	std::default_random_engine e(seed);
	for(int i = 0; i < size; ++i)
		randArr[i] = u(e);
}


int main()
{
	int *arr = new int[5000000];
	int seed;
	cout<<"Input seed:";
	cin>>seed;

	generateRandData(arr,5000000,seed);

	clock_t start = clock();
	quicksort(arr,0,4999999);
	clock_t end = clock();
	cout<<"time:"<<static_cast<float>(end-start)/CLOCKS_PER_SEC<<endl;
	delete [] arr;
	return 0;
}
