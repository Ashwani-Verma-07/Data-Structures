#include <iostream>
using namespace std;
template <typename T, typename V>
// class Pair
// {        //                   x    y
//     T x; // int x;         -----------
//          //                 |int |int|
//          //                -----------
//     T y; //int y;               p1

//     //                      Pair<int,int>p1;
// public:
//     void setX(T x) //void setX(int x)
//     {
//         this->x = x;
//     }
//     T getX() //int getX;
//     {
//         return x;
//     }
//     void setY(T y) //void setY(int y)
//     {
//         this->y = y;
//     }
//     T getY() //int getY
//     {
//         return y;
//     }
// };
class Pair ///////////////////// x        y
{          //                   x,y       y
    T x;   // int x;         ------------------
           //                 ||int,int| int|
           //                ------------------
    V y;   //int y;               p1

    //                      Pair<int,double>p1;
public:
    void setX(T x) //void setX(int x)
    {
        this->x = x;
    }
    T getX() //int getX;
    {
        return x;
    }
    void setY(V y) //void setY(int y)
    {
        this->y = y;
    }
    V getY() //int getY
    {
        return y;
    }
};
int main()
{
    Pair<Pair<int, int>, int> p1;
    // Pair<int, double> p1; //both x and y are int datatype and double datatype.
    // p1.setX(10);
    // p1.setY(20.234);
    // cout << p1.getX() << " " << p1.getY() << endl;
    Pair<int, int> p2;
    p2.setX(10);
    p2.setY(15);
    p1.setX(p2);
    p1.setY(20);
    cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;
}