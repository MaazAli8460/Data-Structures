#include <iostream>
#include <string>
#include <time.h>

using namespace std;
class HashEntry
{
public:
    int key;
    int val;
    HashEntry()
    {
        key = -1;
        val = -1;
    }
    ~HashEntry();
};
class HashMap
{
public:
    int size = 5;
    HashEntry *arr;
    HashMap()
    {
        arr = new HashEntry[size];
    }
    int HashFunction(int key)
    {
        return key % size;
    }
    void Insert(int key, int val)
    {
        int hash = HashFunction(key);
        bool found = false;
        while (arr[hash].key != -1 && !found)
        {
            if (arr[hash].key == key)
            {
                found = true;
            }
            else
            {
                hash = HashFunction(hash + 1);
            }
        }

        if (found)
        {
            cout << "\nDuplicate items are not allowed.\n";
        }
        else
        {
            arr[hash].key = key;
            arr[hash].val = val;
        }
    }
    int Search(int key)
    {
        int hash = HashFunction(key);
        if (arr[hash].val == -1)
        {
            return -1;
            /* code */
        }
        return arr[hash].val;
    }
    void Insert2(int key, int val)
    {
        srand(time(0));
        int hash = HashFunction(key);
        bool found = false;
        while (arr[hash].key != -1 && found == true)
        {
            if (arr[hash].key == key)
            {
                found = true;
            }
            else
            {
                int val1 = rand() % size;
                hash = HashFunction(hash + val1);
            }
        }

        if (found)
        {
            cout << "\nDuplicate items are not allowed.\n";
        }
        else
        {
            arr[hash].key = key;
            arr[hash].val = val;
        }
    }
    void Insert3(int key, int val)
    {
        int hash = HashFunction(key);
        int val=1;
        bool found = false;
        while (arr[hash].key != -1 && !found)
        {
            if (arr[hash].key == key)
            {
                found = true;
            }
            else
            {
                val=val*val;
                hash = HashFunction(hash + val);
                val++;
            }
        }

        if (found)
        {
            cout << "\nDuplicate items are not allowed.\n";
        }
        else
        {
            arr[hash].key = key;
            arr[hash].val = val;
        }
    }
};
