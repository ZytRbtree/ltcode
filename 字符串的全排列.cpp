#include <iostream>
using namespace std;

class Solution
{
public:
  //abc abc acb bac bca cab cba
  void calcAllPermutation(string & s,int from,int to)
  {
    if(from==to)
    {
      cout<<s<<endl;;
    }
    else
    {
      int i;
      for(i=from;i<=to;i++)
      {
        Solution::swap(s[i],s[from]);
        calcAllPermutation(s,from+1,to);
        Solution::swap(s[i],s[from]);
      }
    }
  }
  void getallquene(string & s)
  {
    calcAllPermutation(s,0,s.size()-1);
  }
  static void swap(char & a,char & b)
  {
    char c;
    c=a;
    a=b;
    b=c;
  }
};

int main(int argc, char const *argv[]) {

  string s1("abcd");
  cout<<s1<<endl;
  Solution S;
  S.getallquene(s1);
  return 0;
}
