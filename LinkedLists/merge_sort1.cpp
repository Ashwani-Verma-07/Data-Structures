// C++ code for linked list merged sort
#include <bits/stdc++.h>
using namespace std;

// Link list node
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// Merging two sorted lists.
node *MergeSortedList(node *lst1, node *lst2)
{
    node *result = NULL;

    // Base Cases
    if (lst1 == NULL)
        return (lst2);
    else if (lst2 == NULL)
        return (lst1);

    // recursively merging two lists
    if (lst1->data <= lst2->data)
    {
        result = lst1;
        result->next = MergeSortedList(lst1->next, lst2);
    }
    else
    {
        result = lst2;
        result->next = MergeSortedList(lst1, lst2->next);
    }
    return result;
}

// Splitting two into halves.
// If the size of the list is odd, then extra element goes in the first list.
void SplitList(node *source, node **front, node **back)
{
    node *ptr1;
    node *ptr2;
    ptr2 = source;
    ptr1 = source->next;

    // ptr1 is incrmented twice and ptr2 is icremented once.
    while (ptr1 != NULL)
    {
        ptr1 = ptr1->next;
        if (ptr1 != NULL)
        {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
    }

    // ptr2 is at the midpoint.
    *front = source;
    *back = ptr2->next;
    ptr2->next = NULL;
}

// Merge Sort
void MergeSort(node **thead)
{
    node *head = *thead;
    node *ptr1;
    node *ptr2;

    // Base Case
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    // Splitting list
    SplitList(head, &ptr1, &ptr2);

    // Recursively sorting two lists.
    MergeSort(&ptr1);
    MergeSort(&ptr2);

    // Sorted List.
    *thead = MergeSortedList(ptr1, ptr2);
}
// Printing List.
void printList(node *tnode)
{
    while (tnode != NULL)
    {
        cout << tnode->data << " ";
        tnode = tnode->next;
    }
}
// Push function for inserting nodes in the list.

node *input()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newaddress = new node(data); //dynamic memory allocation
        if (head == NULL)
        {
            head = newaddress;
            tail = newaddress;
        }
        else
        {
            tail->next = newaddress;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
// Driver Program.
int main()
{
    // Empty list
    node *res = NULL;
    node *MyList = input();

    // List: 10->4->15->1->2->12->54

    cout << "Unsorted Linked List: ";
    printList(MyList);
    cout << "\n";

    MergeSort(&MyList);

    cout << "Sorted Linked List: ";
    printList(MyList);

    return 0;
}