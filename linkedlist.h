#include <string>

class Voter
{
private:
public:
    std::string key;
    std::string zipcode;
    std::string first_name;
    std::string last_name;
    bool voted;

    Voter();
    Voter(std::string key, std::string zipcode, std::string first_name, std::string last_name, bool voted);
    void print();
};

class Node
{
public:
    Voter voter;
    Node *next;

    Node();
    Node(Voter voter);
};

class LinkedList
{
private:
    Node *head;
    int LLsize;

public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    int size() const;
    void incrementsize();
    Node *front();
    Voter *get_Node(std::string PIN) const;
    void push_front(const Voter &e);
    void rm_front();
    bool rm_Node(std::string PIN);
    void print();
    void print(std::string PIN);
    bool change_Vote(std::string key);
};
