
class Solution {
  private:
    int height(struct Node* node){
        //base case
        if(node == NULL) {
            return 0;
        }
        
        int left = height(node ->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    
    pair<int,int> diameterFast(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        // calculate diyamiter and height
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3)); //diyamiter  (l.d), (r.d),(l.h r.h+1)
        ans.second = max(left.second , right.second) + 1;//height

        return ans;
    }
    int diameter(Node* root) {
    
        return diameterFast(root).first;
        
    }
};

class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
    
private:
    int diameter = 0;
};