//Graph_map[原图的节点]=深拷贝之后新图所对应的节点
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
        if (node==NULL)
            return NULL;
        queue<Node*> Graph_queue;
        Graph_queue.push(node);
        Node * head=new Node(node->val,{});
        unordered_map<Node*,Node*> Graph_map;
        Graph_map.insert({node,head});
        while (!Graph_queue.empty())
        {
            //p对应原图的节点
            Node * p=Graph_queue.front();
            Graph_queue.pop();
            //i对应原图中p的下一层
            for (Node * i:p->neighbors)
            {
                if (Graph_map.find(i)==Graph_map.end())
                {
                    Graph_map.insert({i,new Node(i->val,{})});
                    Graph_queue.push(i);
                }
                //通过Graph_map中的p为key值找到深拷贝对应的节点
                Graph_map.at(p)->neighbors.push_back(Graph_map.at(i));
            }
        } 
        return head;      
    }
};
