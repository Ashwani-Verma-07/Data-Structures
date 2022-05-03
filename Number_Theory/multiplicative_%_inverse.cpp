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
int multiplicative(int a, int m)
{
    Triplet ans = extendedEuclid(a, m);
    return ans.x;
}
int main()
{
    cout << "a*b mod(m) = 1" << endl;
    // gcd(a,m) = 1
    // a*b + m*Q = gcd(a,m)
    int a, m;
    cout << "Enter Value of a : ";
    cin >> a;
    cout << "Enter Value of m : ";
    cin >> m;
    int ans = multiplicative(a, m);
    cout << "Multiplicative Modulo invese is : " << ans << endl;
}