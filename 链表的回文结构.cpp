#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class PalindromeList {
public:
  //对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
  //1->2->3->4->5->6
    bool chkPalindrome(ListNode* A) {
          bool ret=true;
          ListNode * quick=A;
          ListNode * slow=A;
          while(quick!=NULL&&quick->next!=NULL&&quick->next->next!=NULL)
          {
            quick=quick->next->next;
            slow=slow->next;
          }
          ListNode * link1=slow->next;
          ListNode * link2=NULL;
          ListNode * tmp;
          slow->next=NULL;
          cout<<"前"<<endl;
          outputment(A);
          if(link1!=NULL)
          {
            link2=link1->next;
            link1->next=NULL;
          }
          while(link2!=NULL)
          {
            tmp=link2;
            link2=link2->next;
            tmp->next=link1;
            link1=tmp;
          }
          ListNode * curr=A;
          ListNode * later=link1;
          cout<<"前"<<endl;
          outputment(curr);
          cout<<"后"<<endl;
          outputment(later);
          while(later!=NULL)
          {
            if(later->val!=curr->val)
            {
              ret=false;
              break;
            }
            curr=curr->next;
            later=later->next;
          }

          return ret;
    }
    void outputment(ListNode * head)
    {
      while(head!=NULL)
      {
        cout<<head->val<<' ';
        head=head->next;
      }
      cout<<endl;
    }
};
void outputment(ListNode * head)
{
  while(head!=NULL)
  {
    cout<<head->val<<' ';
    head=head->next;
  }
  cout<<endl;
}
int main(int argc, char const *argv[]) {
  int a[]={1};
  ListNode * curr=NULL;
  int i;
  for(i=0;i<1;i++)
  {
    ListNode * newnode=new ListNode(a[i]);
    newnode->next=curr;
    curr=newnode;
  }
  PalindromeList P;
  P.outputment(curr);
  bool ret=P.chkPalindrome(curr);
  if(ret==true)
  {
    cout<<"是"<<endl;
  }
  else
  {
    cout<<"不是"<<endl;
  }
  return 0;
}
