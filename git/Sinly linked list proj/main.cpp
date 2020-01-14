
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
void insert(Node *root,int a1,int a2,char lr){
    if(root==NULL){
        return;
    }
    if(root->data==a1){
        switch(lr){
            case 'L':root->left=new Node(a2);
                break;
            case 'R':root->right=new Node(a2);
                break;
        }
    }
    else{
        insert(root->left,a1,a2,lr);
        insert(root->right,a1,a2,lr);
    }
}
void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool isIsomorphic(Node *root1,Node *root2);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        int m=n;
        Node *root1=NULL;
        Node *root2=NULL;
        while(n-->0){
            int a1,a2;
            cin>>a1>>a2;
            char lr;
            scanf(" %c",&lr);
            if(root1==NULL){
                root1=new Node(a1);
                switch(lr){
                    case 'L':root1->left=new Node(a2);
                        break;
                    case 'R':root1->right=new Node(a2);
                        break;
                }
            }
            else{
                insert(root1,a1,a2,lr);
            }
        }
        while(m-->0){
            int a1,a2;
            cin>>a1>>a2;
            char lr;
            scanf(" %c",&lr);
            if(root2==NULL){
                root2=new Node(a1);
                switch(lr){
                    case 'L':root2->left=new Node(a2);
                        break;
                    case 'R':root2->right=new Node(a2);
                        break;
                }
            }
            else{
                insert(root2,a1,a2,lr);
            }
        }
        /*inorder(root1);
        cout<<endl;
        inorder(root2);*/
        if(isIsomorphic(root1,root2)){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
bool isIsomorphic(Node *root1,Node *root2) {
//add code here.
    if (!root1 && !root2)
        return true;


    if (!root1 || !root2)return false;

    if (root1->data != root2->data)return false;

    if (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right) ||
        isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left))
        return true;


}