#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;

    Node(string key, T val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <class T>
class HashTable
{
    Node<T> **table;
    int current_size;
    int table_size;

    int hashFn(string key)
    {
        int idx = 0;
        int p = 1;
        for (int j = 0; j < key.length(); j++)
        {
            idx = idx + (key[j] * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }
    void rehash()
    {
        Node<T> **oldTable = table;
        int oldTableSize = table_size;
        table_size = 2 * table_size; // approximation to find prime no.
        table = new Node<T> *[table_size];

        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
        current_size = 0;

        // shift the elements from old table to new table
        for (int i = 0; i < oldTableSize; i++)
        {
            Node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int ts = 7)
    {
        // 7 Node* buckets which is a collection of pointers
        table_size = ts;
        table = new Node<T> *[table_size];
        // Example =>
        // Student s = new student[10];
        // Student **s = new student*[10];
        current_size = 0;
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
    }
    void insert(string key, T value)
    {
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key, value);

        // insert at head of the linked list with id = idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        // rehash...

        // float load_factor = current_size / (1.0 * table_size);
        // if (load_factor > 0.7)
        // {
        //     rehash();
        // }
    }
    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Bucket " << i << " ->";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << " ->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    /*
        T search(string key)
        {
        }
        void erase(string key)
        {
        }
        */
};

int main()
{
    HashTable<int> price_menu;

    price_menu.insert("Paneer wrap", 120);
    price_menu.insert("Pizza Roll", 20);
    price_menu.insert("Paneer Roll", 150);
    price_menu.insert("Pizza patte", 25);
    price_menu.insert("Hot dog", 40);
    // price_menu.insert("Burger", 60);

    price_menu.print();
    return 0;
}