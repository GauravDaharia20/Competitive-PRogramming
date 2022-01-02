#include<bits/stdc++.h>
using namespace std;
string palin(string &str)
{
    if(str.length()==1) return "";
    int s= 0; int e = str.size()-1;
    while(s<e)
    {
        if(str[s]!='a')
        {
            str[s]='a'
            ;
            return str;
        }
        s++;
        e--;
    }
    str[str.size()-1]='b';
    return str;
}
int main()
{
    string str = "abccba";
    cout<<palin(str);

}