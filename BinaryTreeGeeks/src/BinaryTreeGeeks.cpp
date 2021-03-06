//============================================================================
// Name        : BinaryTreeGeeks.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "BinaryTreeGeeks.h"
/***************************************************************************
 * Start Convert singly linked list to complete binary tree
 **************************************************************************/
LinkedListToCompleteBinaryTree::LinkedListToCompleteBinaryTree(){
	head=NULL;
	root=NULL;
}

SinglyLinkedNode* LinkedListToCompleteBinaryTree::insertLinked(int data){
	SinglyLinkedNode* newnode=new SinglyLinkedNode();
	newnode->next=NULL;
	newnode->data=data;
	cout<<"Inserted data in linked "<<newnode->data<<endl;
	return newnode;
}
void LinkedListToCompleteBinaryTree::insertRandomLinkedList(){
	head=insertLinked(1);
	head->next=insertLinked(2);
	head->next->next=insertLinked(3);
	head->next->next->next=insertLinked(4);
	head->next->next->next->next=insertLinked(5);
	head->next->next->next->next->next=insertLinked(6);
	head->next->next->next->next->next->next=insertLinked(7);

	head->next->next->next->next->next->next->next=insertLinked(15);
	head->next->next->next->next->next->next->next->next=insertLinked(8);
	head->next->next->next->next->next->next->next->next->next=insertLinked(9);
	head->next->next->next->next->next->next->next->next->next->next=insertLinked(10);
	head->next->next->next->next->next->next->next->next->next->next->next=insertLinked(11);
	head->next->next->next->next->next->next->next->next->next->next->next->next=insertLinked(12);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next=insertLinked(13);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next=insertLinked(14);


}
void LinkedListToCompleteBinaryTree::inorderHelper(BinaryTreeNode *node){
	    if(node){
		inorderHelper(node->left);
		cout<<node->data<<"->";
		inorderHelper(node->right);
	}
}
BinaryTreeNode* LinkedListToCompleteBinaryTree::linkedListToCompleteBinaryTree(){
	if(head){
		root=linkedListToCompleteBinaryTree(head);
		inorderHelper(root);
		return root;
	}

	return NULL;
}

BinaryTreeNode * LinkedListToCompleteBinaryTree::insert(int newdata){
	BinaryTreeNode *newnode = new BinaryTreeNode();
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = newdata;
	cout<<"inserted data "<<newdata<<"successfully"<<endl;
	return newnode;
}

BinaryTreeNode* LinkedListToCompleteBinaryTree::linkedListToCompleteBinaryTree(SinglyLinkedNode* head){
	queue<BinaryTreeNode*> q;
	if(head==NULL){
		return NULL;
	}
	SinglyLinkedNode* current=head;
	root=insert(current->data);
	q.push(root);
	while(!q.empty()){
		BinaryTreeNode* top=q.front();
		cout<<"Top ele is "<<top->data<<endl;
		q.pop();
		if(current->next){
			cout<<"If curr->next is "<<current->next->data<<endl;
			top->left=insert(current->next->data);
			q.push(top->left);
			current=current->next;
		}
		if(current->next){
			cout<<"If curr->next for right is "<<current->next->data<<endl;
			top->right=insert(current->next->data);
			q.push(top->right);
			current=current->next;
			}
	}

	return root;
}
/***************************************************************************
 * End Convert singly linked list to complete binary tree
 **************************************************************************/
/***************************************************************************
 * Start Linked complete binary tree and its creation(INCOMPLETE)
 **************************************************************************/
void LinkedListToCompleteBinaryTree::insertCompleteBinaryTree(){
	int data;
	queue<BinaryTreeNode*> q;
	for(int i=0;i<6;i++){
		cin>>data;
		insertCompleteBinaryTreeHelper(q,data);
	}


	cout<<q.front()->data;
	q.pop();
	cout<<q.front()->data;
	cout<<"Inorder Traversal is:"<<endl;
	inorderHelper(root);
}

void LinkedListToCompleteBinaryTree::insertCompleteBinaryTreeHelper(queue<BinaryTreeNode*> &q,int data){
	BinaryTreeNode* newnode=insert(data);
	if(root==NULL){
		root=newnode;
		(q).push(newnode);
	}
	else{
		BinaryTreeNode* top=(q).front();
		if(top->left){
			if(top->right){  //both left and right exist so delete this node
				(q).pop();
				top=(q).front();
				top->left=newnode;
				(q).push(top->left);
			}
			else{
				top->right=newnode;
				(q).push(top->right);
			}
		}
		else{
			top->left=newnode;
			(q).push(top->left);
		}
	}
	cout<<"Front data"<<q.front()->data<<endl;
}
/*****************************************************************************************
 * End Linked complete binary tree and its creation
 *****************************************************************************************/
/*****************************************************************************************
 * Start Largest independent set in binary tree
 *****************************************************************************************/
int LinkedListToCompleteBinaryTree::LISS(){
	if(root){
		return LISSHelper(root);
	}
	return 0;
}
int LinkedListToCompleteBinaryTree::LISSHelper(BinaryTreeNode* root){
	int incl=1,excl=0;
	//if excluding root
	if(root==NULL){
		return 0;
	}
	excl+=LISSHelper(root->left)+LISSHelper(root->right);
	if(root->left){
		incl+=LISSHelper(root->left->left)+LISSHelper(root->left->right);
	}
	if(root->right){
			incl+=LISSHelper(root->right->left)+LISSHelper(root->right->right);
	}
	return max(incl,excl);
}
/*****************************************************************************************
 * End Largest independent set in binary tree
 *****************************************************************************************/

/*****************************************************************************************
 * Start Convert binary tree to doubly linked list Set3
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::convertBinaryTreeToDoubly(){
	BinaryTreeNode* head;
	head=NULL;
	convertBinaryTreeToDoublyHelper(root,&head);
	printList(head);
}

void LinkedListToCompleteBinaryTree::convertBinaryTreeToDoublyHelper(BinaryTreeNode* root,BinaryTreeNode** head){
	static BinaryTreeNode* prev=NULL;
	if(root==NULL){
		return;
	}
	convertBinaryTreeToDoublyHelper(root->left,head);
	if(prev==NULL){
		*head=root;
		prev=root;
	}
	else{
	root->left=prev;
	prev->right=root;
	prev=root;
	}
	convertBinaryTreeToDoublyHelper(root->right,head);
}

void LinkedListToCompleteBinaryTree::printList(BinaryTreeNode* head){
	BinaryTreeNode* tmp=head;
	while(tmp){
			if(tmp->right){
				cout<<"Next of "<<tmp->data<<"is "<<tmp->right->data<<endl;
				tmp=tmp->right;
			}

		}
}
/*****************************************************************************************
 * End Convert binary tree to doubly linked list Set3
 *****************************************************************************************/

/*****************************************************************************************
 * Start Convert binary tree to doubly linked list Set2
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::fixLeftPtr(BinaryTreeNode* root,BinaryTreeNode** head){
	static BinaryTreeNode* prev=NULL;
	if(root==NULL){
		return;
	}
	*head=root;
	fixLeftPtr(root->right,head);
	if(prev){
		prev->left=root;
	}
	prev=root;
	fixLeftPtr(root->left,head);
}

void LinkedListToCompleteBinaryTree::fixRightPtr(BinaryTreeNode* root){
	static BinaryTreeNode* prev=NULL;
	if(root==NULL){
		return;
	}
	fixRightPtr(root->right);
	while(root->left){
		prev=root->left;
		prev->right=root;
		root=prev;
	}
}
void LinkedListToCompleteBinaryTree::convertBinaryTreeToDoublySet2(){
	BinaryTreeNode* head;
	head=NULL;
	fixLeftPtr(root,&head);
	fixRightPtr(root);
	printList(head);
}
/*****************************************************************************************
 * Start Convert binary tree to doubly linked list Set2
 *****************************************************************************************/

/*****************************************************************************************
 * Start Convert binary tree to doubly linked list Set1
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::convertBinaryTreeToDoublySet1(){
	if(root){
		inorderHelper(root);
	BinaryTreeNode* head=convertBinaryTreeToDoublySet1(root);
	while(head->left){
		head=head->left;
	}
	printList(head);
	delete head;
	}
}

BinaryTreeNode* LinkedListToCompleteBinaryTree::convertBinaryTreeToDoublySet1(BinaryTreeNode* root){
	if(root==NULL){
		return NULL;
	}
	if(root->left){
	BinaryTreeNode* alist=convertBinaryTreeToDoublySet1(root->left);
	for(;alist->right!=NULL;alist=alist->right);
	root->left=alist;
	alist->right=root;
	}
	if(root->right){
	BinaryTreeNode* blist=convertBinaryTreeToDoublySet1(root->right);
	for(;blist->left!=NULL;blist=blist->left);
	root->right=blist;
	blist->left=root;
	}
return root;
}
/*****************************************************************************************
 * End Convert binary tree to doubly linked list Set1
 *****************************************************************************************/
/*****************************************************************************************
 * Start Find Lowest Common Ancestor of two nodes
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::LCAPrint(int n1,int n2){
	BinaryTreeNode* lca=findLCA(n1,n2);
	if(lca){
		cout<<"Lowest common ancestor is "<<lca->data<<endl;
	}
	else{
		cout<<"No Lowest common ancestor exists."<<endl;
	}
}
BinaryTreeNode* LinkedListToCompleteBinaryTree::findLCA(int n1,int n2){
	if(root){
		bool b1=false;
		bool b2=false;
		BinaryTreeNode* lca=findLCAHelper(root,n1,n2,b1,b2);
		if(b1 && b2){
			return lca;
		}
		else{
			if(b1){
				if(findPath(lca,n2))
				return lca;
			}
			else if(b2){
				if(findPath(lca,n1))
				return lca;
			}
		}
	}
	return NULL;
}

bool LinkedListToCompleteBinaryTree::findPath(BinaryTreeNode* root,int node1){
	if(root==NULL){
		return false;
	}
	if(root->data==node1){
		return true;
	}
	return findPath(root->left,node1)||findPath(root->right,node1);
}
BinaryTreeNode* LinkedListToCompleteBinaryTree::findLCAHelper(BinaryTreeNode* root,int n1,int n2,bool &b1,bool &b2){
	if(root==NULL){
		return NULL;
	}
	if(root->data==n1){
		b1=true;
		return root;
	}
	if(root->data==n2){
		b2=true;
		return root;
	}
	BinaryTreeNode* left_lca=findLCAHelper(root->left,n1,n2,b1,b2);
	BinaryTreeNode* right_lca=findLCAHelper(root->right,n1,n2,b1,b2);
	if(left_lca&& right_lca){
		return root;
	}
	if(left_lca){
		return left_lca;
	}
	else{
		return right_lca;
	}
}
/*****************************************************************************************
 * End Find Lowest Common Ancestor of two nodes
 *****************************************************************************************/
/*****************************************************************************************
 * Start Find distance between given two nodes in a binary tree
 *****************************************************************************************/
int LinkedListToCompleteBinaryTree::findDist(int n1,int n2){
	int d1=-1,d2=-1,dist=0;
	BinaryTreeNode* lca=findDistLCAHelper(root,n1,n2,d1,d2,dist,0);
	if(d1!=-1 && d2!=-1){
		return dist;
	}
	if(d1!=-1){
		dist=findDistHelper(lca,n2,0);
		return dist;
	}
	if(d2!=-1){
		dist=findDistHelper(lca,n1,0);
		return dist;
		}
	return -1;
}
int LinkedListToCompleteBinaryTree::findDistHelper(BinaryTreeNode* root,int node,int dist){
	if(root==NULL){
		return -1;
	}
	if(root->data==node){
		return dist;
	}
	return findDistHelper(root->left,node,dist+1)||findDistHelper(root->right,node,dist+1);
}
BinaryTreeNode* LinkedListToCompleteBinaryTree::findDistLCAHelper(BinaryTreeNode* root,int n1,int n2,int& d1,int& d2,int& dist,int lvl){
	if(root==NULL){
		return NULL;
	}
	if(root->data==n1){
		d1=lvl;
		return root;
	}
	if(root->data==n2){
		d2=lvl;
		return root;
	}
	BinaryTreeNode* left_lca=findDistLCAHelper(root->left,n1,n2,d1,d2,dist,lvl+1);
	BinaryTreeNode* right_lca=findDistLCAHelper(root->right,n1,n2,d1,d2,dist,lvl+1);
	if(left_lca && right_lca){
		dist=d1+d2-2*lvl;
	}
	if(left_lca){
		return left_lca;
	}
	else{
		return right_lca;
	}
}
/*****************************************************************************************
 * End Find distance between given two nodes in a binary tree
 *****************************************************************************************/
/******************************************************************************************
 * Start Sum of all the numbers that are formed from root to leaf paths
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::sumHelper(BinaryTreeNode* root,int &sum,int digit){

	if(root==NULL){
		return;
	}
	digit=10*digit+root->data;
	if(root->left==NULL && root->right==NULL){
		sum+=digit;
	}
	sumHelper(root->left,sum,digit);
	sumHelper(root->right,sum,digit);
}

void LinkedListToCompleteBinaryTree::findSum(){
	int sum=0;
	sumHelper(root,sum,0);
	cout<<endl<<"Sum is "<<sum<<endl;
}
/******************************************************************************************
 * End Sum of all the numbers that are formed from root to leaf paths
 *****************************************************************************************/
/******************************************************************************************
 * Start Remove all nodes which don’t lie in any path with sum>= k
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::removeAllPathsSumLessThanK(int k){
	if(root){
		int sum=0;
		//removeAllPathsSumLessThanKHelper(root,&sum,k);
		removeAllPathsSumLessThanKHelper2(root,k);
		inorderHelper(root);
	}
}
BinaryTreeNode* LinkedListToCompleteBinaryTree::removeAllPathsSumLessThanKHelper(BinaryTreeNode* root,int* sum,int k){
	if(root==NULL){
		return NULL;
	}
	int lsum=*sum+root->data;
	int rsum=*sum+root->data;
	root->left=removeAllPathsSumLessThanKHelper(root->left,&lsum,k);
	root->right=removeAllPathsSumLessThanKHelper(root->right,&rsum,k);
	*sum=max(lsum,rsum);
	cout<<endl<<"Now sum is "<<*sum<<"at "<<root->data<<endl;
	if(max(lsum,rsum)<k){
		delete root;
		root=NULL;
	}
	return root;
}

BinaryTreeNode* LinkedListToCompleteBinaryTree::removeAllPathsSumLessThanKHelper2(BinaryTreeNode* root,int k){
	if(root==NULL){
		return NULL;
	}
	root->left=removeAllPathsSumLessThanKHelper2(root->left,k-(root->data));
	root->right=removeAllPathsSumLessThanKHelper2(root->right,k-(root->data));
	if(root->left==NULL && root->right==NULL){
	if(root->data<k){
		delete root;
		root=NULL;
	}
	}
	return root;
}
/******************************************************************************************
 * End Remove all nodes which don’t lie in any path with sum>= k
 *****************************************************************************************/

/******************************************************************************************
 * Start Print ancestors of a given binary tree without recursion
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::printAncestorsWithoutRecursion(int key){
	stack<BinaryTreeNode*> s;
	while(1){
		while(root && root->data!=key){
			s.push(root);
			root=root->left;
		}
		if(root && root->data==key){
			cout<<"Found"<<endl;
			break;
		}
		if(s.top()->right==NULL){
			root=s.top();
			s.pop();
			while(root && s.top()->right==root){
				root=s.top();
				s.pop();
			}
		}
		if(s.top()->right){
			root=s.top()->right;
		}
		else root=NULL;
	}
	while(!s.empty()){
		root=s.top();
		s.pop();
		cout<<root->data<<"->";
	}
}
/******************************************************************************************
 * End Print ancestors of a given binary tree without recursion
 *****************************************************************************************/

/******************************************************************************************
 * Start Difference between odd level and even level of a binary tree
 *****************************************************************************************/
int LinkedListToCompleteBinaryTree::diff(){
	if(root){
		return diffHelper(root);
	}
	return 0;
}
int LinkedListToCompleteBinaryTree::diffHelper(BinaryTreeNode* root){
	if(root==NULL){
		return 0;
	}
	else return root->data-diffHelper(root->left)-diffHelper(root->right);
}
/******************************************************************************************
 * End Difference between odd level and even level of a binary tree
 *****************************************************************************************/

/******************************************************************************************
 * Start Depth of deepest odd level left leaf node a binary tree
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::depthLeftLeaf(){
	if(root){
		int maxlvl=0;
		depthLeftLeafHelper(root,0,&maxlvl,false);
		cout<<"Depth of deepest odd level left leaf node a binary tree "<<maxlvl<<endl;
	}
}
void LinkedListToCompleteBinaryTree::depthLeftLeafHelper(BinaryTreeNode* root,int lvl,int *maxlvl,bool isLeft){
	if(root==NULL){
		return;
	}
	if((root->left==NULL&& root->right==NULL)&& isLeft && (lvl&1) ){
		if(lvl>*maxlvl){
			*maxlvl=lvl;
		}
	}
	depthLeftLeafHelper(root->left,lvl+1,maxlvl,true);
	depthLeftLeafHelper(root->right,lvl+1,maxlvl,false);
	}
/******************************************************************************************
 * End Depth of deepest odd level left leaf node a binary tree
 *****************************************************************************************/
/******************************************************************************************
 * Start Check if all leaves are at same level in a binary tree
 *****************************************************************************************/
bool LinkedListToCompleteBinaryTree::checkLeavesLevel(){
	if(root){
		int samelevel=0;
		return checkLeavesLevelHelper(root,0,&samelevel);
	}
	return true;
}
bool LinkedListToCompleteBinaryTree::checkLeavesLevelHelper(BinaryTreeNode* root,int lvl,int *samelevel){
	if(root==NULL){
		return true;
	}
	if(root->left==NULL&& root->right==NULL){
		if(*samelevel==0){
			*samelevel=lvl;
		}
		else{
			if(*samelevel!=lvl){
				return false;
			}
		}
	}

	return checkLeavesLevelHelper(root->left,lvl+1,samelevel)&& checkLeavesLevelHelper(root->right,lvl+1,samelevel);
}
/******************************************************************************************
 * End Check if all leaves are at same level in a binary tree
 *****************************************************************************************/

/******************************************************************************************
 * Start Extract Leaves of a Binary Tree in a Doubly Linked List
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::extractLeaves(){
	if (root){
		BinaryTreeNode* head=NULL;
		extractLeavesHelper(root,&head);
		while(head){
			cout<<(head)->data<<"->";
			head=(head)->left;
		}
	}
}

BinaryTreeNode* LinkedListToCompleteBinaryTree::extractLeavesHelper(BinaryTreeNode* root,BinaryTreeNode** head){
	if(root==NULL){
		return NULL;
	}
	if(root->left==NULL && root->right==NULL){
		cout<<"For root "<<root->data<<endl;
		root->right=*head;
		if(*head!=NULL){
			(*head)->left=root;
		}


		*head=root;

		return NULL;
	}

	root->right=extractLeavesHelper(root->right,head);
	root->left=extractLeavesHelper(root->left,head);
	return root;
}
/******************************************************************************************
 * End Extract Leaves of a Binary Tree in a Doubly Linked List
 *****************************************************************************************/

/******************************************************************************************
 * Start Check if a given Binary Tree is height balanced like a Red-Black Tree
 *****************************************************************************************/
bool LinkedListToCompleteBinaryTree::isBalancedLikeRedBlackHelper(){
	int minh=0;
	int maxh=0;
	return isBalancedLikeRedBlackHelper(root,minh,maxh);
}
bool LinkedListToCompleteBinaryTree::isBalancedLikeRedBlackHelper(BinaryTreeNode* root,int &minh,int &maxh){
	if(root==NULL){
		return true;
	}
	int lmin=0,lmax=0,rmin=0,rmax=0;
	if(!isBalancedLikeRedBlackHelper(root->left,lmin,lmax)){
		return false;
	}
	if(!isBalancedLikeRedBlackHelper(root->right,rmin,rmax)){
		return false;
	}
	minh=min(lmin,rmin)+1;
	maxh=max(lmax,rmax)+1;
	if(maxh>2*minh){
		return false;
	}
	return true;
}
/******************************************************************************************
 * End Check if a given Binary Tree is height balanced like a Red-Black Tree
 *****************************************************************************************/
/******************************************************************************************
 * Start Print all nodes at distance k from a given node
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::printAllNodesAtK(int node,int k){
	if(root && k>=0){
		printAllNodesAtKHelper(root,node,k);
	}
}

void LinkedListToCompleteBinaryTree::printAllNodesDown(BinaryTreeNode* root,int k){
	if(root==NULL||k<0){
		return;
	}
	if(k==0){
		cout<<root->data;
	}
	printAllNodesDown(root->left,k-1);
	printAllNodesDown(root->right,k-1);
}

int LinkedListToCompleteBinaryTree::printAllNodesAtKHelper(BinaryTreeNode* root,int node,int k){
	if(root==NULL){
		return -1;
	}
	if(node==root->data){
		printAllNodesDown(root,k);
		return 0;
	}
	int dl=printAllNodesAtKHelper(root->left,node,k);
	if(dl!=-1){
		if(dl+1==k){
			cout<<root->data<<"->";
		}
		else
		printAllNodesDown(root->right,k-dl-2);
		return 1+dl;
	}

	int dr=printAllNodesAtKHelper(root->right,node,k);
		if(dr!=-1){
			if(dr+1==k){
				cout<<root->data<<"->";
			}
			else
			printAllNodesDown(root->left,k-dr-2);


		return 1+dr;
}
		return -1;
}
/******************************************************************************************
 * End Print all nodes at distance k from a given node
 *****************************************************************************************/
/******************************************************************************************
 * Start Print a Binary Tree in Vertical Order
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::printInVerticalOrder(){
	if(root){
		int maxhd=0,minhd=0,HD=0;
		findMinMaxHD(root,maxhd,minhd,HD);
		cout<<"Minimum and maximum HD are"<<minhd<<maxhd<<endl;
		for(int i=minhd;i<=maxhd;i++){
			cout<<"Nodes with HD "<<i<<"are :";
			printHDValues(root,i);
			cout<<endl;
		}
	}
}
void LinkedListToCompleteBinaryTree::printHDValues(BinaryTreeNode* root,int HD){
	if(root==NULL){
		return;
	}
	if(HD==0){
		cout<<root->data<<"->";
	}
	printHDValues(root->left,HD+1);
	printHDValues(root->right,HD-1);
}
void LinkedListToCompleteBinaryTree::findMinMaxHD(BinaryTreeNode* root,int& maxhd,int& minhd,int HD){
	if(root==NULL){
		return;
	}
	if(HD<minhd){
		minhd=HD;
	}
	if(HD>maxhd){
		maxhd=HD;
	}
	findMinMaxHD(root->left,maxhd,minhd,HD-1);
	findMinMaxHD(root->right,maxhd,minhd,HD+1);
}
/******************************************************************************************
 * End Print a Binary Tree in Vertical Order
 *****************************************************************************************/
/******************************************************************************************
 * Start Find the maximum path sum between two leaves of a binary tree
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::maxSumPathBetweenLeavesHelper(){
	if(root){
		int maxsum=0;
		maxSumPathBetweenLeavesHelper(root,maxsum);
		cout<<endl<<"Maximum path sum between two leaves "<<maxsum<<endl;
	}
}
int LinkedListToCompleteBinaryTree::maxSumPathBetweenLeavesHelper(BinaryTreeNode* root,int &maxsum){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}
	int ls=maxSumPathBetweenLeavesHelper(root->left,maxsum);
	int rs=maxSumPathBetweenLeavesHelper(root->right,maxsum);
	if((ls+rs+root->data)>maxsum){
		maxsum=ls+rs+root->data;
	}
	return max(ls,rs)+root->data;
}
/******************************************************************************************
 * End Find the maximum path sum between two leaves of a binary tree
 *****************************************************************************************/
/******************************************************************************************
 * Start Reverse alternate levels of a perfect binary tree
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::inorderStoreAlternateLevel(BinaryTreeNode* root,int arr[],int& index,int level){
	if(root){
		inorderStoreAlternateLevel(root->left,arr,index,level+1);
		if(level&1){
		arr[index++]=root->data;
		}
		inorderStoreAlternateLevel(root->right,arr,index,level+1);
	}
}

void LinkedListToCompleteBinaryTree::reverseArray(int arr[],int len){
	for(int i=0;i<len/2;i++){
		int tmp=arr[i];
		arr[i]=arr[len-i-1];
		arr[len-i-1]=tmp;
	}
}

void LinkedListToCompleteBinaryTree::inorderModifyAndStoreAlternateLevel(BinaryTreeNode* root,int arr[],int& index,int level){
	if(root){
		inorderModifyAndStoreAlternateLevel(root->left,arr,index,level+1);
		if(level&1){
			root->data=arr[index++];
		}
		inorderModifyAndStoreAlternateLevel(root->right,arr,index,level+1);
	}
}

void LinkedListToCompleteBinaryTree::reverseAlternateLevelsPerfectBT(){
	if(root){
		int index=0;
		int arr[50];
		inorderStoreAlternateLevel(root,arr,index,0);
		reverseArray(arr,index);
		index=0;
		inorderModifyAndStoreAlternateLevel(root,arr,index,0);
		inorderHelper(root);
	}
}
/******************************************************************************************
 * End Reverse alternate levels of a perfect binary tree
 *****************************************************************************************/
/******************************************************************************************
 * Start Check if two nodes are cousins in a Binary Tree
 *****************************************************************************************/
int LinkedListToCompleteBinaryTree::levelNode(BinaryTreeNode* root,int node,int lvl){
	if(root==NULL){
		return 0;
	}
	if(root->data==node){
		return lvl;
	}
	int l=levelNode(root->left,node,lvl+1);
	if(l!=0) return l;
	return levelNode(root->right,node,lvl+1);
}

bool LinkedListToCompleteBinaryTree::areSiblings(BinaryTreeNode* root,int node1,int node2){
	if(root==NULL){
		return false;
	}
	if(root->left==NULL||root->right==NULL){
		return false;
	}

	if(((root->left && root->right&& (root->left->data==node1 && root->right->data==node2))) || ((root->left && root->right)&&(root->right->data==node1 && root->left->data==node2))|| areSiblings(root->left,node1,node2) || areSiblings(root->right,node1,node2)){
		return true;
	}

	return false;
}

bool LinkedListToCompleteBinaryTree::areCousins(int node1,int node2){
	if(root){
		if((levelNode(root,node1,0)==levelNode(root,node2,0))&& !areSiblings(root,node1,node2)){
			cout<<node1<<"and "<<node2<<" are cousins"<<endl;
			return true;
		}
		return false;
	}
	return false;
}
/******************************************************************************************
 * End Check if two nodes are cousins in a Binary Tree
 *****************************************************************************************/
/******************************************************************************************
 * Start Find sum of all left leaves in a given Binary Tree
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::sumLeftLeavesBT(){
	if(root){
		int sum=0;
		sumLeftLeaves(root,sum,false);
		cout<<"Sum of all left leaves is "<<sum<<endl;
	}
}
void LinkedListToCompleteBinaryTree::sumLeftLeaves(BinaryTreeNode* root,int& sum,bool isLeft){
	if(root==NULL){
		return;
	}
	cout<<"Root being is "<<root->data<<endl;
	if(root->left==NULL && root->right==NULL && isLeft){
		sum+=root->data;
	}
	sumLeftLeaves(root->left,sum,true);
	sumLeftLeaves(root->right,sum,false);
}
/******************************************************************************************
 * End Find sum of all left leaves in a given Binary Tree
 *****************************************************************************************/
/******************************************************************************************
 * Start Find maximum in a given Binary Tree
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::findMax(){
	if(root){
		int maxi=INT_MIN;
		maximum(root,maxi);
		cout<<"Maximum is "<<maxi<<endl;
	}
}
void LinkedListToCompleteBinaryTree::maximum(BinaryTreeNode* root,int& maxi){
	if(root==NULL){
		return ;
	}
	if(root->data>maxi){
		maxi=root->data;
	}
	maximum(root->left,maxi);
	maximum(root->right,maxi);
}
/******************************************************************************************
 * End check if a given Binary Tree is a subtree of another BT
 *****************************************************************************************/
void LinkedListToCompleteBinaryTree::isSubtreeStoreArray(BinaryTreeNode* root,char preS[],int& index){
	if(root==NULL){
		preS[index++]='$';
		return;
	}
	preS[index++]=root->data+'0';
	isSubtreeStoreArray(root->left,preS,index);
	isSubtreeStoreArray(root->right,preS,index);
}

void LinkedListToCompleteBinaryTree::isSubtreeStoreInorderArray(BinaryTreeNode* root,char inS[],int& index){
	if(root==NULL){
		inS[index++]='$';
		return;
	}
	isSubtreeStoreArray(root->left,inS,index);
	inS[index++]=root->data+'0';
	isSubtreeStoreArray(root->right,inS,index);
}

bool LinkedListToCompleteBinaryTree::isSubtreeHelper(BinaryTreeNode* subtree,BinaryTreeNode* root){
	if(subtree==NULL){
		return true;
	}
	if(root==NULL){
		return false;
	}
	char inS[50];
	int index=0;
	char inT[50];
	isSubtreeStoreInorderArray(root,inS,index);
	inS[index]='\0';
	index=0;
	isSubtreeStoreInorderArray(root,inT,index);
	if(strstr(inS,inT)==false)
		return false;
	return true;
}

bool LinkedListToCompleteBinaryTree::isSubtree(){
	if(root){
		return isSubtreeHelper(subtree,root);
	}
	return false;
}

/******************************************************************************************
 * Start Find the distance of closest leaf in a Binary Tree
 *****************************************************************************************/
int LinkedListToCompleteBinaryTree::getMin(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
int LinkedListToCompleteBinaryTree::closestLeafDown(BinaryTreeNode* root){
	if(root==NULL){
		return INT_MAX;
	}
	if(root->left==NULL && root->right==NULL){
		return 0;
	}
	return 1+getMin(closestLeafDown(root->left),closestLeafDown(root->right));
}
int LinkedListToCompleteBinaryTree::closestLeaf(BinaryTreeNode* root,BinaryTreeNode* ancestors[],int index,int key){
	if(root==NULL){
		return INT_MAX;
	}
	if(root->left==NULL && root->right==NULL){
		return 0;
	}
	if(root->data==key){
		int res=closestLeafDown(root);
		for(int i=index-1;i>=0;i--){
			res=getMin(res,index-i+closestLeafDown(ancestors[index]));
		}
		return res;
	}
	ancestors[index++]=root;
	return getMin(closestLeaf(root->left,ancestors,index,key),closestLeaf(root->right,ancestors,index,key));
}

int LinkedListToCompleteBinaryTree::findClosestLeafDistance(int key){
	if(root){
		BinaryTreeNode* ancestors[50];
		int index=0;
		return closestLeaf(root,ancestors,index,key);
	}
	return INT_MAX;
}
/******************************************************************************************
 * End Find the distance of closest leaf in a Binary Tree
 *****************************************************************************************/
/******************************************************************************************
* Start Given a binary tree, how do you remove all the half nodes?
******************************************************************************************/
void LinkedListToCompleteBinaryTree::removeAllHalfNodes(){
	if(root){
		root=removeHalfNodes(root);
		inorderHelper(root);
	}
}
BinaryTreeNode* LinkedListToCompleteBinaryTree::removeHalfNodes(BinaryTreeNode* root){
	if(root==NULL){
		return NULL;
	}
	root->left=removeHalfNodes(root->left);
	root->right=removeHalfNodes(root->right);
	if(root->left==NULL && root->right==NULL){
		return root;
	}
	if(root->left&& !root->right){
		BinaryTreeNode* new_root=root->left;
		return new_root;
	}
	if(!root->left&& root->right){
		BinaryTreeNode* new_root=root->right;
		return new_root;
	}
	return root;
}
/******************************************************************************************
* End Given a binary tree, how do you remove all the half nodes?
******************************************************************************************/
/******************************************************************************************
* Start Convert left-right representation of a binary tree to down-right
******************************************************************************************/
void LinkedListToCompleteBinaryTree::convertToDownRight(){
	if(root==NULL){
		return;
	}
	queue<BinaryTreeNode*> q;
	q.push(root);
	while(!q.empty()){
		int tmp_size=q.size();
		BinaryTreeNode* firstnode=NULL;
		while(tmp_size>0){
			BinaryTreeNode* extractnode=q.front();
			if(!firstnode){
				firstnode=extractnode;
			}

			if(extractnode->left){
				q.push(extractnode->left);
			}
			if(extractnode->right){
				q.push(extractnode->right);
			}
			extractnode->left=NULL;
			q.pop();
			if(tmp_size==1){
				extractnode->right=NULL;
			}
			else{
				extractnode->right=q.front();
			}
			tmp_size--;
		}
		if(!q.empty()){
		firstnode->left=q.front();
		}
		else break;
	}

	inorderHelper(root);
}
/******************************************************************************************
* End Convert left-right representation of a binary tree to down-right
******************************************************************************************/

/******************************************************************************************
* Start Convert a Binary Tree to Threaded binary tree
******************************************************************************************/
void LinkedListToCompleteBinaryTree::storeInorder(BinaryTreeNode* root,BinaryTreeNode* in[],int& index){
	if(root==NULL){
		return;
	}
	storeInorder(root->left,in,index);

	in[index++]=root;

	storeInorder(root->right,in,index);
}
void LinkedListToCompleteBinaryTree::retrieveInorderAndConvertThreaded(BinaryTreeNode* root,BinaryTreeNode* in[],int& index,int len){
	if(root==NULL || index>=len){
			return;
	}


	retrieveInorderAndConvertThreaded(root->left,in,index,len);
	index++;
	if(root->right){
	retrieveInorderAndConvertThreaded(root->right,in,index,len);
	}
	else{
		if(index<len){
		root->right=in[index];

		}
	}

}
void LinkedListToCompleteBinaryTree::convertToThreadedBT(){
	BinaryTreeNode* in[50];
	int index=0;
	storeInorder(root,in,index);
	cout<<"Data is fo rindex"<<index<<endl;
	for(int i=0;i<index;i++){
		cout<<in[i]->data<<" ";
	}
	int len=index;
	index=0;

	retrieveInorderAndConvertThreaded(root,in,index,len);
	cout<<"Threaded binary tree is"<<endl;
	while(root->left){
		root=root->left;
	}
	while(root){
		cout<<root->data<<" ";
		root=root->right;
	}
}
/******************************************************************************************
* End Convert a Binary Tree to Threaded binary tree
******************************************************************************************/

/******************************************************************************************
* Start Perfect Binary Tree Specific Level Order Traversal
******************************************************************************************/
void LinkedListToCompleteBinaryTree::perfectBTSpecificLevelOrder(){
	if(root==NULL){
		return;
	}
	queue<BinaryTreeNode*> q;

	cout<<root->data<<" ";
	if(root->left){
		cout<<root->left->data<<" ";
		q.push(root->left);
	}
	if(root->right){
		cout<<root->right->data<<" ";
		q.push(root->right);
	}
	while(!q.empty()){
		BinaryTreeNode* first;
		BinaryTreeNode* second;
		first=q.front();
		q.pop();
		second=q.front();
		q.pop();
		if(first->left){
			cout<<first->left->data<<" ";
			q.push(first->left);
		}
		if(second->right){
					cout<<second->right->data<<" ";
					q.push(second->right);
				}

		if(first->right){
					cout<<first->right->data<<" ";
					q.push(first->right);
				}
		if(second->left){
							cout<<second->left->data<<" ";
							q.push(second->left);
						}

	}
}
