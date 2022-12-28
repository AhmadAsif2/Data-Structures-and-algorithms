#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class linkedlist
{
private:
    Node *head;

public:
    linkedlist()
    {
        head = nullptr;
    }

    void append(int data)
    {
        if (head == nullptr)
        {
            head = new Node{data, nullptr};
            return;
        }

        else
        {
            Node *current = head;

            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = new Node{data, nullptr};
        }
    }

    void prepend(int data)
    {
        if (head == nullptr)
        {
            head = new Node{data, nullptr};
            return;
        }
        else
        {
            Node *temp = new Node{data, nullptr};
            temp->next = head;
            head = temp;
        }
    }

    void insertAtPosition(int pos, int data)
    {
        if (pos == 1)
        {
            prepend(data);
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
            append(data);
            return;
        }

        Node *nodeToInsert = new Node{data, nullptr};
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }

    void print_list()
    {
        if (head == nullptr)
        {
            cout << "Empty list" << endl;
        }
        else
        {
            Node *current = head;

            while (current != NULL)
            {
                cout << current->data << "->";
                current = current->next;
            }
            cout << "null" << endl;
        }
    }
};

int main()
{
    linkedlist ll;
    // ll.prepend(32);
    ll.append(12);
    ll.append(24);
    ll.append(36);
    ll.append(48);

    ll.insertAtPosition(1, 4);

    ll.print_list();
}