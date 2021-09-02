/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allTrees(int l,int r){
        if(l>r) return {NULL};
        if(l==r) return {new TreeNode(l)};
        
        vector<TreeNode*> ans;
        
        for(int val=l;val<=r;val++){
            vector<TreeNode*> leftSubtrees = allTrees(l,val-1);
            vector<TreeNode*> rightSubtrees = allTrees(val+1,r);
            for(TreeNode* leftSubtree: leftSubtrees){
                for(TreeNode* rightSubtree: rightSubtrees){
                    ans.push_back(new TreeNode(val,leftSubtree,rightSubtree));
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return allTrees(1,n);
    }
};
