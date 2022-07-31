void pree(Node* root,int a[],int &n)
{
    if(root==NULL)
        return;
    pree(root->left,a,n);
    a[n++]=root->key;
    pree(root->right,a,n);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    int a[1000],n=0;
    pree(root,a,n);
    int f=0;
    for(int i=0;i<n;i++)
    {
        Node* t=new Node(a[i]);
        if(a[i]<key)
            pre=t;
        if(a[i]>key)
        {
            f=1;
            suc=t;
            break;
        }
    }
    if(f==0)
    {
        Node* h=new Node(-1);
        suc=h;
    }
}
