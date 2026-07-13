/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node*,Node*> map1;
    Node* cloneGraph(Node* node) {
         if(node==nullptr)
         {
            return nullptr;
         }
         else
         {
            return dfs(node);
         }          
    }
    private:
    Node* dfs(Node* node)
        {
            if(map1.find(node) != map1.end())
            {
                return map1[node];
            }
            else
            {
                Node* copy = new Node(node->val);
                map1[node]=copy;
                for(auto & nei : node->neighbors )
                {
                    copy->neighbors.push_back(dfs(nei));
                }
                return copy;
            }
            
        }
};