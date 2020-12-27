#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
struct Tree{
    int right=0;
    int left=0;
};

Tree tree[1000001];

void DFS(int root)
{
    if(tree[root].left!=0) DFS(tree[root].left);
    if(tree[root].right!=0) DFS(tree[root].right);
    cout << root << endl;

}
int main()
{
    int num,root;
    bool flag=true;
    cin >> root;
    while (scanf("%d", &num) == 1)
    {
        //if(num ==0) break;
        int node = root;
        while(1)
        {
            //cout << "node:" << node << endl;
            if(node < num) //들어온게 노드보다 크면
            {
                if(tree[node].right==0)
                {
                    tree[node].right = num;
                    break;
                }
                else
                {
                    node =  tree[node].right;
                }
            }
            else // 들어온게 노드보다 작거나 같으면
            {
                if(tree[node].left==0)
                {
                    tree[node].left= num;
                    break;
                }
                else
                {
                    node =  tree[node].left;
                }
            }
        }

    }
    DFS(root);

}