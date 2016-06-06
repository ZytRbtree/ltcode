#include <iostream>
#include <vector>
using namespace std;
class Printer {
public:
    vector<int> printMatrix(vector<vector<int> > mat, int n, int m) {
        vector<int> ret;
        int i,j;
        int flag=0;
        for(i=0;i<n;i++)
        {
          if(flag==0)
          {
            for(j=0;j<m;j++)
            {
              ret.push_back(mat[i][j]);
            }
            flag=1;
          }
          else
          {
            for(j=m-1;j>=0;j--)
            {
              ret.push_back(mat[i][j]);
            }
            flag=0;
          }
        }
        return ret;
    }
};


void outputment(vector<vector<int> > p)
{
  vector<vector<int> >::iterator it;
  vector<int>::iterator it1;
  for(it=p.begin();it!=p.end();it++)
  {
    it1=it->begin();
    for(;it1!=it->end();it1++)
    {
      cout<<*it1<<' ';
    }
    cout<<endl;
  }
}


void outputment2(vector<int> p)
{
  vector<int>::iterator it1;
  it1=p.begin();
  for(;it1!=p.end();it1++)
  {
    cout<<*it1<<' ';
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int a[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
  int i,j;
  vector<vector<int> > source;
  source.resize(4);
  for(i=0;i<4;i++)
  {
    for(j=0;j<3;j++)
    {
      source[i].push_back(a[i][j]);
    }
  }
  outputment(source);
  Printer P;
  vector<int> accept;
  accept=P.printMatrix(source,4,3);
  outputment2(accept);
  return 0;
}
