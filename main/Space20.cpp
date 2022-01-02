#include<bits/stdc++.h>
using namespace std;
int main()
{
  char input[1000];
  cin.getline(input,1000);
  int sp = 0;
 for(int i=0;i<input[i]!='\0';i++)
 {
    if(input[i]==' ')
    {
       sp++;
    }
 }

  int id = strlen(input)+2*sp;
  input[id] = '\0';

  for(int i=strlen(input)-1;i>=0;i--)
  {
     if(input[i]==' ')
     {
         input[id-1]='0';
         input[id-2]='2';
         input[id-3]='%';

         id = id-3;

     }
     else{
        input[id-1] = input[i];
        id--;
     }
  }
    
    cout<<input;
}