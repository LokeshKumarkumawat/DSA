class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {       
        wordList.push_back(beginWord);
        int N = wordList.size();
        
        //Construct the Adjacency list, add an edge only if it's HammingDistance it's 1
        vector<vector<int>> adj(N, vector<int>());
        for(int i = 0; i < wordList.size(); i++)
          for(int j = 0; j < wordList.size(); j++)  
              if(hammingDistance(wordList[i], wordList[j]) == 1)
                  adj[i].push_back(j);
        
        //Standard BFS
        unordered_set<int> visited;
        queue<int> q;
        q.push(N-1);
        visited.insert(N-1);
        int diff = 1;
        while(!q.empty())
        {
            int qSize = q.size();
            while(qSize > 0)
            {
                int curr = q.front();
                q.pop();
                if(wordList[curr] == endWord)
                    return diff;
                for(int  x : adj[curr])
                {
                    if(visited.count(x) <= 0)
                    {
                        visited.insert(x);
                        q.push(x);
                    }
                }
                qSize--;
            }
            diff++;
        }
        return 0;
    }
    
    int hammingDistance(string& s1, string& s2)
    {
        int count = 0;
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
                count += 1;
        }
        return count;
    }
};