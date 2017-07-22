#include <iostream>
using namespace std;
#include<queue>
struct Node
{
	int Key;
	Node* Left;
	Node* Right;
};
void Asign(int key, int parent, Node* nodeptr);
struct Node* GetNewNode(void);
void PrintNodeData(int index);
void LevelOrder(Node* nodeptr);

int findlevel(Node* Root, int nodeNumber, int level);
struct Node *lca(struct Node* root, int n1, int n2);
Node *findDistUtil(Node* root, int n1, int n2, int &d1, int &d2, int &dist, int lvl);
int findDistance(Node *root, int n1, int n2);
int FindTotalDistance(Node* nodeptr);

Node* edgePtr[1000];
int current=0;
int BFSArray[50];
int main()
{
	int Test_Case,T,N,KeysParent;
	FILE* InputFile;
	InputFile = fopen("Seetaram.txt", "r");
	fscanf(InputFile, "%d", &T);
	for (Test_Case = 1; Test_Case <= T; Test_Case++)
	{
		edgePtr[1] = GetNewNode();
		edgePtr[1]->Key = 1;
		edgePtr[1]->Left = NULL;
		edgePtr[1]->Right = NULL;

		fscanf(InputFile, "%d", &N);
		for (int i = 2; i <=N; i++)
		{		
			//get the instance of the node
			edgePtr[i] = GetNewNode();
		}
		for (int i = 2; i <= N; i++)
		{
			fscanf(InputFile, "%d", &KeysParent);
			//asign the key to the node
			Asign(i, KeysParent, edgePtr[i]);
		}
		LevelOrder(edgePtr[1]);
		cout << FindTotalDistance(edgePtr[1])<<"\n";
	}
	/*for (int i = 1; i <= N; i++)
	{
		PrintNodeData(i);
	}*/
	
}
void PrintNodeData(int index)
{
	printf("%d\n", edgePtr[index]->Key);
	//printf("%d", edgePtr[index]->Left);
	//printf("%d", edgePtr[index]->Right);
}




//get the instance of the node
Node* GetNewNode(void)
{
	Node* NewNodePtr;
	NewNodePtr = new Node;
	NewNodePtr->Key = 0;
	NewNodePtr->Left = NULL;
	NewNodePtr->Right = NULL;
	return NewNodePtr;
}
//asign the key to the node:input:key,nodeparent,nodePtr
void Asign(int key, int parent, Node* nodeptr)
{
	if (edgePtr[parent]->Left == NULL)
	{
		edgePtr[parent]->Left = nodeptr;		
	}
	else
	{
		edgePtr[parent]->Right = nodeptr;
	}
	nodeptr->Key = key;
}


void LevelOrder(Node* nodeptr)
{	
	Node* temp;
	if (nodeptr == NULL)
		return;
	queue<Node*> Q;
	Q.push(nodeptr);
	while (!Q.empty())
	{
		temp = Q.front();
		//printf("%d\n", temp->Key);
		BFSArray[current] = temp->Key;
		current++;
		Q.pop();
		if((temp->Left)!=NULL)Q.push(temp->Left);
		if ((temp->Right) != NULL)Q.push(temp->Right);

	}
}

int FindTotalDistance(Node* nodeptr)
{
	int sum = 0;
	for (int i = 0; i < current-1; i++)
	{
		sum += findDistance(nodeptr, BFSArray[i], BFSArray[i + 1]);
	}
	for (int i = 0; i < current; i++)
	{
		BFSArray[i]=0;
	}
	current = 0;
	return sum;
}

int findlevel(Node* Root, int nodeNumber, int level)
{
	int temp = -1;
	if (Root == NULL)
	{
		return -1;
	}
	if (Root->Key == nodeNumber)
	{
		return level;
	}
	temp = findlevel(Root->Left, nodeNumber, level + 1);
	return (temp != -1) ? temp : findlevel(Root->Right, nodeNumber, level + 1);
}


struct Node *lca(struct Node* root, int n1, int n2)
{
	if (root == NULL) return NULL;

	// If both n1 and n2 are smaller than root, then LCA lies in left
	if (root->Key > n1 && root->Key > n2)
		return lca(root->Left, n1, n2);

	// If both n1 and n2 are greater than root, then LCA lies in right
	if (root->Key < n1 && root->Key < n2)
		return lca(root->Right, n1, n2);

	return root;
}

// This function returns pointer to LCA of two given values n1 and n2. 
// It also sets d1, d2 and dist if one key is not ancestor of other
// d1 --> To store distance of n1 from root
// d2 --> To store distance of n2 from root
// lvl --> Level (or distance from root) of current Node
// dist --> To store distance between n1 and n2
Node *findDistUtil(Node* root, int n1, int n2, int &d1, int &d2, int &dist, int lvl)
{
	// Base case
	if (root == NULL) return NULL;

	// If either n1 or n2 matches with root's key, report
	// the presence by returning root (Note that if a key is
	// ancestor of other, then the ancestor key becomes LCA
	if (root->Key == n1)
	{
		d1 = lvl;
		return root;
	}
	if (root->Key == n2)
	{
		d2 = lvl;
		return root;
	}

	// Look for n1 and n2 in left and right subtrees
	Node *left_lca = findDistUtil(root->Left, n1, n2, d1, d2, dist, lvl + 1);
	Node *right_lca = findDistUtil(root->Right, n1, n2, d1, d2, dist, lvl + 1);

	// If both of the above calls return Non-NULL, then one key
	// is present in once subtree and other is present in other,
	// So this node is the LCA
	if (left_lca && right_lca)
	{
		dist = d1 + d2 - 2 * lvl;
		return root;
	}

	// Otherwise check if left subtree or right subtree is LCA
	return (left_lca != NULL) ? left_lca : right_lca;
}


// The main function that returns distance between n1 and n2
// This function returns -1 if either n1 or n2 is not present in
// Binary Tree.
int findDistance(Node *root, int n1, int n2)
{
	// Initialize d1 (distance of n1 from root), d2 (distance of n2 
	// from root) and dist(distance between n1 and n2)
	int d1 = -1, d2 = -1, dist;
	Node *lca = findDistUtil(root, n1, n2, d1, d2, dist, 1);

	// If both n1 and n2 were present in Binary Tree, return dist
	if (d1 != -1 && d2 != -1)
		return dist;

	// If n1 is ancestor of n2, consider n1 as root and find level 
	// of n2 in subtree rooted with n1
	if (d1 != -1)
	{
		dist = findlevel(lca, n2, 0);
		return dist;
	}

	// If n2 is ancestor of n1, consider n2 as root and find level 
	// of n1 in subtree rooted with n2
	if (d2 != -1)
	{
		dist = findlevel(lca, n1, 0);
		return dist;
	}

	return -1;
}
