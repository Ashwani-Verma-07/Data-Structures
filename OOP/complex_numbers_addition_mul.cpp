#include <iostream>
using namespace std;
int real_1, img_1;
class complex
{
private:
    int real;
    int img;

public:
    complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }
    void print()
    {
        cout << real << "+" << img << "i" << endl;
    }
    void print_1()
    {
        cout << real_1 << "+" << img_1 << "i" << endl;
    }
    void add(complex c2)
    {
        real = real + c2.real;
        img = img + c2.img;
    }
    void mul(complex c2)
    {
        real_1 = real * c2.real - img * c2.img;
        img_1 = this->real * c2.img + img * c2.real;
    }
};
int main()

{
    int real1, real2, cmp1, cmp2, op;
    cout << "Enter real 1: ";
    cin >> real1;
    cout << "Enter complex 1: ";
    cin >> cmp1;
    cout << "Enter real 2: ";
    cin >> real2;
    cout << "Enter complex 2: ";
    cin >> cmp2;
    cout << "Enter choice 1.Add or 2.Multiplication ";
    cin >> op;

    complex c1(real1, cmp1);
    complex c2(real2, cmp2);
    if (op == 1)
    {
        c1.add(c2);
        c1.print();
    }
    if (op == 2)
    {
        c1.mul(c2);
        c1.print_1();
    }
}