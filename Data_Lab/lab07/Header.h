#include <iostream>
using namespace std;

class DoublyNode
{
public:
    DoublyNode *next;
    DoublyNode *priv;

    int data;
    DoublyNode()
    {
        next = NULL;
        priv = NULL;
        data = -1;
    }
    DoublyNode(DoublyNode *temp)
    {
        next = temp->next;
        priv = temp->priv;
        data = temp->data;
        *this = temp;
    }
    int getData()
    {
        return data;
    }
    DoublyNode *getNext()
    {
        return next;
    }
    DoublyNode *getPriv()
    {
        return priv;
    }
    void setData(int data1)
    {
        data = data1;
    }
    void setNext(DoublyNode *Next)
    {
        next = Next;
    }
    void setData(DoublyNode *Priv)
    {
        priv = Priv;
    }
};
class DoublyLinkedList
{
public:
    DoublyNode *head;
    DoublyNode *tail;
    int count;
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    DoublyNode *getHead()
    {
        return head;
    }
    void insert(int data1)
    {
        if (head == NULL)
        {
            head = new DoublyNode;
            tail = head;
            head->next = NULL;
            head->priv = NULL;
            head->data = data1;
            count++;
            return;
        }
        if (count == 1)
        {

            DoublyNode *temp = head;
            temp->next = new DoublyNode;
            temp = temp->next;
            temp->data = data1;
            temp->priv = head;
            temp->next = NULL;
            tail = temp;
            count++;
            return;
        }

        count++;
        tail->next = new DoublyNode;
        DoublyNode *temp = tail;
        tail = tail->next;
        tail->data = data1;
        tail->next = NULL;
        tail->priv = temp;
    }
    void insertToHead(int data1)
    {
        if (head == NULL)
        {
            head = new DoublyNode;
            tail = head;
            head->next = NULL;
            head->priv = NULL;
            head->data = data1;
            count++;
            return;
        }
        DoublyNode *temp = new DoublyNode;
        temp->data = data1;
        temp->next = head;
        temp->priv = NULL;
        head = temp;
        count++;
    }
    bool isEmpty()
    {
        if (count == 0)
        {
            return true;
            /* code */
        }
        return false;
    }
    // Linked list can never be full so no isFULL() function
    bool search(int data1)
    {
        DoublyNode *temp = head;
        while (temp != NULL && temp->next != NULL && temp->data != data1)
        {
            temp = temp->next;
            /* code */
        }
        if (temp->data == data1)
        {
            return true;
        }
        return false;
    }
    void update(int data1, int newdata)
    {
        if (!search(data1))
        {
            return;
        }
        DoublyNode *temp = head;
        while (temp != NULL && temp->data != data1)
        {
            temp = temp->next;
            /* code */
        }
        if (temp->data == data1)
        {
            temp->data = newdata;
        }
    }
    void insertAtIndex(int data1, int index)
    {
        int i = 1;
        DoublyNode *temp = head;
        while (i != index)
        {
            temp = temp->next;
            i++;
        }
        DoublyNode *temp2 = temp->next;
        temp->next = new DoublyNode;
        // DoublyNode* temp3=temp->next;
        temp->next->next = temp2;
        temp2->priv = temp->next;
        temp->priv = temp;
        temp->next->data = data1;
        count++;
    }
    void deleteData(int data1)
    {
        if (!search(data1))
        {
            return;
        }
        DoublyNode *temp = head;
        while (temp != NULL && temp->data != data1)
        {
            temp = temp->next;
            /* code */
        }
        if (temp->data == data1)
        {
            DoublyNode *temp1 = temp;
            temp->priv->next = temp->next;
            temp->next->priv = temp->priv;
            count--;
            delete temp1;
        }
    }
    void print()
    {
        DoublyNode *temp = head;
        cout << endl;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<<endl;

    }
};
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
        data = -1;
    }
    Node(Node *temp)
    {
        next = temp->next;
        data = temp->data;
        *this = temp;
    }
    int getData()
    {
        return data;
    }
    Node *getNext()
    {
        return next;
    }
    void setData(int data1)
    {
        data = data1;
    }
    void setNext(Node *Next)
    {
        next = Next;
    }
};
class CircularLinkedList
{
public:
    Node *head;
    int count;
    CircularLinkedList(/* args */)
    {
        head = NULL;
        count = 0;
    }
    void insert(int data1)
    {
        if (head == NULL)
        {
            head = new Node;
            head->next = head;
            head->data = data1;
            count++;
            return;
        }
        if (count == 1)
        {

            Node *temp = head;
            temp->next = new Node;
            temp = temp->next;
            temp->data = data1;
            temp->next = head;
            count++;
            return;
        }

        count++;
        Node *temp = head;
        Node *temp2 = head;
        while (temp2->next != temp)
        {
            temp2 = temp2->next;
        }
        temp2->next = new Node;
        temp2 = temp2->next;
        temp2->data = data1;
        temp2->next = head;
    }
    Node *getHead()
    {
        return head;
    }
    bool isEmpty()
    {
        if (count == 0)
        {
            return true;
            /* code */
        }
        return false;
    }
    // Linked list can never be full so no isFULL() function
    bool search(int data1)
    {
        Node *temp = head;
        do
        {
            temp = temp->next;
            /* code */
        } while (temp != head && temp->data != data1);
        if (temp->data == data1)
        {
            return true;
        }
        return false;
    }
    void update(int data1, int newdata)
    {
        if (!search(data1))
        {
            return;
        }
        Node *temp = head;
        do
        {
            temp = temp->next;
            /* code */
        } while (temp != head && temp->data != data1);
        if (temp->data == data1)
        {
            temp->data = newdata;
        }
    }
    void insertAtIndex(int data1, int index)
    {
        int i = 1;
        Node *temp = head;
        while (i != index)
        {
            temp = temp->next;
            i++;
        }
        Node *temp2 = temp->next;
        temp->next = new Node;
        // DoublyNode* temp3=temp->next;
        temp->next->next = temp2;
        temp->next->data = data1;
        count++;
    }
    void deleteData(int data1)
    {
        if (!search(data1))
        {
            return;
        }
        Node *temp = head;
        Node *priv = NULL;
        do
        {
            priv = temp;
            temp = temp->next;
            /* code */
        } while (temp != head && temp->data != data1);
        if (temp->data == data1)
        {
            Node *temp1 = temp;
            priv->next = temp->next;
            count--;
            delete temp1;
        }
    }

    void print()
    {
        Node *temp = head;
        cout << endl;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout<<endl;

    }
    int findWinner(int val)
    {
        Node *temp = head;
        Node *priv = NULL;

        int i = 1;
        int winner;
        // count++;
        while (count != 1)
        {
            if (val != 1)
            {
                while (i != val)
                {
                    priv = temp;
                    temp = temp->next;
                    i++;
                }
                Node *temp1 = temp;
                priv->next = temp->next;
                temp = temp->next;
                delete temp1;
                count--;
                i = 1;
            }
            else
            {
                deleteData(temp->data);
                temp = temp->next;
                count--;
            }
        }
        return temp->data;
    }
};
