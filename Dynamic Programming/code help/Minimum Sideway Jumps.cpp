// tle

class Solution {
public:
    
    int solve(vector<int>& obs, int currline,int currpos){
        int n = obs.size()-1;
        
        if(currpos == n){
            return 0;
        }
        
        if(obs[currpos+1] != currline){
            return solve(obs,currline, currpos+1);
        }else{
            // sidejump
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(currline != i && obs[currpos] !=i){
                    ans = min(ans, 1+ solve(obs,i,currpos));
                }
            }
            
            return ans;
        }
        
    }
    
    
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles,2,0);
        
    }
};

////////////////////////////////////////////////////////////////
 // memo

 class Solution {
public:
 
    int solve(vector<int>& obs, int currline,int currpos, vector<vector<int>> &t){
        int n = obs.size()-1;
        
        if(currpos == n){
            return 0;
        }
        
        if(t[currline][currpos] != -1){
            return t[currline][currpos];
        }
        
        
        if(obs[currpos+1] != currline){
            return solve(obs,currline, currpos+1,t);
        }else{
            // sidejump
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(currline != i && obs[currpos] !=i){
                    ans = min(ans, 1+ solve(obs,i,currpos,t));
                }
            }
            
            t[currline][currpos] = ans;
            return t[currline][currpos];
        }
        
    }
    
    
    int minSideJumps(vector<int>& obstacles) {
        
        vector<vector<int>> t(4,vector<int>(obstacles.size(),-1));
        
        return solve(obstacles,2,0,t);
        
    }
};



// table

class Solution
{
	public:

		int solve(vector<int> &obs, int currline, int currpos)
		{
			int n = obs.size() - 1;
			vector<vector < int>> t(4, vector<int> (obs.size(), INT_MAX));

			t[0][n] = 0;
			t[1][n] = 0;
			t[2][n] = 0;
			t[3][n] = 0;

			for (int currpos = n - 1; currpos >= 0; currpos--)
			{
				for (int currline = 1; currline <= 3; currline++)
				{
					if (obs[currpos + 1] != currline)
					{
						t[currline][currpos] = t[currline][currpos + 1];
					}
					else
					{
						// sidejump
						int ans = INT_MAX;
						for (int i = 1; i <= 3; i++)
						{
							if (currline != i && obs[currpos] != i)
							{
								ans = min(ans, 1 + t[i][currpos + 1]);
							}
						}

						t[currline][currpos] = ans;
					}
				}
			}

			return min(t[2][0], min(1 + t[1][0], 1 + t[3][0]));
		}

	int minSideJumps(vector<int> &obstacles)
	{
		return solve(obstacles, 2, 0);
	}
};