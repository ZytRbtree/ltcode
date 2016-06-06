#include <iostream>
#include <vector>
using namespace std;

class Array_data
{
public:
  Array_data(int n)
  {
    size=n;
  }
  friend class test;
private:
  Array_data(const Array_data &);
  //怎么写的话会覆盖之前的拷贝构造函数，如果只有声明，那么这个拷贝构造函数将是无定义的，如果用户使用它，在编译的时候将会出错
  Array_data & operator=(const Array_data &);
  int size;
};

class test
{
  public:
  void solution()
  {
    Array_data a1(12);
    solution1(a1);
    cout<<"a1.size="<<a1.size<<endl;
  }
  void solution1(Array_data a)
  {
    cout<<"a.size+1="<<a.size+1<<endl;
  }
};


class base
{
public:
  /*base()
  {
    cout<<"none parameter construct function"<<endl;
    m=0;
  }*/
  base(int d)
  {
    cout<<"one parameter construct function"<<endl;
    m=d;
  }
private:
  int m;
};
class child:public base
{
public:
  child(int d):base(d)//当继承的时候，如果派生类构造函数没有指定调用哪一个基类构造函数，那么会自动调用无参构造函数
  {

  }
  child():base(3)
  {

  }
};

template<class T>
class test3
{
  template<class T1>
  friend test3<T1> operator +(const test3<T1> &,int);
  //friend test3<T> operator +(const test3<T> &,int);
  template<class T2>
  friend test3<T2> operator +(int,const test3<T2> &);
  //friend test3<T> operator +(int,const test3<T> &);
public:
  test3(int s)
  {
    d=s;
  }
  test3 & modify(int val)
  {
    d=val;
  }
  int getvalue(void)
  {
    return d;
  }
private:
  T d;
};
template<class T>
test3<T> operator +(const test3<T> & obj,int n)
{
  cout<<"nasdjasasdk"<<endl;
}
template<class T>
test3<T> operator +(int n,const test3<T> & obj)
{
  cout<<"nasdjasasdk_yes"<<endl;
}

template<class T>
class test7;

template<class T>
class test6
{
  //template<class T1>
  friend class test7<T>;//模版继承类和模版派生类 声明为友元时，应当这样写 先将派生类声明为模版类 再在基类中
  //声明友元类（类型和基类类型一样 都为T）
public:
  test6(T s)
  {
    d=s;
  }
  T getvalue(void)
  {
    return d;
  }
private:
  T d;
};
template<class T>
class test7:public test6<T>
{
public:
  test7(T s):test6<T>(s)
  {
    ;
  }
  T getvalue2(void)
  {
    this->d=6;
    //test6<T>::d=6;
  //  return test6<T>::d;
  return this->d;
  }
};
int main(int argc, char const *argv[]) {
  test7<double> t(4);
  //t.d=1;
  cout<<t.getvalue2()<<endl;
/*  test S1;
  Array_data a1(12);
  S1.solution1(a1);*/
  //child c(3);

  /*
  测试返回值为 vector<int> &类型的情况
  vector<int> source;
  source.push_back(1);
  source.push_back(2);
  source.push_back(3);
  cout<<"source[2]="<<source[2]<<endl;
  int t=source[2];
  cout<<"t="<<t<<endl;
  //t=12;
  source[2]=12;
  cout<<"----------------------"<<endl;
  cout<<"source[2]="<<source[2]<<endl;
  cout<<"t="<<t<<endl;*/

  //test3<int> t(2);
  //int ret=t.getvalue();
  //cout<<ret<<endl;
  //test3<char> ret2=t.modify(5);
  //ret=t.getvalue();
  //cout<<ret<<endl;
  //t+3;
  //3+t;
  /*int * p=new int[0];
  if(p==NULL)
  {
      cout<<"yes"<<endl;
  }
  else
  {
    cout<<"no"<<endl;
  }
  p[0]=1;
  p[1]=2;
  cout<<p[0]<<endl;
  cout<<p[1]<<endl;*/
  return 0;
}
