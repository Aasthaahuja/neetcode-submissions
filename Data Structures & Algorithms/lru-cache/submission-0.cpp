class LRUCache {
public:

    // Doubly Linked List Node
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };

    int limit;

    // key -> node
    unordered_map<int, Node*> m;

    // Dummy head and tail
    Node* head;
    Node* tail;


    LRUCache(int capacity) {

        limit = capacity;

        // Create dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        // Connect head and tail
        head->next = tail;
        tail->prev = head;
    }


    // Add node just after head
    void addNode(Node* newNode) {

        Node* oldNext = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = oldNext;
        oldNext->prev = newNode;
    }


    // Delete a node
    void delNode(Node* oldNode) {

        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }


    int get(int key) {

        // Key doesn't exist
        if(m.find(key) == m.end())
            return -1;

        Node* node = m[key];

        // This node is recently used,
        // so move it to the front
        delNode(node);
        addNode(node);

        return node->val;
    }


    void put(int key, int value) {

        // If key already exists
        if(m.find(key) != m.end()) {

            Node* oldNode = m[key];

            // Remove old node
            delNode(oldNode);
            m.erase(key);
        }


        // If cache is full
        if(m.size() == limit) {

            // Least recently used node
            Node* lru = tail->prev;

            // Remove it from list
            delNode(lru);

            // Remove it from map
            m.erase(lru->key);

            delete lru;
        }


        // Create new node
        Node* newNode = new Node(key, value);

        // Add to front
        addNode(newNode);

        // Store in map
        m[key] = newNode;
    }
};