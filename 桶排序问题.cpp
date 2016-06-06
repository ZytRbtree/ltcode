#include <iostream>
#include <vector>
using namespace std;
/*请设计一个复杂度为O(n)的算法，计算一个未排序数组中排序后相邻元素的最大差值。

给定一个整数数组A和数组的大小n，请返回最大差值。保证数组元素个数大于等于2小于等于500。
*/
class MaxDivision {
public:
    int findMaxDivision(vector<int> A, int n) {
        int mx=A[0];
        int mn=A[0];
        int i;
        for(i=1;i<n;i++)
        {
          if(mx<A[i])
          {
            mx=A[i];
          }
          if(mn>A[i])
          {
            mn=A[i];
          }
        }
        vector<int> bucket(mx-mn+1);

        for(i=0;i<n;i++)
        {
          bucket[A[i]-mn]++;
        }
        int curr=0;
        int maxdec=0;
        int pre=curr;
        for(curr++;curr<mx-mn+1;curr++)
        {
          if(bucket[curr]!=0)
          {
            if(curr-pre>maxdec)
            {
              maxdec=curr-pre;
            }
            pre=curr;
          }
        }
        return maxdec;
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
  int i;
  int a[4]={9,3,1,10};
  for(i=0;i<4;i++)
  {
    source.push_back(a[i]);
  }
  outputment(source);
  MaxDivision M;
  int ret=M.findMaxDivision(source,4);
  cout<<"最大差值="<<ret<<endl;
  return 0;
}
