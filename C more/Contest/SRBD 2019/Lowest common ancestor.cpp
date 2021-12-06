/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
///my efficient style for lca
map<Node *,Node *>parent;
Node *a,*b;
void dfs(Node *root,int v1,int v2){
    if(root==NULL)return;
    if(root->data==v1)a=root;
    if(root->data==v2)b=root;
    if(root->left){

        parent[root->left]=root;

        dfs(root->left,v1,v2);
    }
    if(root->right){
        parent[root->right]=root;


        dfs(root->right,v1,v2);
    }
}

    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        parent[root]=NULL;

        dfs(root,v1,v2);
        Node *arr[50],*arr2[50];
        int t1=0,t2=0;
        while(a)arr[t1++]=a,a=parent[a];
        while(b)arr2[t2++]=b,b=parent[b];
        int i,j;
        for(i=0;i<t1;i++){
            for(j=0;j<t2;j++)if(arr[i]==arr2[j])break;
            if(j<t2)break;
        }
        return arr[i];
    }
