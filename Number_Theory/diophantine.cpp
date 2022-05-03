#include <iostream>
using namespace std;
class Triplet
{
public:
    int x;
    int y;
    int gcd;
};
// Extended Euclid Algorithm
Triplet extendedEuclid(int a, int b)
{
    if (b == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    // a*x1 + b*y1 = c;
    // x = y1;
    // y = x1-(a/b)*y1;
    Triplet smallAns = extendedEuclid(b, a % b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}
int main()
{
    cout << "a*x + b*y = c" << endl;
    int a, b;
    cout << "Enter Value of a : ";
    cin >> a;
    cout << "Enter Value of b : ";
    cin >> b;
    Triplet ans = extendedEuclid(a, b);
    cout << a << "*x + " << b << "*y = "
         << "c" << endl;
    cout << "x is : " << ans.x << endl;
    cout << "y is : " << ans.y << endl;
    cout << "c is : " << ans.gcd << endl;
}