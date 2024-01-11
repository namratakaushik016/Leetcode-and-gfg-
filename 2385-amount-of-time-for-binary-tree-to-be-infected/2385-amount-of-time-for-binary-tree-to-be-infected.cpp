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
     unordered_map<int, vector<int>> graph;

    // Find the amount of time needed to infect all nodes starting from the start node
    int amountOfTime(TreeNode* root, int start) {
    // Build graph representation of the tree using DFS
        constructGraph(root);
   // Queue for BFS traversal
        queue<int> q;
        q.push(start);

        // Set to keep track of visited nodes
        unordered_set<int> visited;

        // Variable to track the number of minutes passed
        int minutesPassed = -1;

        // Performing BFS on the graph
        while (!q.empty()) {
            // Increment time for each level
            ++minutesPassed;
            // Iterate over all nodes in the current level
            for (int levelSize = q.size(); levelSize > 0; --levelSize) {
                int currentNode = q.front();
                q.pop();
                visited.insert(currentNode);
                
                
                // Add all unvisited adjacent nodes to the queue
                for (int adjacentNode : graph[currentNode]) {
                    if (!visited.count(adjacentNode)) {
                        q.push(adjacentNode);
                    }
                }
            }
        }

        return minutesPassed;
    }

    
    void constructGraph(TreeNode* root) {
        if (!root) return;

        // Connect current node with its left child (if exists)
        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        // Connect current node with its right child (if exists)
        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }
};