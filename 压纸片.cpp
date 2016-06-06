#include <iostream>
#include <vector>
using namespace std;

class FoldPaper {
public:
    vector<string> foldPaper(int n) {
        // write code here
        vector<string> result;
        press(result,n,1,1);
        return result;
    }
    void press(vector<string> &result,int n,int k,int flag)
    {
      if(n<k)
      {
        return;
      }
      if(k==1)
      {
          press(result,n,k+1,1);
          if(flag==1)
          {
            result.push_back("down");
          }
          press(result,n,k+1,0);
      }
      else
      {
        press(result,n,k+1,1);
        if(flag==0)
        {
          result.push_back("up");
        }
        else
        {
          result.push_back("down");
        }
        press(result,n,k+1,0);
      }
  }
};

void outputment(vector<string> & v)
{
  vector<string>::iterator it;//=v.begin();
  it=v.begin();//当在v前面加了cosnt （如：const vector<string> & v）不能调用begin()函数 会报错
  for(;it!=v.end();it++)
  {
    cout<<*it<<endl;
  }
}

int main(int argc, char const *argv[]) {
  vector<string> result;
  FoldPaper F;
  result=F.foldPaper(3);
  cout<<"折纸片的的结果是--："<<endl;
  outputment(result);
  return 0;
}
