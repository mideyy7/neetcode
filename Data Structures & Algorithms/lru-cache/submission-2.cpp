struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val, Node* next = nullptr, Node* prev = nullptr): val(val), next(next), prev(prev){}
};


class LRUCache {
private:
    int capacity{};
    int size{};
    unordered_map<int, pair<int, Node*>> mp;
    Node* left_most;
    Node* right_most;
public:
    LRUCache(int capacity) : capacity(capacity) {
        left_most = new Node(-1);
        right_most = new Node(-1);
        left_most->next = right_most;
        right_most->prev = left_most;   
    }

    void remove_node(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void add_node(Node* node) {
        Node* before = right_most->prev;
        before->next = node;
        node->prev = before;
        node->next = right_most;
        right_most->prev = node;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        pair<int, Node*> p = mp[key];
        remove_node(p.second);
        add_node(p.second);
        return p.first;
    }
    
    void put(int key, int value) {
        Node* n;
        if (mp.find(key) == mp.end()) {
            if (size == capacity) {
                Node* remove = left_most->next;
                remove_node(remove);
                mp.erase(remove->val);
                delete remove;
                size--;
            }
            n = new Node(key);
            size++;
        } else {
            n = mp[key].second;
            remove_node(n);
        }
        mp[key] = {value, n};
        add_node(n);
        
    }
};
