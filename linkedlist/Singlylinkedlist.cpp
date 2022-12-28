

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
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

        cout << "memory is free for " << value << endl;
    }
};

// insertion at head O(1)
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);

    temp->next = head;
    head = temp;
}

// insertion at tail O(1)
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

// inserting at position
void insertAtPosition(Node *&head, Node *&tail, int pos, int data)
{

    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Deletion
void deleteNode(int pos, Node *&head)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *current = head;
        Node *prev = NULL;
        int count = 1;

        while (count < pos)
        {
            prev = current;
            current = current->next;
            count++;
        }

        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

// traversing linkedlist
void print_list(Node *&head)
{
    Node *temp = head;

    if (head == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}

int main()
{
    Node *node1 = new Node(4);

    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 33);
    print_list(head);
    // cout << tail->data << endl;

    cout << "After insertion: ";
    insertAtPosition(head, tail, 3, 67);
    print_list(head);

    deleteNode(4, head);

    print_list(head);
}
