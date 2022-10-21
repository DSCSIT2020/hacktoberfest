class Solution {
public:
     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
      
      if(root == NULL){
          return root;
        }
    
    if(depth == 1){
        TreeNode* newNode = new TreeNode(val);
        newNode->left = root;
        return newNode;
    }
    
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    int depthCount = 1;
    
    while(depth-depthCount != 1){
        TreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        
        if(front == NULL){
            pendingNodes.push(NULL);
            depthCount++;
        }
        else{
            if(front->left != NULL)
            pendingNodes.push(front->left);
            if(front->right != NULL)
            pendingNodes.push(front->right);
        }
    }
    
    while(pendingNodes.size() != 0){
        TreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        
        if(front == NULL)
            continue;
        
        TreeNode* newNodeLeft = new TreeNode(val);
        TreeNode* newNodeRight = new TreeNode(val); 
        
        newNodeLeft->left = front->left;
        newNodeRight->right = front->right;
        
        front->left = newNodeLeft;
        front->right = newNodeRight;
    }
    
    return root;
     }
};
