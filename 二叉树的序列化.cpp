#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class TreeToSequence {
public:
    string toSequence(TreeNode* root) {
        string ret;
        getsequence(ret,root);
        return ret;
    }
    void getsequence(string & result,TreeNode * curr)
    {
      string::iterator it;
      if(curr==NULL)
      {
        return ;
      }
      else
      {
        it=result.end();
        result.insert(it,'(');
        getsequence(result,curr->left);
        getsequence(result,curr->right);
        it=result.end();
        result.insert(it,')');
      }
    }
    TreeNode * createtree()
    {
      int val;
      scanf("%d",&val);
      if(val==-1)
      {
        return NULL;
      }
      TreeNode * newnode=new TreeNode(val);
      newnode->left=createtree();
      newnode->right=createtree();
      return newnode;
    }
    void printtree(TreeNode * root)
    {
      if(root==NULL)
      {
        return;
      }
      printtree(root->left);
      cout<<root->val<<endl;
      printtree(root->right);
    }
};
int main(int argc, char const *argv[]) {
/*
  TreeToSequence T;
  TreeNode * root=T.createtree();
  T.printtree(root);
  string ret=T.toSequence(root);
  cout<<"输出的序列号是："<<endl;
  cout<<ret<<endl;
  */
  string S("dasjk asjkh akoi");
  int ret=S.find("kl",0);
  if(ret!=string::npos)
  {
    cout<<"find the string"<<endl;
  }
  else
  {
    cout<<"not find the string"<<endl;
  }
  return 0;
}
