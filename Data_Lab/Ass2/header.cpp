#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node
{
public:
    int id;
    int layer1;
    Node *next;
    Node *priv;
    Node *up;
    Node *down;
    Node()
    {
        next = nullptr;
        priv = nullptr;
        up = nullptr;
        down = nullptr;
        id = -1;
        layer1 = 0;
    }
};
class Transport_Layer_optimization
{
private:
    string str;
    Node *transport;
    Node *h1;
    Node *h2;
    Node *h3;
    Node *path;

    int n, m, q;
    int L;

public:
    Transport_Layer_optimization()
    {
        str = "";
        transport = nullptr;
        h1 = nullptr;
        h2 = nullptr;
        h3 = nullptr;
        path = nullptr;
        n = 0;
        m = 0;
        q = 0;
        L = 3;
    }
    void ReadFile(string filename)
    {
        ifstream tempfile(filename);
        if (!tempfile.is_open())
        {
            cout << "Error opening file: " << filename << endl;
            return;
        }
        tempfile >> n >> m >> q;
        int layer = 1;
        int id;
        for (int i = 0; i < n; i++)
        {
            tempfile >> id;
            addNode(layer, id);
        }
        layer++;
        for (int i = 0; i < m; i++)
        {
            tempfile >> id;
            addNode(layer, id);
        }
        layer++;
        for (int i = 0; i < q; i++)
        {
            tempfile >> id;
            addNode(layer, id);
        }
        tempfile.close();
    }
    void addNode(int layer, int Location_id)
    {
        int i = 1;
        Node *temp = nullptr;
        if (layer == 1)
        {
            temp = h1;
            if (temp == nullptr)
            {
                temp = new Node;
                h1 = temp;
                temp->layer1 = layer;
                temp->id = Location_id;
                return;
            }
        }
        else if (layer == 2)
        {
            temp = h2;
            if (temp == nullptr)
            {
                temp = new Node;
                h2 = temp;
                temp->layer1 = layer;
                temp->id = Location_id;
                return;
            }
        }
        else if (layer == 3)
        {
            temp = h3;
            if (temp == nullptr)
            {
                temp = new Node;
                h3 = temp;
                temp->layer1 = layer;
                temp->id = Location_id;
                return;
            }
        }
        else
        {
            cout << "\nError!! Wrong input\n";
            return;
        }
        while (temp != nullptr && temp->next != nullptr && temp->id < Location_id)
        {
            Node *temp1 = temp;
            temp = temp->next;
            temp->priv = temp1;
            i++;
        }
        if (temp != nullptr && temp->next != nullptr)
        {
            Node *temp1 = new Node;
            temp1->id = Location_id;
            temp1->layer1 = layer;
            temp1->next = temp;
            temp->priv->next = temp1;
            temp1->priv = temp->priv;
            temp->priv = temp1;
            return;
        }
        Node *temp1 = temp->priv;
        temp->next = new Node;
        temp->next->priv = temp1;
        temp = temp->next;
        temp->layer1 = layer;
        temp->id = Location_id;
    }

    void DeleteNode(int layer, int Location_id)
    {
        Node *temp1 = nullptr;
        if (layer == 1)
        {
            temp1 = h1;
        }
        else if (layer == 2)
        {
            temp1 = h2;
        }
        else if (layer == 3)
        {
            temp1 = h3;
        }
        else
        {
            cout << "\nERROR! Layer Not Present\n";
            return;
        }
        while (temp1 != nullptr)
        {
            if (temp1->id != Location_id)
            {
                temp1 = temp1->next;
                continue;
            }
            Node *temp2 = temp1;
            temp1 = temp1->next;
            temp1->priv = temp2->priv;
            temp1 = temp1->priv;
            temp1->next = temp2->next;
            delete temp2;
            temp1 = temp1->next;
        }
    }
    void Map()
    {
        Node *temp1 = h1;
        Node *tempx = h1;
        Node *tempp = h2;
        Node *temp = nullptr;
        while (tempx != nullptr && tempp != nullptr)
        {
            temp = tempp;
            while (tempp->id != tempx->id && tempp->next != nullptr)
            {
                tempp = tempp->next;
            }
            if (tempx->id == tempp->id)
            {
                tempx->down = tempp;
                tempp->up = tempx;
                tempp = tempp->next;
            }
            tempp = temp;
            tempx = tempx->next;
        }
        tempx = h2;
        tempp = h3;
        while (tempx != nullptr && tempp != nullptr)
        {
            temp = tempp;

            while (tempp->id != tempx->id && tempp->next != nullptr)
            {
                tempp = tempp->next;
            }
            if (tempx->id == tempp->id)
            {
                tempx->down = tempp;
                tempp->up = tempx;
                tempp = tempp->next;
            }
            tempp = temp;
            tempx = tempx->next;
        }

        transport = h1;
    }
    // continue from here to check if linked list is printed correct
    string GetPath(int start, int end)
    {
        Map();
        bool rev = false;
        if (end < start)
        {
            rev = true;
            int temp = start;
            start = end;
            end = temp;
        }
        if (start == end)
        {
            return str;
        }
        Node *temp = transport;
        Node *temp1 = nullptr;
        bool fl1 = false;
        for (int i = 1; i <= 3; i++)
        {
            temp1 = find_node(i, start);
            if (temp1 != nullptr)
            {
                path = new Node;
                path->down = temp1->down;
                path->up = temp1->up;
                path->next = temp1->next;
                path->priv = temp1->priv;
                path->id = temp1->id;
                path->layer1 = temp1->layer1;
                if (path->up == nullptr && path->down == nullptr && path->next != nullptr && path->priv != nullptr)
                {
                    if (path->id + 1 != path->next->id)
                    {
                        if (path->id - 1 != path->priv->id)
                        {
                            continue;
                        }
                    }
                }
                fl1 = true;
                start++;
                break;
            }
        }
        if (fl1 == false)
        {
            return str;
        }
        Node *p = path;
        bool fl2 = false;
        temp = nullptr;
        temp1 = nullptr;
        while (start <= end)
        {

            if (p->layer1 == 1)
            {
                temp = find_node(p->layer1, start);
                if (temp != nullptr && temp->next != nullptr)
                {
                    temp1 = new Node;
                    temp1->down = temp->down;
                    temp1->up = temp->up;
                    temp1->next = temp->next;
                    temp1->priv = p;
                    temp1->id = temp->id;
                    temp1->layer1 = temp->layer1;
                    p->next = temp1;
                    p = p->next;
                    start++;
                }
                else
                {
                    Node *temp3 = nullptr;
                    while (p->down == nullptr)
                    {
                        temp3 = p;
                        p = p->priv;
                        delete temp3;
                        temp3 = nullptr;
                        p->next = nullptr;
                    }
                    temp1 = new Node;
                    temp1->down = p->down->down;
                    temp1->up = p->down->up;
                    temp1->next = p->down->next;
                    temp1->priv = p;
                    temp1->id = p->down->id;
                    temp1->layer1 = p->down->layer1;
                    p->next = temp1;
                    p = p->next;
                }
            }
            if (p->layer1 == 2)
            {
                temp = find_node(p->layer1, start);
                bool checkup = false;
                bool checkdown = false;
                if (temp != nullptr && temp->up == nullptr)
                {
                    temp1 = new Node;
                    temp1->down = temp->down;
                    temp1->up = temp->up;
                    temp1->next = temp->next;
                    temp1->priv = p;
                    temp1->id = temp->id;
                    temp1->layer1 = temp->layer1;
                    p->next = temp1;
                    p = p->next;
                    start++;
                }
                else if (temp != nullptr && temp->up != nullptr)
                {
                    if (temp->up->next != nullptr)
                    {
                        temp1 = new Node;
                        temp1->down = temp->down;
                        temp1->up = temp->up;
                        temp1->next = temp->next;
                        temp1->priv = p;
                        temp1->id = temp->id;
                        temp1->layer1 = temp->layer1;
                        p->next = temp1;
                        p = p->next;
                        start++;
                    }

                    if (p->id == end)
                    {
                        cout << "in break:" << p->id << " Layer:" << p->layer1;
                        break;
                    }
                    temp1 = new Node;
                    temp1->down = temp->up->down;
                    temp1->up = temp->up->up;
                    temp1->next = temp->up->next;
                    temp1->priv = p;
                    temp1->id = temp->up->id;
                    temp1->layer1 = temp->up->layer1;
                    p->next = temp1;
                    p = p->next;
                }

                else
                {
                    if (temp != nullptr && temp->up != nullptr)
                    {
                        checkup = true;
                    }
                    else
                    {
                        checkdown = true;
                    }
                    Node *temp3 = nullptr;
                    Node *temp4 = p;

                    temp3 = nullptr;
                    temp4 = p;
                    while (temp4->down == nullptr)
                    {
                        temp3 = temp4;
                        temp4 = temp4->priv;
                        delete temp3;
                        temp3 = nullptr;
                        temp4->next = nullptr;
                    }
                    temp1 = new Node;
                    temp1->down = temp4->down->down;
                    temp1->up = temp4->down->up;
                    temp1->next = temp4->down->next;
                    temp1->priv = temp4;
                    temp1->id = temp4->down->id;
                    temp1->layer1 = temp4->down->layer1;
                    p->next = temp1;
                    p = p->next;
                    continue;
                }
            }
            if (p->layer1 == 3)
            {
                temp = find_node(p->layer1, start);
                bool checkup = false;
                if (temp != nullptr && temp->up == nullptr)
                {
                    temp1 = new Node;
                    temp1->down = temp->down;
                    temp1->up = temp->up;
                    temp1->next = temp->next;
                    temp1->priv = p;
                    temp1->id = temp->id;
                    temp1->layer1 = temp->layer1;
                    p->next = temp1;
                    p = p->next;
                    start++;
                }
                else if (temp != nullptr && temp->up != nullptr)
                {
                    if (temp->up->next != nullptr)
                    {
                        temp1 = new Node;
                        temp1->down = temp->down;
                        temp1->up = temp->up;
                        temp1->next = temp->next;
                        temp1->priv = temp;
                        temp1->id = temp->id;
                        temp1->layer1 = temp->layer1;
                        p->next = temp1;
                        p = p->next;
                    }
                    if (p->id == end)
                    {
                        cout << "in break:" << p->id << " Layer:" << p->layer1;
                        break;
                    }
                    temp1 = new Node;
                    temp1->down = temp->up->down;
                    temp1->up = temp->up->up;
                    temp1->next = temp->up->next;
                    temp1->priv = temp;
                    temp1->id = temp->up->id;
                    temp1->layer1 = temp->up->layer1;
                    p->next = temp1;
                    p = p->next;
                }
                else
                {
                    cout << "\nERROR!->STATION NOT PRESENT\n";
                    break;
                }
            }
        }
        p->next = nullptr;
        path->priv = nullptr;

        if (rev == true)
        {
            return str = To_String_rev(p);
        }
        return str = To_String();
    }
    string To_String_rev(Node *p)
    {
        string str1 = "";
        Node *temp = p;
        // str1 += static_cast<char>(id1)+ "-" + static_cast<char>(layer)+ " -> ";
        str1 = to_string(temp->id) + "-" + to_string(temp->layer1);
        temp = temp->priv;
        while (temp != nullptr)
        {
            if (temp->priv != nullptr)
            {
                if (temp->id == temp->priv->id && temp->layer1 == temp->priv->layer1)
                {
                    temp = temp->priv;
                    continue;
                }
            }
            str1 += " -> ";
            str1 += to_string(temp->id) + "-" + to_string(temp->layer1);
            temp = temp->priv;
        }
        // cout<<endl;
        return str1;
    }
    string To_String()
    {
        string str1 = "";
        Node *temp = path;
        // str1 += static_cast<char>(id1)+ "-" + static_cast<char>(layer)+ " -> ";
        str1 = to_string(temp->id) + "-" + to_string(temp->layer1);
        temp = temp->next;
        while (temp != nullptr)
        {
            if (temp->next != nullptr)
            {
                if (temp->id == temp->next->id && temp->layer1 == temp->next->layer1)
                {
                    temp = temp->next;
                    continue;
                }
            }
            str1 += " -> ";
            str1 += to_string(temp->id) + "-" + to_string(temp->layer1);
            temp = temp->next;
        }
        // cout<<endl;
        return str1;
    }
    bool checkNext(Node *temp)
    {
        if (temp->next == nullptr)
        {
            return false;
        }

        if (temp->id + 1 == temp->next->id)
        {
            return true;
        }
        return false;
    }

    bool checkPriv(Node *temp)
    {
        if (temp->priv != nullptr)
        {
            return false;
        }
        if (temp->id - 1 == temp->priv->id && temp->priv != nullptr)
        {
            return true;
        }
        return false;
    }

    Node *find_node(int layer, int l_id)
    {
        Node *temp = transport;
        bool found = false;
        while (temp->layer1 != layer)
        {
            while (temp->down == nullptr && temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp = temp->down;
        }
        while (temp->next != nullptr && temp->id != l_id)
        {
            temp = temp->next;
        }
        if (temp->id == l_id)
        {
            found = true;
            return temp;
        }
        return nullptr;
    }
    void print()
    {
        int i = 1, c1, c2, c3;
        Node *temp = h2;
        while (i == 1 && temp != nullptr)
        {
            i++;
            Node *temp1 = temp;
            while (temp1 != nullptr)
            {
                cout << temp1->id << "->";
                temp1 = temp1->next;
            }
            cout << endl;
            // temp = h2;
        }
        cout << endl;
        temp = h1;
        i = 1;
        while (i == 1 && temp != nullptr)
        {
            i++;
            Node *temp1 = temp;
            while (temp1 != nullptr)
            {
                cout << temp1->id << "->";
                temp1 = temp1->next;
            }
            cout << endl;
            // temp = h2;
        }
        Node *temp1 = h1;

        while (temp1 != nullptr)
        {
            cout << "|  ";
            temp1 = temp1->next;
        }
        cout << endl;
        temp1 = h1;

        while (temp1 != nullptr)
        {
            cout << "V  ";
            temp1 = temp1->next;
        }
        cout << endl;
        temp1 = h1;

        while (temp1 != nullptr)
        {
            if (temp1->down != nullptr)
            {
                cout << temp1->down->id << "->";
                temp1 = temp1->next;
            }
            else
            {
                cout << "L  ";
                temp1 = temp1->next;
            }
        }
        cout << endl;
    }

    ~Transport_Layer_optimization()
    {
        // delete transport;
    }
};
// class Transport_Cost_Calculator
// {
// public:
//     Node *h1;
//     Node *h2;
//     Node *h3;
//     int size;
//     int extra = 5;
//     int cost;
//     int var;
//     Transport_Cost_Calculator()
//     {
//         h1 = nullptr;
//         h2 = nullptr;
//         h3 = nullptr;
//         cost = 0;
//         size = 0;
//         var=0;
//     }
//     void ReadFile(string filename)
//     {
//         ifstream tempfile(filename);
//         if (!tempfile.is_open())
//         {
//             cout << "Error opening file: " << filename << endl;
//             return;
//         }
//         tempfile >> size;
//         int layer = 1;
//         int id;
//         for (int i = 1; i < size; i++)
//         {
//             tempfile >> id;
//             addNode(layer, id);
//         }
//         layer++;
//         for (int i = 1; i < size; i++)
//         {
//             tempfile >> id;
//             addNode(layer, id);
//         }
//         layer++;
//         for (int i = 1; i < size; i++)
//         {
//             tempfile >> id;
//             addNode(layer, id);
//         }
//         tempfile.close();
//     }
//     void addNode(int layer, int Location_id)
//     {
//         int i = 1;
//         Node *temp = nullptr;
//         if (layer == 1)
//         {
//             temp = h1;
//             if (temp == nullptr)
//             {
//                 temp = new Node;
//                 h1 = temp;
//                 temp->layer1 = layer;
//                 temp->id = Location_id;
//                 return;
//             }
//         }
//         else if (layer == 2)
//         {
//             temp = h2;
//             if (temp == nullptr)
//             {
//                 temp = new Node;
//                 h2 = temp;
//                 temp->layer1 = layer;
//                 temp->id = Location_id;
//                 return;
//             }
//         }
//         else if (layer == 3)
//         {
//             temp = h3;
//             if (temp == nullptr)
//             {
//                 temp = new Node;
//                 h3 = temp;
//                 temp->layer1 = layer;
//                 temp->id = Location_id;
//                 return;
//             }
//         }
//         else
//         {
//             cout << "\nError!! Wrong input\n";
//             return;
//         }
//         while (temp != nullptr && temp->next != nullptr && temp->id < Location_id)
//         {
//             Node *temp1 = temp;
//             temp = temp->next;
//             temp->priv = temp1;
//             i++;
//         }
//         if (temp != nullptr && temp->next != nullptr)
//         {
//             Node *temp1 = new Node;
//             temp1->id = Location_id;
//             temp1->layer1 = layer;
//             temp1->next = temp;
// //            temp->priv->next = temp1;
//             temp1->priv = temp->priv;
//             temp->priv = temp1;
//             return;
//         }
//         Node *temp1 = temp->priv;
//         temp->next = new Node;
//         temp->next->priv = temp1;
//         temp = temp->next;
//         temp->layer1 = layer;
//         temp->id = Location_id;
//     }
//     void Map()
//     {
//         Node *temp1 = h1;
//         Node *tempx = h1;
//         Node *tempp = h2;
//         Node *temp = nullptr;
//         while (tempx != nullptr && tempp != nullptr)
//         {
//             temp = tempp;
//             while (tempp->id != tempx->id && tempp->next != nullptr)
//             {
//                 tempp = tempp->next;
//             }
//             if (tempx->id == tempp->id)
//             {
//                 tempx->down = tempp;
//                 tempp->up = tempx;
//                 tempp = tempp->next;
//             }
//             tempp = temp;
//             tempx = tempx->next;
//         }
//         tempx = h2;
//         tempp = h3;
//         while (tempx != nullptr && tempp != nullptr)
//         {
//             temp = tempp;

//             while (tempp->id != tempx->id && tempp->next != nullptr)
//             {
//                 tempp = tempp->next;
//             }
//             if (tempx->id == tempp->id)
//             {
//                 tempx->down = tempp;
//                 tempp->up = tempx;
//                 tempp = tempp->next;
//             }
//             tempp = temp;
//             tempx = tempx->next;
//         }
//     }
//     int GetMinCost(int start, int end)
//     {
//         Map();
//         int cost1=0,cost2=0,cost3=0;
//         int layer=1;
//         Node* temp=nullptr;
//         int i=1;
//         while (i!=start)
//         {
//             h1=h1->next;
//             h2=h2->next;
//             h3=h3->next;
//             i++;
//         }
//         if (layer==1)
//         {
//             temp=h1;
//             var=start;
//             permutation(var,end,temp,cost1);
//             //cout<<"\nCost:"<<cost1;

//             layer++;
//         }
//         if(layer==2)
//         {
//             temp=h2;
//             var=start;
//             permutation(var,end,temp,cost2);

//             layer++;
//         }
//         if(layer==3)
//         {
//             temp=h3;
//             var=start;
//             permutation(var,end,temp,cost3);

//             layer++;
//         }
//         if (cost1<cost2)
//         {
//             if (cost1<cost3)
//             {
//                 return cost1;
//             }
//         }
//         if (cost2<cost1)
//         {
//             if (cost2<cost3)
//             {
//                 return cost2;
//             }
//         }
//         if (cost3<cost2)
//         {
//             if (cost3<cost1)
//             {
//                 return cost3;
//             }
//         }

//         return cost;
//     }
//     void permutation(int start,int end,Node* temp,int &costt )
//     {
//         if(start==end)
//         {
//             return;
//         }

//         if(temp->down!=nullptr)
//         {
//             permutation(start,end,temp->down,costt);
//             costt+=5;

//         }
//         if (temp->up!=nullptr)
//         {
//             permutation(start,end,temp->up,costt);
//             costt+=5;
//         }
//         if (temp->next!=nullptr)
//         {
//             start++;
//             permutation(start,end,temp->next,costt);
//             costt+=temp->id;

//         }

//     }
// };
// int main()
// {
//     Transport_Layer_optimization obj;
//     obj.ReadFile("Q1T4.txt");
//     string result = obj.GetPath(1, 9);
//     cout<<result<<endl;
//     return 0;
// }
