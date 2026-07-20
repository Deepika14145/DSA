class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node*> mp;
    Node *head, *tail;
    int cap;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;

        Node* node = mp[key];
        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {

        if (mp.count(key)) {
            Node* node = mp[key];
            remove(node);
            node->val = value;
            insert(node);
            return;
        }

        if (mp.size() == cap) {
            Node* lru = head->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);
        insert(node);
        mp[key] = node;
    }
};