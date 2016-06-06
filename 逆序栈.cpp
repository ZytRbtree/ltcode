#include <iostream>
#include <vector>
using namespace std;
//1 2 3 4 5
class ReverseStack {
public:
    vector<int> reverseStackRecursively(vector<int> stack, int top) {
        // write code here
        vector<int> ret;
        getnixu(ret,stack,1,top);
        return ret;
    }
    void getnixu(vector<int> & ret,vector<int> source,int n,int top)
    {
      if(n==top)
      {
        ret.push_back(source[n-1]);
      }
      else
      {
        getnixu(ret,source,n+1,top);
        ret.push_back(source[n-1]);
      }
    }
};
void outputment(vector<int> & source)
{
  vector<int>::iterator it;
  it=source.begin();
  for(;it!=source.end();it++)
  {
    cout<<*it<<' ';
  }
  cout<<endl;
}
int main(int argc, char const *argv[]) {
  vector<int> source;
  vector<int> ret;
  int i;
  int a[7]={1,2,3,4,5,78,799};
  for(i=0;i<7;i++)
  {
    source.push_back(a[i]);
  }
  outputment(source);
  ReverseStack R;
  ret=R.reverseStackRecursively(source,7);
  outputment(ret);
  return 0;
}
