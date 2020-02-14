#include <iostream> 
using namespace std; 
  
struct Node 
{ 
    struct Node *left, *right; 
    int key; 
}; 
  
Node* newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
Node* LCA(Node * root, int n1,int n2) 
{ 
    if (root == NULL) 
       return root; 
    if (root->key == n1 || root->key == n2) 
       return root; 
  
    Node* left = LCA(root->left, n1, n2); 
    Node* right = LCA(root->right, n1, n2); 
  
    if (left != NULL && right != NULL) 
         return root; 
    if (left != NULL) 
        return LCA(root->left, n1, n2); 
  
    return LCA(root->right, n1, n2); 
} 

class BinaryTreeTest
{

    public: 

    bool ifNodeExists(Node* node, int val) 
    { 
    if (node == NULL) 
        return false; 
  
    if (node->key == val) 
        return true; 
  
    bool res1 = ifNodeExists(node->left, val); 
    if(res1) return true; // node found, no need to look further 
    bool res2 = ifNodeExists(node->right, val); 
    return res2; 
    }

    int checkHeight(Node* root, int x) 
    { 
    if (root == NULL) 
      return -1; 
  
    int dist = -1;     
    if ((root->key == x) || 
        (dist = checkHeight(root->left, x)) >= 0 || 
        (dist = checkHeight(root->right, x)) >= 0) 
        return dist + 1; 
  
    return dist; 
    } 

    int findDistance(Node* root, int n1, int n2) 
    {
    if (ifNodeExists(root,n1)==false)
    {
        cout<<"Node "<<n1<<" doesn't exist in the tree. \n";
        return -1;
    }
    else if (ifNodeExists(root,n2)==false)
    {
        cout<<"Node "<<n2<<" doesn't exist in the tree. \n";
        return -1;}

    else if (checkHeight(root, n1)!=checkHeight(root, n2))
    {
        cout<<"Nodes "<<n1<<" and "<<n2<<" are not at same level   \n";
        return -1;}
        int leftNode = Pathlength(root, n1, 'l') - 2;
        int rightNode = Pathlength(root, n2,'r') - 2;
        int lcaData = (LCA(root, n1, n2))->key;   //LCA->Lowest Common Ancestor
        int lcaDistance = Pathlength(root, lcaData,'r') - 1;
        return (leftNode + rightNode) - 2 * lcaDistance;
    }

    int Pathlength(Node* root, int val,char traverse) 
    {
    if (root != NULL) 
    {
        int x = 0;
        if('r' == traverse)
        {
            if(root->left ==NULL && root->right ==NULL)
            {//do nothing
            }
            else if(root->left ==NULL || root->right ==NULL)
            {cout<<"\nCounting the position where the node is not present is : " <<root->key<<"\n";}
            if ((root->key == val) || (x = Pathlength(root->left, val,'r')) > 0 || (x = Pathlength(root->right, val,'r')) > 0)
            {return x + 1;}
        }
        if('r' != traverse )
        {
            if ((root->key == val) || (x = Pathlength(root->left, val,'l')) > 0  || (x = Pathlength(root->right, val,'l')) > 0) 
            {return x + 1;}
        }
        return 0;
    }
    return 0;
    }
};

int main() 
{     
    Node *root = newNode(5); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(9);
    // root->left->left->right = newNode(11);
    root->right->right = newNode(1); 
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(6);

    BinaryTreeTest bt;
    int n1=2, n2=3;
    int dist = bt.findDistance(root,n1, n2);
    if (dist>=0)
    {cout << "\nDistance between "<<n1<<" and "<<n2<<" is : " << dist <<"\n";}
    return 0; 
}