#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << "Top element " << st.top() << endl;
    cout << "size " << st.size() << endl;
    st.pop();
    cout << "Top element " << st.top() << endl;
    cout << "size " << st.size() << endl;
}