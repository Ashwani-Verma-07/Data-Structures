//Map->BST : log(n);
//unordered_map : HashTable : O(1);
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> ourMap;
    //insert
    pair<string, int> p("abc", 1);
    ourMap.insert(p);
    //another way
    ourMap["def"] = 2;
    //find or access
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;
    //cout << ourMap.at("ghi") << endl; // uncaught exception : key not found
    cout << ourMap["ghi"] << endl; // if "ghi" is present in hash then return corresponding value
    //else ourMap["ght"] makes insert into hash and assigns its value to 0
    cout << "Size is : " << ourMap.size() << endl;
    //better approach for search
    if (ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    //erase
    ourMap.erase("ghi");

    if (ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "ghi is not present" << endl;
    }
    //ghi , abc -> these all are key for our corresponding value so that complexity tends to O(1)
}