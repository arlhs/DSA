#include<iostream>
#include<map>
#include<stack>
using namespace std;

int main()
{
    stack<pair<char, int>> s;

    s.push({'a',1});
    s.top().second++;

    string result;
    result.append(25,"aa");
    cout<<result;
}