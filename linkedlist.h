class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void insert(int key, int value);
    int get(int key);
    void remove(int key);
    void print();
private:
    struct Node {
        int key;
        int value;
        Node* next;
    };
    Node* head;
};


