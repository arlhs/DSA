#include<iostream>

using namespace std;

int main()
{
    string s;
    cout<<"Enter String: ";
    cin>>s;
    int result=0;

    for(int i; s[i]; i++)
    {
        //Assci of integer 0-9 if subtracted from assci of 0 will always
        //results in the number itself
        if(s[i]-'0'>=0 && s[i]-'0'<=9)
            result = result*10 + s[i]-'0';
        else
        {
            cout<<"Can't convert to integer"<<endl;
            return 0;
        }
    }
    cout<<"Integer : "<<result;
}
