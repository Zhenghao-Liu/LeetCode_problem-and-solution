/*
* Graph_map[原图的节点]=深拷贝之后新图对应的节点
* 这里新图的节点不是一步完成的，而是逐渐完善，只是记录了新图节点的位置
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> Graph_map;
        return dfs(node,Graph_map);
    }
    Node* dfs(Node * node,unordered_map<Node*,Node*>& Graph_map)
    {
        if (node==NULL)
            return NULL;
        if (Graph_map.find(node)!=Graph_map.end())
            return Graph_map.at(node);
        Node * p=new Node(node->val,{});
        Graph_map.insert({node,p});
        for (Node* i:node->neighbors)
            p->neighbors.push_back(dfs(i,Graph_map));
        return p;
    }
};
