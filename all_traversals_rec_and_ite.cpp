// om namo vnekateshaya
// om namah shivaya
// om shri matre namaha
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

};
void inorder(node* n)
{
  if(n==NULL)return;
  inorder(n->left);
  cout<<n->data<<" ";
  inorder(n->right);
}
void postorder(node* n)
{
 if(n==NULL)return;
 postorder(n->left);
 postorder(n->right);
 cout<<n->data<<" ";
}
void preorder(node* n)
{
   if(n==NULL)return;
   cout<<n->data<<" ";
   preorder(n->left);
   preorder(n->right);
}
void dfs(node* root)
{
    if(root==NULL)return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
             root=q.front();
        if(root->left!=NULL)q.push(root->left);
        if(root->right!=NULL)q.push(root->right);
         q.pop();
         cout<<root->data<<" ";
        }
        cout<<"\n";
    }
}
void inorder_ite(node* root)
{
    stack<node*>st;
    node* n=root;
    while(1)
    {
        if(n!=NULL)
        {
            st.push(n);
            n=n->left;
        }
        else
        {
            if(st.empty()==true)break;
            n=st.top();st.pop();
            cout<<n->data<<" ";
            n=n->right;
        }

    }
}
void preorder_ite(node* root)
{
    if(root==NULL)return;
    stack<node*>st;
    st.push(root);
    while(!st.empty())
    {
        node* n=st.top();
        st.pop();
        if(n->right!=NULL)st.push(n->right);
        if(n->left!=NULL)st.push(n->left);
        cout<<n->data<<" ";
    }
}
void postorder_2sta(node* root)
{
    if(root==NULL)return;
      stack<node*>s1,s2;
       s1.push(root);
    while(!s1.empty())
   {
    root=s1.top();
    s2.push(root);
    s1.pop();
    if(root->left!=NULL)s1.push(root->left);
    if(root->right!=NULL)s1.push(root->right);
   }
   while(!s2.empty())
   {
    node* p=s2.top();s2.pop();
    cout<<p->data<<" ";
   }
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
inorder(root);cout<<endl;
preorder(root);cout<<endl;
postorder(root);cout<<endl;
dfs(root);cout<<endl;
inorder_ite(root);cout<<endl;
preorder_ite(root);cout<<endl;
postorder_2sta(root);
}
