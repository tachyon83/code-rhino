#include <iostream>
#define endl '\n'
using namespace std;
const int sz=1e3+10;
int t,n,parent[sz],inorder[sz],preorder[sz],idxInorder[sz];
pair<int,int>children[sz];

void binaryTree(int preS,int preE,int inS,int inE,int r,int fs){
    int root=preorder[preS];
    parent[root]=r;
    if(r!=-1){
        if(!fs)children[r].first=root;
        else children[r].second=root;
    }
    int rootIdx=idxInorder[root];
    int cntLeft=rootIdx-inS;
    int cntRight=inE-rootIdx;

    if(cntLeft)binaryTree(preS+1,preS+cntLeft,inS,rootIdx-1,root,0);
    if(cntRight)binaryTree(preS+cntLeft+1,preE,rootIdx+1,inE,root,1);
}
void postOrder(int root){
    int left=children[root].first;
    int right=children[root].second;
    if(left)postOrder(left);
    if(right)postOrder(right);
    cout<<root<<' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>t;
    while(t--){
        cin>>n;
        fill(parent,parent+n+1,0);
        fill(inorder,inorder+n+1,0);
        fill(preorder,preorder+n+1,0);
        fill(idxInorder,idxInorder+n+1,0);
        fill(children,children+n+1,make_pair(0,0));
        for(int i=0;i<n;++i)cin>>preorder[i];
        for(int i=0;i<n;++i){
            cin>>inorder[i];
            idxInorder[inorder[i]]=i;
        }
        
        binaryTree(0,n-1,0,n-1,-1,0);
        postOrder(preorder[0]);
        cout<<endl;
    }
    return 0;
}
