#include <iostream>
using namespace std;
class Solution
{
public:
  bool findincludestr(const string & s1,const string & s2)//用散列表
  {
    int flag=0;
    int i;
    bool ret=true;
    for(i=0;i<s1.size();i++)
    {
      flag|=0x01<<s1[i]-'A';
    }
    printf("%#x\n",flag);
    for(i=0;i<s2.size();i++)
    {
      cout<<"sadbjd"<<endl;
      if(((flag>>s2[i]-'A')&0x01)==0)//这里注意优先级
      {
        ret=false;
        break;
      }
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  string s1("YQWUYSBJGDHUAJGJK");
  string s2("SAJHSDA");
  Solution S;
  bool ret=S.findincludestr(s1,s2);
  if(ret==false)
  {
    cout<<"false"<<endl;
  }
  else
  {
    cout<<"true"<<endl;
  }
  return 0;
}
