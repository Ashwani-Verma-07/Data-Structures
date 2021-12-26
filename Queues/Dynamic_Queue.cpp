#include <iostream>
using namespace std;
class queueusingarray
{
    int *data;
    int nextindex;
    int firstindex;
    int size;
    int capacity;

public:
    queueusingarray(int s)
    {
        data = new int[s];
        nextindex = 0;
        firstindex = -1;
        size = 0;
        capacity = s;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    //insert element
    void enqueue(int element)
    {
        if (size == capacity)
        {
            int *newData = new int[2 * capacity];
            int j = 0;
            for (int i = firstindex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstindex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            firstindex = 0;
            nextindex = capacity;
            capacity *= 2;
        }
        data[nextindex] = element;
        nextindex = (nextindex + 1) % capacity;
        if (firstindex == -1)
        {
            firstindex = 0;
        }
        size++;
    }
    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is full!" << endl;
            return 0;
        }
        return data[firstindex];
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is full!" << endl;
            return 0;
        }
        int ans = data[firstindex];
        firstindex = (firstindex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstindex = -1;
            nextindex = 0;
        }
        return ans;
    }
};
int main()
{
    queueusingarray q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
}