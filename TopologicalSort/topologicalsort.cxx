#include<iostream>
#include<vector>
#include<stack>
using std::cout;
using std::endl;

void topologicalsort(int **graph,int vertex_num)
{
	std::stack<int> S;
	std::vector<int> L;
	for(int col = 0;col < vertex_num;++col)    //initial S
	{
		bool have_incoming_edge = false;
		for(int row = 0;row < vertex_num;++row)
		{
			if(graph[row][col] == 1)
			{
				have_incoming_edge = true;
				break;
			}
		}
		if(!have_incoming_edge)
			S.push(col);
	}
	std::vector<int> test_node;
	while(!S.empty())
	{
		test_node.clear();
		int tmp = S.top();
		S.pop();
		L.push_back(tmp);
		for(int col = 0;col < vertex_num;++col)
		{
			if(graph[tmp][col] == 1)
			{
				graph[tmp][col] = 0;
				test_node.push_back(col);
			}
		}
		for(int i = 0;i < test_node.size();++i)
		{
			int t_node = test_node[i];
			bool have_incoming_edge = false;
			for(int row = 0;row < vertex_num;++row)
			{
				if(graph[row][t_node] == 1)
				{
					have_incoming_edge = true;
					break;
				}
			}
			if(!have_incoming_edge)
				S.push(t_node);
		}
	}
	for(auto e:L) cout<<e+1<<" ";
	cout<<endl;
}

int main()
{
	int vertex_num,edge_num;
	cout<<"Input the nuber of vertex:";
	std::cin>>vertex_num;
	int **graph = new int*[vertex_num];
	for(int i = 0;i < vertex_num;++i)
		graph[i] = new int[vertex_num];
	cout<<"Input the number of edge:";
	std::cin>>edge_num;
	cout<<"Input the edges:\n";
	for(int i = 0;i < edge_num;++i)
	{
		int src,des;
		std::cin>>src>>des;
		--src;
		--des;
		graph[src][des] = 1;
	}

	topologicalsort(graph,vertex_num);

	for(int i = 0;i < vertex_num;++i)
		delete [] graph[i];
	delete [] graph;
}
