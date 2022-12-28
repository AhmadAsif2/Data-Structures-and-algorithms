/*
    In double linked list we maintain two pointers
    one pointer holds the next node address and the other pointer holds the previous node address
*/

#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "Memory free for: " << value << endl;
    }
};

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *node = new Node(data);
        head = node;
        tail = node;
    }

    else
    {
        // create new node
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else
    {
        // create new node
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

int getLength(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return -1;
    }

    Node *curr = head;
    int len = 0;

    while (curr != NULL)
    {
        curr = curr->next;
        len++;
    }

    return len;
}

void print_list(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "null" << endl;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    Node *temp = head;
    int count = 1;

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteAtPosition(int pos, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    int count = 1;

    while (count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr->next == NULL)
    {
        tail = prev;
        prev->next = curr->next;
        curr->prev = NULL;
        delete curr;
        return;
    }

    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, tail, 89);
    insertAtTail(head, tail, 34);
    insertAtHead(head, tail, 44);
    insertAtTail(head, tail, 8);
    insertAtPosition(head, tail, 5, 10);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    print_list(head);

    deleteAtPosition(5, head, tail);
    print_list(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    cout << "Length of linekdlist: " << getLength(head) << endl;
}
