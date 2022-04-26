// om namo venkateshaya
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
vector<vector<int>> bfs(node* root)
{
 // level order traversal or BFS 
    // take a vector of vector or an array list now use a queue data structure  to store the elements 
    // now when we have a root node push it into the queue and then thir children and then the corresponding chhildren to the arraylist 
    vector<vector<int>>v;
    if(root==NULL)return v;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++)
        {
            node* n=q.front();
            q.pop();
            if(n->left!=NULL)q.push(n->left);
            if(n->right!=NULL)q.push(n->right);
            level.push_back(n->data);
        }
        v.push_back(level);
    }
    return v;
}
int main()
{
    // tree representation and traversals 
    // bfs and dfs traversals 

// DFS
    // inorder (left root right)
    // pre ordr (root left right)
    // post ordr (left right root)

    //in inordr traversal first goto the extreme left of the left sub tree and apply the gien rule left root right 
    // for tree 
    /*
                1
               / \
               2  3
              /\  /\
              4 5 6 7
              these are all depth first searches 
now inorder traversal fot this given tree is  4 2 5 1 6 3 7 
now the preorder traversal fot the above tree will be 1 2 4 5 3 6 7
now the post order traversal will be 4 5 2 6 7 3 1
now for another tree 
                1
               / \
               2  3
              /\  /\
              4 5 6 7
                /   /\
                8   9 10
        inorder: 4 2 8 5 1 6 3 9 7 10 
        preorder: 1 2 4 5 8 3 6 7 9 10
        postorder: 4 8 5 2 6 9 10 7 3 1 
// BFS 
now bfs for the same tree 
1 2 3 4 5 6 7 8 9 10
    */
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // below is creating a tree;
    /*
                1
               / \
               2  3
              /\  /\
              4 5 7 8
                /   /\
                6   9 10
     preorder(root,left,right)
     1 2 4 5 6 3 7 8 9 10
     inorder(left,root,right)
     4 2 6 5 1 7 3 9 8 10
     postorder(left,right,root)
     4 6 5 2 7 9 10 8 3 1 

    */
  struct node* root=new node(1);
       root->left=new node(2);
       root->right=new node(3);
       root->left->left=new node(4);
       root->left->right=new node(5);
       root->left->right->left=new node(6);
       root->right->left=new node(7);
       root->right->right=new node(8);
       root->right->right->left=new node(9);
       root->right->right->right=new node(10);
   vector<vector<int>>v=bfs(root);
   for(int i=0;i<v.size();i++)
   {
    vector<int>v1=v[i];
    for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";cout<<"\n";
   }
}
