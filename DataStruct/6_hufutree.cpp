#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef struct HuFuNode
{
	int weight;
	int parent, LTree, RTree;
}HuFuNode, *PHuFuNode;

void Select(PHuFuNode HuFuNode, int n, int &s1, int &s2)    
{
    for(int i = 1; i < n; i++){         
        if(HuFuNode[i].parent == 0){     
            s1 = i;					
            break;          
        }
    }

    for(int i = 1; i < n; i++){         
            if(HuFuNode[i].parent == 0 && HuFuNode[s1].weight > HuFuNode[i].weight)
                s1 = i;
    }

    for(int j = 1; j < n; j++){        
        if(HuFuNode[j].parent == 0 && j != s1){
            s2 = j;
            break;
        }
    }

    for(int j = 1; j < n; j++){         
        if(HuFuNode[j].parent == 0 && HuFuNode[s2].weight > HuFuNode[j].weight && j != s1)
            s2 = j;
    }
}

void initHuFuNode(PHuFuNode &H, int n)
{
	if(n <= 1) return;
	int m = 2*n - 1;            //数组共2n - 1个元素
	H = new HuFuNode[m + 1];	//0号单元未用，H[m]表示根节点
    for(int i = 1; i <= m; i++){
        H[i].parent = 0;
        H[i].LTree = 0;
        H[i].RTree = 0;
    }
	for(int i = 1; i <= n; i++)
        cin >> H[i].weight;
    cout << endl;
    for(int i = n + 1; i <= m; i++)         
    {
        int s1, s2;
        Select(H, i, s1, s2);
        H[s1].parent = i;
        H[s2].parent = i;   
        H[i].LTree = s1;
        H[i].RTree = s2;
        H[i].weight = H[s1].weight + H[s2].weight;
    }
    for(int i =1 ;i<=m;i++){
        cout<<H[i].weight<<" ";
    }
}

int main()
{
    PHuFuNode HuFuNode;
    int n = 0;
    cin >> n;
    initHuFuNode(HuFuNode, n);
	return 0;
}
