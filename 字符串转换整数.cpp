#include <iostream>
using namespace std;

class Solution
{
public:
  int StrToInt(const string & s)
  {
    if(s.size()==0)
    {
      cout<<"该字符串为空"<<endl;
      return -1;
    }
    int i=0;
    int sum=0;
    int flag=1;
    if(s[i]=='-')
    {
      flag=-1;
      i++;
    }
    for(;i<s.size();i++)
    {
      if(s[i]<'0'||s[i]>'9')
      {
        cout<<"字符串格式错误"<<endl;
        return -1;
      }
      sum=sum*10+s[i]-'0';
    }
    return sum*flag;
  }
};


int main(int argc, char c const *argv[]) {
  Solution S;
  string s("0987688998");
  int ret=S.StrToInt(s);
  cout<<ret<<endl;
  return 0;
}
