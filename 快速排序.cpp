#include <iostream>
using namespace std;

class Quicksort
{
  friend ostream & operator<<(ostream &,Quicksort &);
public:
  Quicksort(int a[],int _n)
  {
    n=_n;
    p=new int[n];
    int i;
    for(i=0;i<n;i++)
    {
      p[i]=a[i];
    }
  }
  void sortfunction()
  {
    cout<<"sortfunction"<<endl;
    sort(0,n-1);
  }
  void sort(int left,int right)
  {
    if(left<right)
    {
      cout<<"sort"<<endl;
      int mid;
      mid=qs(left,right);
      sort(left,mid);
      sort(mid+1,right);
    }
  }
  // 2 4 6 1 8 9 3
  int qs(int up,int down)
  {
    int left=up;
    int right=down;
    int com=p[up];
    while(left<right)
    {
      while(left<right&&p[right]>com)
      {
        right--;
      }
      if(left<right)
      {
        p[left]=p[right];
        left++;
      }
      while(left<right&&p[left]<com)
      {
        left++;
      }
      if(left<right)
      {
        p[right]=p[left];
        right--;
      }
    }
    p[left]=com;
    return left;
  }

private:
  int * p;
  int n;
};
ostream & operator<<(ostream &out,Quicksort & q)
{
  int i;
  for(i=0;i<q.n;i++)
  {
    out<<q.p[i]<<' ';
  }
  out<<endl;
}
int main(int argc, char const *argv[]) {
  int a[10]={3,6,5,7,2,9,1,4,0,8};
  Quicksort q1(a,10);
  cout<<q1<<endl;
  q1.sortfunction();
  cout<<q1<<endl;
  return 0;
}
