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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr){

            if(!curr->left){
                ans.push_back(curr->val);
                curr=curr->right;
            }

            else{
                TreeNode* pred = curr->left;
                while(pred->right!=curr && pred->right){
                    pred = pred->right;
                }

                if(!pred->right){
                    pred->right = curr;
                    curr=curr->left;
                } 
                else{
                    pred->right = nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
