// om namo venkateshaya
// om namah shivaya
// om shri matre namaha
#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
  node(int x)
  {
    val=x;
    left=NULL;
    right=NULL;
  }
};
// check for balanced binary tree 
// balanced 
int dfsHeight(node* root)
{
    if(root==NULL)return 0;
    int lh=dfsHeight(root->left);
    if(lh==-1)return -1;
    int rh=dfsHeight(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    return 1+max(lh,rh);
}
bool is_balanced(node* root)
{
    return dfsHeight(root)!=-1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
  struct node* root=new node(1);
  root->left=new node(2);
  root->right=new node(3);
  root->left->left=new node(4);
  root->left->right=new node(5);
  root->right->left=new node(6);
  root->right->right=new node(7);
if(is_balanced(root))cout<<"ITS A BAlANCED BINARY TREE\n";
else cout<<"NOT a balanced binary tree\n";
}
