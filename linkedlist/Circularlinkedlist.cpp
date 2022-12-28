#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }

    ~Node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << " memory free for: " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        // assume element is present in the linkedlist
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = prev->next;

    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    // removing one node
    if (curr == prev)
    {
        tail = NULL;
    }

    if (tail == curr)
    {
        tail = prev;
    }

    curr->next = NULL;
    delete curr;
}

void print_list(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node *temp = tail;

    do
    {
        cout << tail->data << "->";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, -1, 12);
    insertNode(tail, 12, 45);
    insertNode(tail, 45, 88);
    insertNode(tail, 88, 92);

    print_list(tail);
    deleteNode(tail, 12);
    print_list(tail);
}