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
// all inorder ,preorder and postorder traversals 
// here we will be using a single stack which stores node and a number
// initialize the number with 1 and 
// in the next step increment the number 
void all_in_one_trav(node* root)
{
    stack<pair<node*,int>>st;
    st.push({root,1});
   vector<int>pre,post,in;
   while(!st.empty())
   {
    auto it=st.top();
    st.pop();
    if(it.second==1)
    {
        // this is the part fo pre ,increment it to 2 

        pre.push_back(it.first->data);
        it.second++;
        st.push(it);
        if(it.first->left!=NULL)
        {
            st.push({it.first->left,1});
        }
    }
    else if(it.second==2)
    {
        in.push_back(it.first->data);
        it.second++;
       st.push(it);
       if(it.first->right!=NULL)
        st.push({it.first->right,1});
    }
    else
    {
        post.push_back(it.first->data);
    }
   }
for(int i=0;i<pre.size();i++)cout<<pre[i]<<" ";
cout<<endl;
for(int i=0;i<post.size();i++)cout<<post[i]<<" ";
cout<<endl;
for(int i=0;i<in.size();i++)cout<<in[i]<<" ";
cout<<endl;
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
all_in_one_trav(root);

}
