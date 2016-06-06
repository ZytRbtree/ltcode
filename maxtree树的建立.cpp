#include <iostream>
#include <vector>
using namespace std;
class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
      int i,j;
      int flag1=0,flag2=0;
      int left,right;
      vector<int> ret;
      for(i=0;i<n;i++)
      {
        left=i-1;
        right=i+1;
        flag1=0;
        flag2=0;
        while((left>=0||right<n)&&(flag1==0||flag2==0)&&(!(flag2==1&&left==-1))&&(!(flag2==1&&left==-1)))
        {
          if(flag1==0)
          {
            if(A[left]>A[i])
            {
              flag1=1;
            }
            else
            {
              left--;
            }
          }
          if(flag2==0)
          {
            if(A[right]>A[i])
            {
              flag2=1;
            }
            else
            {
              right++;
            }
          }
        }
        if(left<0&&right>=n)
        {
          ret.push_back(-1);
          continue;
        }
        if(flag1==1&&flag2==1)
        {
          if(A[left]>A[right])
          {
            ret.push_back(right);
          }
          else
          {
            ret.push_back(left);
          }
          continue;
        }
        if(flag1==1)
        {
          ret.push_back(left);
          continue;
        }
        if(flag2==1)
        {
          ret.push_back(right);
          continue;
        }
      }
      return ret;
    }
    void outputment(vector<int> source)
    {
      vector<int>::iterator it;
      for(it=source.begin();it!=source.end();it++)
      {
        cout<<*it<<' ';
      }
      cout<<endl;
    }
};


int main(int argc, char const *argv[]) {


  vector<int> treenode;
  int a[9]={1,5,4,2,3,7,11,14,16};
  int i;
  for(i=0;i<9;i++)
  {
    treenode.push_back(a[i]);
  }
  MaxTree M;
  M.outputment(treenode);
  vector<int> ret;
  ret=M.buildMaxTree(treenode,9);
  M.outputment(ret);
  return 0;
}
