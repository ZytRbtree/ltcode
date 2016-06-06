#include <iostream>
using namespace std;
class StringRotation {
public:
    string rotateString(string A, int n, int p) {
      reverse(A,0,p);
      reverse(A,p+1,n-1);
      reverse(A,0,n-1);//三步反转法
      return A;
    }
    void reverse(string & a,int left,int right)
    {
      while(left<right)
      {
        a[left]=a[left]+a[right];
        a[right]=a[left]-a[right];
        a[left]=a[left]-a[right];
        left++;
        right--;
      }
    }
};

int main(int argc, char const *argv[]) {
  StringRotation S;
  string s1("PQWIVLQQ");
  cout<<s1<<endl;
  s1=S.rotateString(s1,strlen("PQWIVLQQ"),5);
  cout<<s1<<endl;
  //S.reverse(s1,0,strlen("PQWIVLQQ")-1);
  //cout<<s1<<endl;
  return 0;
}
