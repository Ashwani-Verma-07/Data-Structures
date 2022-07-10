#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> mergeKArrays(vector<vector<int>> arrays)
{
    int k = arrays.size();

    // triplet ->element,array index,element index

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

    vector<int> output;
    // initialize the heap
    for (int i = 0; i < k; i++)
    {
        int element = arrays[i][0];
        q.push({element, i, 0});
    }

    // start popping & pushing more elements
    while (!q.empty())
    {
        auto top = q.top();
        q.pop();
        int element = top[0];
        int array_index = top[1];
        int element_index = top[2];

        output.push_back(element);

        if (element_index + 1 < arrays[array_index].size())
        {
            int next_element = arrays[array_index][element_index + 1];
            q.push({next_element, array_index, element_index + 1});
        }
    }
    return output;
}
int main()
{
    vector<vector<int>> arr = {
        {10, 15, 20, 30},
        {2, 5, 8, 14, 24},
        {0, 11, 60, 90}};

    // various approaches
    vector<int> result = mergeKArrays(arr);

    // output
    for (auto x : result)
    {
        cout << x << " ";
    }

    return 0;
}
// output:
// 0 2 5 8 10 11 14 15 20 24 30 60 90

// Time-complexity:
// O(nkLog(k)).  -> size=k