# Synopsis
Implement [Topological Sorting](https://en.wikipedia.org/wiki/Topological_sorting) in Python and C++.
# Example
**python:**   
![topological sorting](http://i13.tietuku.com/e03d6a73a248d36a.png)    
Run `topologicalsort.py` as    
```
$ python topo.py
Input the number of vertex: 6    
Input the number of edges: 5
Input the edges:
1 6
6 5
4 5
5 3
3 2
4 1 6 5 3 2
```
**C++:**   
Run `topologicalsort.cxx` as    
```
$ g++ --std=gnu++11 topological.cxx    
Input the number of vertex: 6        
Input the number of edges: 5   
Input the edges:   
1 6   
6 5  
4 5  
5 3  
3 2  
4 1 6 5 3 2
```
