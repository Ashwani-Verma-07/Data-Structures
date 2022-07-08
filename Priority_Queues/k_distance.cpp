#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// Finding K distance Cabs:
class Car
{
public:
    string id;
    int x, y;
    Car(string id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist() const
    {
        return x * x + y * y;
    }
};
class CarCompare
{
public:
    bool operator()(const Car A, const Car B)
    {
        return A.dist() < B.dist(); // max-heap
    }
};
void printNearestCars(vector<Car> cars, int k)
{

    // create a max heap of size k;
    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);
    for (int j = k; j < cars.size(); j++)
    {
        auto car = cars[j];
        if (car.dist() < max_heap.top().dist())
        {
            max_heap.pop();
            max_heap.push(car);
        }
    }
    vector<Car> output;

    while (!max_heap.empty())
    {
        output.push_back(max_heap.top());
        max_heap.pop();
    }
    reverse(output.begin(), output.end());
    cout << "Smallest " << k << "Cabs were" << endl;
    for (auto it : output)
    {
        cout << it.id << endl;
    }

    return;
}
int main()
{
    int n, k;
    cout << "Enter Number of cabs: ";
    cin >> n;
    cout << "Enter how many cabs you want nearest :";
    cin >> k;
    string id;
    int x, y;

    vector<Car> cars;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> x >> y;
        Car car(id, x, y);
        cars.push_back(car);
    }
    printNearestCars(cars, k);
}
// Enter Number of cabs: 5
// Enter how many cabs you want nearest :3
// C1 1 1
// C2 2 1
// C3 3 2
// C4 0 1
// C5 2 3
// Smallest 3Cabs were
// C4
// C1
// C2