#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector < int>> umap;

int main()
{
    int manager[17] = {-1,0,0,1,1,2,2,3,3,4,4,5,6,7,7,8,8};

	// Fill umap
	for (int i = 0; i < 17; i++)
	{
		int val = manager[i];
		if (val != -1)
		{
			umap[val].push_back(i);
		}
	}
	
	
	  for (auto x : umap){
	      cout << x.first << " " << "-> " ;
	      
	      for(auto y: x.second){
	          cout<<y<<" ";
	      }
	      
	      cout<<endl;
	  }
      

	return 0;

}