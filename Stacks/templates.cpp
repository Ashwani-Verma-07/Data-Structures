#include <iostream>
using namespace std;
template <typename T>
class Pair
{        //                   x    y
    T x; // int x;         -----------
         //                 |int |int|
         //                -----------
    T y; //int y;               p1

    //                      Pair<int,int>p1;
public:
    void setX(T x) //void setX(int x)
    {
        this->x = x;
    }
    T getX() //int getX;
    {
        return x;
    }
    void setY(T y) //void setY(int y)
    {
        this->y = y;
    }
    T getY() //int getY
    {
        return y;
    }
};
int main()
{
    Pair<int> p1; //both x and y are int datatype
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << endl;
    Pair<double> p2; //both x and y are double datatype
    p2.setX(10.24);
    p2.setY(20.56);
    cout << p2.getX() << " " << p2.getY() << endl;
}