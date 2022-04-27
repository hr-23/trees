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
    // TC for recursive approach is o(n) 
    // SC for recursive approach is o(n)
}
void preorder(node* n)
{
    if(n==NULL)return;
    cout<<n->data<<" ";
    preorder(n->left);
    preorder(n->right);
}
void postorder(node* n)
{
    if(n==NULL)return;
    postorder(n->left);
    postorder(n->right);
    cout<<n->data<<" ";
}
void levelorder(node* root)
{
vector<vector<int>>v;
    if(root==NULL)return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        vector<int>v1;
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            node* n=q.front();
            q.pop();
            if(n->left!=NULL)q.push(n->left);
            if(n->right!=NULL)q.push(n->right);
            v1.push_back(n->data);
        }
        v.push_back(v1);
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
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
    /*
       1
       /\
       2 3
       /\ /\
      4 5 6 7
      inorder 4 2 5 1 6 3 7 
      preorder 1 2 4 5 3 6 7 
      postorder 4 5 2 6 7 3 1
      levleoder 1 2 3 4 5 6 7
    */
   struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    inorder(root);cout<<"\n";
    preorder(root);cout<<"\n";
    postorder(root);cout<<"\n";
    levelorder(root);cout<<"\n";
}
