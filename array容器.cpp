#include <iostream>
using  namespace std;
template<class T>
class Random_Pointer;
template<class T>
class Array;
template<class T>
class Pointer;
template<class T>
class Random_Pointer;
class Errhandle
{
public:
  virtual void printferror(void)=0;
};
class OverSide:public Errhandle
{
public:
  void printferror(void)
  {
    cout<<"the pos is out of the array side"<<endl;
  }
};
class IsNull:public Errhandle
{
public:
  void printferror(void)
  {
    cout<<"the po is NULL"<<endl;
  }
};
class NotCompare:public Errhandle
{
public:
  void printferror(void)
  {
    cout<<"pointer is beyond comparing"<<endl;
  }
};
template<class T>
class Array_Data
{
  //template<class T1>
  friend class Array<T>;
  //template<class T2>
  friend class Pointer<T>;
  friend class Random_Pointer<T>;

  template<class T1>
  friend ostream & operator<<(ostream & out,const Array<T1> & obj);
private:
  Array_Data():ap(0),size(0),use(1)
  {;}
  Array_Data(int _size):use(1)
  {
    size=_size;
    if(size==0)
    {
      ap=NULL;
    }
    else
    {
      ap=new T[size];
    }
  }
  Array_Data(int _size,int val):use(1)
  {
    size=_size;
    ap=new T[size];
    int i;
    for(i=0;i<size;i++)
    {
      ap[i]=val;
    }
  }
  T & operator[](int pos)
  {
      if(pos>=size)
      {
        throw new OverSide();
      }
      return ap[pos];
  }
  void resize(int newlength)
  {
    if(newlength==size)
    {
      return;
    }
    T *oldarray=ap;
    ap=new T[newlength];
    size=newlength;
    unsigned int len=size>newlength?newlength:size;
    copy(oldarray,len);
    delete oldarray;
    oldarray=NULL;
  }
  void reverse(int newcap)
  {
    if(newcap<=size)
    {
      return;
    }
    unsigned int newsize;
    if(size==0)
    {
      newsize=1;
    }
    else
    {
      newsize=size;
    }
    while(newsize<newcap)
    {
      newsize*=2;
    }
    resize(newsize);
  }
  void copy(T *source,int length)
  {
    int i;
    for(i=0;i<length;i++)
    {
      ap[i]=source[i];
    }
  }
  ~Array_Data()
  {
    delete ap;
    ap=NULL;
  }
  Array_Data(const Array_Data & obj);
  Array_Data & operator=(const Array_Data & obj);
  T *ap;
  unsigned int size;
  int use;
};

template<class T>
class Array
{
  template<class T1>
  friend ostream & operator<<(ostream & out,const Array<T1> & obj);
  friend class Random_Pointer<T>;
  friend class Pointer<T>;
public:
  Array()
  {
    po=new Array_Data<T>();
  }
  Array(int size)
  {
    po=new Array_Data<T>(size);
  }
  Array(int size,int val)
  {
    po=new Array_Data<T>(size,val);
  }

  Array(const Array & obj)
  {
    po=new Array_Data<T>(obj.po->size);
    po->copy(obj.po->ap,obj.po->size);
  }
  Array & operator=(const Array & obj)
  {
    if(--po->use==0)
    {
      delete po;
      po=NULL;
    }
    else
    {
      po=new Array_Data<T>(obj.po->size);
      po->copy(obj.po->ap,obj.po->size);
    }
  }
  T & operator[](int i)
  {
    return (*po)[i];
  }
  const T & operator[](int i) const
  {
    return (*po)[i];
  }
  void resize(int newlength)
  {
    po->resize(newlength);
  }
  void reverse(int newcap)
  {
    po->reverse(newcap);
  }
  unsigned int getsize()
  {
    return po->size;
  }
  ~Array()
  {
    if(--po->use==0)
    {
      delete po;
      po=NULL;
    }
  }
private:
  Array_Data<T> * po;
};
template<class T>
ostream & operator<<(ostream & out,const Array<T> & obj)
{
  int i;
  for(i=0;i<obj.po->size;i++)
  {
    out<<obj[i]<<' ';
  }
  out<<endl;
  return out;
}
template<class T>
class Random_Pointer;
template<class T>
class Pointer
{

  friend class Random_Pointer<T>;
  template<class T1>
  friend Pointer<T1> operator-(int,const Pointer<T1> &);
  template<class T2>
  friend Pointer<T2> operator-(const Pointer<T2> &,int);
  template<class T3>
  friend Pointer<T3> operator+(int,const Pointer<T3> &);
  template<class T4>
  friend Pointer<T4> operator+(const Pointer<T4> &,int);
  template<class T5>
  friend int operator-(const Pointer<T5> &,const Pointer<T5> &);
public:
  Pointer():po(0),pos(0)
  {;}
  Pointer(const Array<T> * obj,unsigned int n=0)
  {
    if(obj!=NULL)
    {
      obj->po->use++;
      po=obj->po;
    }
    else
    {
      po=NULL;
    }
    po=n;
  }
  Pointer(const Array<T> & obj,unsigned int n=0)
  {
      obj.po->use++;
      po=obj.po;
      pos=n;
  }
  Pointer(const Pointer & obj)
  {
    if(obj.po!=NULL)
    {
      obj.po->use++;
    }
    po=obj.po;
    pos=obj.pos;
  }
  Pointer & operator=(const Pointer & obj)
  {
    if(obj.po!=NULL)
    {
      obj.po->use++;
    }
    if(po&&--po->use==0)
    {
      delete po;
      po=NULL;
    }
    po=obj.po;
    pos=obj.pos;
    return  *this;
  }
  const T&  operator*()
  {
    if(po!=NULL)
    {
      return (*po)[pos];
    }
    else
    {
      throw new IsNull;
    }
  }
  Pointer & operator++(int i)
  {
    Pointer ret=*this;
    pos++;
    return ret;
  }
  Pointer & operator++()
  {
    pos++;
    return *this;
  }
  Pointer & operator--(int i)
  {
    Pointer ret=*this;
    pos--;
    return ret;
  }
  Pointer & operator--()
  {
    pos--;
    return *this;
  }
  Pointer &  operator+=(int n)
  {
    pos=pos+n;
    return *this;
  }
  Pointer  operator-=(int n)
  {
    pos=pos-n;
    return *this;
  }

  bool operator!=(Pointer obj)
  {
    return po!=obj.po||pos!=obj.po;
  }
  bool operator==(Pointer obj)
  {
    return po==obj.po&&pos==obj.po;
  }
  bool operator >(Pointer obj)
  {
    if(po!=obj.po)
    {
      throw new NotCompare;
    }
    else
    {
      return pos>obj.pos;
    }
  }
  bool operator <(Pointer obj)
  {
    if(po!=obj.po)
    {
      throw new NotCompare;
    }
    else
    {
      return pos<obj.pos;
    }
  }
  ~Pointer()
  {
    if(po&&--po->use==0)
    {
      delete po;
      po=NULL;
    }
  }
private:
  Array_Data<T> * po;
  unsigned int pos;
};

template<class T>
int operator-(const Pointer<T> & obj1,const Pointer<T> & obj2)
{
  return (int)obj1.pos-(int)obj2.pos;
}

template<class T>
Pointer<T>  operator-(int n,const Pointer<T> & obj)
{
  Pointer<T> ret=obj;
  ret-=n;
  return ret;
}

template<class T>
Pointer<T>  operator-(const Pointer<T> & obj,int n)
{
  Pointer<T> ret=obj;
  ret-=n;
  return ret;
}

template<class T>
Pointer<T>  operator+(int n,const Pointer<T> & obj)
{
  Pointer<T> ret=obj;
  ret+=n;
  return ret;
}

template<class T>
Pointer<T>  operator+(const Pointer<T> & obj,int n)
{
  Pointer<T> ret=obj;
  ret+=n;
  return ret;
}

template<class T>
class Random_Pointer: public Pointer<T>
{
  template<class T1>
  friend Random_Pointer<T1> operator-(int,const Random_Pointer<T1> &);
  template<class T2>
  friend Random_Pointer<T2> operator-(const Random_Pointer<T2> &,int);
  template<class T3>
  friend Random_Pointer<T3> operator+(int,const Random_Pointer<T3> &);
  template<class T4>
  friend Random_Pointer<T4> operator+(const Random_Pointer<T4> &,int);
public:
  Random_Pointer():Pointer<T>()
  {;}
  Random_Pointer(Array<T> * obj,unsigned int n=0):Pointer<T>(obj,n)
  {;}
  Random_Pointer(Array<T> & obj,unsigned int n=0):Pointer<T>(obj,n)
  {;}
  Random_Pointer(const Random_Pointer & obj)
  {
    if(obj.po!=NULL)
    {
      obj.po->use++;
    }
    this->po=obj.po;
    this->pos=obj.pos;
  }
  Random_Pointer & operator=(const Random_Pointer & obj)
  {
    if(obj.po!=NULL)
    {
      obj.po->use++;
    }
    if(this->po&&--this->po->use==0)
    {
      delete this->po;
      this->po=NULL;
    }
    this->po=obj.po;
    this->pos=obj.pos;
    return  *this;
  }
  T & operator*()
  {
    if(this->po!=NULL)
    {
      return (*(this->po))[this->pos];
    }
    else
    {
      throw new IsNull;
    }
  }
  Random_Pointer & operator++(int i)
  {
    Random_Pointer ret=*this;
    this->pos++;
    return ret;
  }
  Random_Pointer & operator++()
  {
    this->pos++;
    return *this;
  }
  Random_Pointer & operator--(int i)
  {
    Random_Pointer ret=*this;
    this->pos--;
    return ret;
  }
  Random_Pointer & operator--()
  {
    this->pos--;
    return *this;
  }
  Random_Pointer &  operator+=(int n)
  {
    this->pos=this->pos+n;
    return *this;
  }
  Random_Pointer & operator-=(int n)
  {
    this->pos=this->pos-n;
    return *this;
  }
/*
  bool operator!=(Random_Pointer obj)
  {
    return po!=obj.po||pos!=obj.po;
  }
  bool operator==(Random_Pointer obj)
  {
    return po==obj.po&&pos==obj.po;
  }*/
  //可以共用

  ~Random_Pointer()
  {
    if(this->po&&--this->po->use==0)
    {
      delete this->po;
      this->po=NULL;
    }
  }
};

template<class T>
Random_Pointer<T>  operator-(int n,const Random_Pointer<T> & obj)
{
  Random_Pointer<T> ret=obj;
  ret-=n;
  return ret;
}

template<class T>
Random_Pointer<T>  operator-(const Random_Pointer<T> & obj,int n)
{
  Random_Pointer<T> ret=obj;
  ret-=n;
  return ret;
}

template<class T>
Random_Pointer<T>  operator+(int n,const Random_Pointer<T> & obj)
{
  Random_Pointer<T> ret=obj;
  ret+=n;
  return ret;
}

template<class T>
Random_Pointer<T>  operator+(const Random_Pointer<T> & obj,int n)
{
  Random_Pointer<T> ret=obj;
  ret+=n;
  return ret;
}

int main(int argc, char const *argv[]) {

  Array<int> a1(5);
  Array<int> a2(6,10);
  Pointer<int> p1=a1;//定义一个只读；
  Random_Pointer<int> p2=a1;//定义一个可读；
  cout<<"a1.size()="<<a1.getsize()<<endl;
  cout<<"a2.size()="<<a2.getsize()<<endl;
  //cout<<*p2<<endl;
  *p2=6;
  cout<<*p2<<endl;
  try{
    cout<<a1<<endl;
    cout<<a2<<endl;
    a2[0]=15;
    a1[2]=16;
    a1.reverse(20);
    a1[10]=1000;
    cout<<"a1.size()="<<a1.getsize()<<endl;
    cout<<"a2.size()="<<a2.getsize()<<endl;
    cout<<a1<<endl;
    cout<<a2<<endl;
    cout<<"-------------------"<<endl;
    a1.resize(10);
    cout<<"a1.size()="<<a1.getsize()<<endl;
    cout<<"a2.size()="<<a2.getsize()<<endl;
    cout<<a1<<endl;
    cout<<a2<<endl;

    Pointer<int> p3=++p2;
    p2++;
    cout<<"*p2="<<*p2<<endl;
    cout<<"*p3="<<*p3<<endl;
  }catch(Errhandle * Eh)
  {
    Eh->printferror();
  }
  return 0;
}
