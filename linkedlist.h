#include <string>

class Voter
{
private:
public:
    std::string key;        // PIN
    std::string zipcode;    // zipcode
    std::string first_name; // first name
    std::string last_name;  // last name
    bool voted;             // voted or not

    Voter();                                                                                                // default constructor
    Voter(std::string key, std::string zipcode, std::string first_name, std::string last_name, bool voted); // constructor
    void print();                                                                                           // print the voter
};

// Node class
class Node
{
public:
    Voter voter; // voter object
    Node *next;  // pointer to the next node

    Node();            // default constructor
    Node(Voter voter); // constructor
};

class LinkedList
{
private:
    Node *head; // pointer to the head of the linked list
    int LLsize; // size of the linked list

public:
    LinkedList();                           // default constructor
    ~LinkedList();                          // destructor
    bool empty() const;                     // check if the linked list is empty
    int size() const;                       // get the size of the linked list
    void incrementsize();                   // increment the size of the linked list
    Node *front();                          // get the head of the linked list
    Voter *get_Node(std::string PIN) const; // get a voter from the linked list
    void push_front(const Voter &e);        // insert a voter into the linked list
    void rm_front();                        // remove the head of the linked list
    bool rm_Node(std::string PIN);          // remove a voter from the linked list
    void print();                           // print the linked list
    void print(std::string PIN);            // print a voter in the linked list
    bool change_Vote(std::string key);      // change the vote status of a voter
};
