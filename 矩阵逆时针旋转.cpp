#include <iostream>
#include <vector>
using  namespace std;

class Rotate {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        vector<vector<int> > ret;
        ret.resize(n);
        int i,j;
        int k=0;
        for(j=0;j<n;j++)
        {
          for(i=n-1;i>=0;i--)
          {
            ret[j].push_back(mat[i][j]);
          }
        }
        return ret;
    }
};
class Printer//蛇形矩阵{
public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        vector<int> ret;
        int line,array,i,j,k;
        line=n;
        array=m;
        i=0;
        j=0;
        while(line>0&&array>0)
        {
          for(k=0;k<array;k++)
          {
            ret.push_back(mat[i][j]);
            j++;
          }
          j=j-1;
          i=i+1;
          for(k=0;k<line-2;k++)
          {
            ret.push_back(mat[i][j]);
            i++;
          }
          for(k=0;k<array;k++)
          {
            ret.push_back(mat[i][j]);
            j--;
          }
          j=j+1;
          i=i-1;
          for(k=0;k<line-2;k++)
          {
            ret.push_back(mat[i][j]);
            i--;
          }
          line=line-2;
          array=array-2;
          i++;
          j++;
        }
        return ret;
    }
};
class Printer1{//改进后蛇形矩阵
public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        vector<int> ret;
        int line,array,i,j,k;
        line=n;
        array=m;
        i=0;
        j=0;
        while(line>0&&array>0)
        {
          for(k=0;k<array;k++)
          {
            ret.push_back(mat[i][j]);
            j++;
          }
          j=j-1;
          i=i+1;
          for(k=0;k<line-2;k++)
          {
            ret.push_back(mat[i][j]);
            i++;
          }
          if(line==1)
          {
              line=line-2;
          	  array=array-2;
               continue;
          }
          for(k=0;k<array;k++)
          {
            ret.push_back(mat[i][j]);
            j--;
          }
          if(array==1)
          {
              line=line-2;
          	  array=array-2;
               continue;
          }
          j=j+1;
          i=i-1;
          for(k=0;k<line-2;k++)
          {
            ret.push_back(mat[i][j]);
            i--;
          }
          line=line-2;
          array=array-2;
          i++;
          j++;
        }
        return ret;
    }
};
void outputment(vector<vector<int> >  V,int n,int m)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      cout<<' '<<V[i][j];
    }
    cout<<endl;
  }
}

void outputment1(vector<int> V)
{
  int i,j;
  vector<int>::iterator it;
  it=V.begin();
  for(;it!=V.end();it++)
  {
    cout<<*it<<' ';
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {

  vector<vector<int> >  V;
  vector<vector<int> >  ret;
  vector<int> ret1;
  V.resize(5);
  int a[5][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
  int i,j;
  for(i=0;i<5;i++)
  {
    for(j=0;j<4;j++)
    V[i].push_back(a[i][j]);
  }
  outputment(V,5,4);
  cout<<"---------------"<<endl;
  Rotate R;
  //ret=R.rotateMatrix(V,4);
  //outputment(ret,4);

   Printer P;
   ret1=P.clockwisePrint(V,5,4);
   outputment1(ret1);

  return 0;
}
