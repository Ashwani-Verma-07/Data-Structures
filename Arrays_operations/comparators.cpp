#include <iostream>
#include <list>
using namespace std;

// template <typename ForwardIterator, typename T,typenama Compare>
template <class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp)
{
    while (start != end)
    {
        if (cmp(*start, key))
        {
            return start;
        }
        start++;
    }
    return end;
}
class Book
{
public:
    string name;
    int price;
    Book() // default constructor
    {
    }
    Book(string name, int price) // parametrized constructor
    {
        this->name = name;
        this->price = price;
    }
};
class Book_compare
{
public:
    bool operator()(Book A, Book B)
    {
        if (A.name == B.name)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Book b1("C++", 100); // old edition
    Book b2("python", 120);
    Book b3("Java", 130);
    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);
    Book booktofind("C", 110); // new edition
    Book_compare cmp;
    // if (cmp(b1, booktofind))
    // {
    //     cout << "True! same Books" << endl;
    // }

    // same as list<book>::iterator it = search(l.begin(), l.end(), booktofind, cmp);
    auto it = search(l.begin(), l.end(), booktofind, cmp);
    if (it != l.end())
    {
        cout << "Book found in the library" << endl;
    }
    else
    {
        cout << "Book not found" << endl;
    }
    // templates,Iterators,comparators
    //  now we get freedom from datatype,containers,different kinds of operations operating on the data
    return 0;
}