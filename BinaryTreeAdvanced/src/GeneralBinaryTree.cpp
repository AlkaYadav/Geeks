/*
 * GeneralBinaryTree.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: user
 */
#include "GeneralBinaryTree.h"

GeneralBinaryTree::GeneralBinaryTree(){
	root=NULL;
	root2=NULL;
}

BinaryTreeNode * GeneralBinaryTree::insert(int newdata){
BinaryTreeNode *newnode = new BinaryTreeNode();
newnode->left = NULL;
newnode->right = NULL;
newnode->data = newdata;
cout<<"inserted data "<<newdata<<"successfully"<<endl;
return newnode;
}

void GeneralBinaryTree::insertRandom(){

	root=insert(1);
	root->left=insert(2);
	root->right=insert(3);

	root->left->left=insert(4);
	root->left->right=insert(5);
	root->right->left=insert(6);
	root->left->right->left=insert(7);
	root->left->right->right=insert(8);

    root2=insert(1);
    root2->right=insert(2);
    root2->left=insert(3);
    root2->right->left=insert(4);
    root2->right->right=insert(5);
    root2->left->left=insert(7);
    root2->right->right->left=insert(8);
    root2->right->right->right=insert(7);
/*
//Foldable Binary tree data
	root=insert(10);
	root->left=insert(7);
	root->right=insert(15);

	root->left->right=insert(6);
	root->right->right=insert(6);
	root->right->left=insert(7);
	*/
	/*Sum Tree data
	root=insert(10);
	root->left=insert(-2);
	root->right=insert(6);
	root->left->left=insert(8);
	root->left->right=insert(-4);
	root->right->left=insert(7);
	root->right->right=insert(5);
	*/
	/*Subtree data
	root=insert(26);
	root->left=insert(10);
	root->right=insert(3);
	root->left->left=insert(4);
	root->left->right=insert(6);
	root->left->left->right=insert(30);
	root->right->right=insert(3);

	root2=insert(4);
	root2->left=insert(4);
	root2->right=insert(6);
	root2->left->right=insert(30);

*/
}
void GeneralBinaryTree::inorderHelper(BinaryTreeNode *node){
	    if(node){
		inorderHelper(node->left);
		cout<<node->data<<"->";
		inorderHelper(node->right);
	}
}
/*********************************************************************
 * Start Double binary tree
 ********************************************************************/
void GeneralBinaryTree::doubleTreeHelper(BinaryTreeNode* root){
	if(root==NULL){
			return;
		}
	doubleTreeHelper(root->left);
	doubleTreeHelper(root->right);
	if(root->left){
				BinaryTreeNode* newnode=insert(root->data);
				BinaryTreeNode* currleft=root->left;
				root->left=newnode;
				newnode->left=currleft;
			}
			else{
				BinaryTreeNode* newnode=insert(root->data);
				root->left=newnode;
			}
}
void GeneralBinaryTree::doubleTree(){
	if(root){
		doubleTreeHelper(root);
		cout<<"Inorder.."<<endl;
		inorderHelper(root);
	}

}
/*********************************************************************
 * End Double binary tree
 ********************************************************************/
int GeneralBinaryTree::heightBinaryTreeHelper(BinaryTreeNode *root){
	if(root == NULL){
		return 0;
	}
	int lheight=heightBinaryTreeHelper(root->left);
	int rheight=heightBinaryTreeHelper(root->right);
	if(lheight>rheight){
		return lheight+1;
	}
	else return rheight+1;
}
int GeneralBinaryTree::maxWidth(){
	int height=heightBinaryTreeHelper(root);
	int maxwidth=0;
	for(int i=1;i<=height;i++){
		int width=maxWidthHelper(root,i);
		cout<<endl<<"Width of level "<<i<<"is "<<width<<endl;
		if(width>maxwidth){
			maxwidth=width;
		}
	}
	return maxwidth;
}

int GeneralBinaryTree::maxWidthHelper(BinaryTreeNode *root,int level){
	if(root==NULL){
		return 0;
	}
	if(level==1){
		return 1;
	}

	return maxWidthHelper(root->left,level-1)+
			maxWidthHelper(root->right,level-1);

}

/********************************************************************************
 * Start Maximum width of binary tree O(n)
 ********************************************************************************/
int GeneralBinaryTree::maxWidthPreorder(){
	int height=heightBinaryTreeHelper(root);
	int a[height],maxwidth=INT_MIN;
	for(int i=1;i<=height;i++){
		a[i]=0;
	}
	if(root){
		maxWidthHelperPreorder(root,1,a);
	}
	for(int i=1;i<=height;i++){
		if(a[i]>maxwidth){
			maxwidth=a[i];
		}
	}
	return maxwidth;
}
void GeneralBinaryTree::maxWidthHelperPreorder(BinaryTreeNode *root,int level,int a[])
{
	if(root){
		a[level]++;
		maxWidthHelperPreorder(root->left,level+1,a);
		maxWidthHelperPreorder(root->right,level+1,a);
	}
}

/********************************************************************************
 * End Maximum width of binary tree O(n)
 ********************************************************************************/

/********************************************************************************
 * Start Get level of a node in binary tree O(n)
 ********************************************************************************/
int GeneralBinaryTree::getLevelOfNode(int data){
	if(root){
		return getLevelOfNodeHelper(root,data,1);
	}
	return -1;
}

int GeneralBinaryTree::getLevelOfNodeHelper(BinaryTreeNode* root,int data,int level){
if(root==NULL){
	return -1;
}
if(data==root->data){
	return level;
}
int downlevel= getLevelOfNodeHelper(root->left,data,level+1);
if(downlevel!=-1){
	return downlevel;
}
else return getLevelOfNodeHelper(root->right,data,level+1);
}

/********************************************************************************
 * End Get level of a node in binary tree O(n)
 ********************************************************************************/

/********************************************************************************
 * Start Determine if binary tree is foldable O(n)
 ********************************************************************************/
bool GeneralBinaryTree::isFoldable(){
if(root){
	return isFoldableHelper(root->left,root->right);
}
return true;
}

bool GeneralBinaryTree::isFoldableHelper(BinaryTreeNode* node1,BinaryTreeNode* node2){
if(node1==NULL && node2==NULL){
	return true;
}
if(node1==NULL||node2==NULL){
	return false;
}
return isFoldableHelper(node1->left,node2->right)&&
		isFoldableHelper(node1->right,node2->left);
}
/********************************************************************************
 * End Determine if binary tree is foldable O(n)
 ********************************************************************************/
/********************************************************************************
 * Start Print nodes at distance k from root O(n)
 ********************************************************************************/
void GeneralBinaryTree::printNodesAtDistanceKFromRoot(int k){
	if(root){
		printNodesAtDistanceKFromRootHelper(root,k);
	}
}

void GeneralBinaryTree::printNodesAtDistanceKFromRootHelper(BinaryTreeNode* root,int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<"->";
		return;
	}
	else if(k>0){
		printNodesAtDistanceKFromRootHelper(root->left,k-1);
		printNodesAtDistanceKFromRootHelper(root->right,k-1);
	}
}
/********************************************************************************
 * Start Print ancestors of a given node O(n)
 ********************************************************************************/
void GeneralBinaryTree::printAncestorsOfNode(int data){
	if(root){
		int a[150];
		printAncestorsOfNodeHelper(root,data,a,0);
		cout<<endl<<"Second Method"<<endl;
		printAncestorsOfNodeHelperOther(root,data);
	}
}

void GeneralBinaryTree::printArray(int a[],int index){
	for(int i=0;i<index;i++){
		cout<<a[i]<<"->";
	}
	cout<<endl;
}
void GeneralBinaryTree::printAncestorsOfNodeHelper(BinaryTreeNode* root,int data,int a[],int index){

	if(root==NULL){
		return;
	}
	a[index++]=root->data;
	if(data==root->data){
		printArray(a,index);
	}
	else{
	printAncestorsOfNodeHelper(root->left,data,a,index);
	printAncestorsOfNodeHelper(root->right,data,a,index);
}
}

bool GeneralBinaryTree::printAncestorsOfNodeHelperOther(BinaryTreeNode* root,int data){
	if(root==NULL){
		return false;
	}
	if(data==root->data){
		//cout<<root->data<<"->";
		return true;
	}
	if( printAncestorsOfNodeHelperOther(root->left,data)||
			printAncestorsOfNodeHelperOther(root->right,data)){
		cout<<root->data<<"->";
		return true;
	}
	return false;
}
/********************************************************************************
 * End Print ancestors of a given node O(n)
 ********************************************************************************/
/********************************************************************************
 * Start Check if binary tree is Sum tree
 ********************************************************************************/
bool GeneralBinaryTree::ifSumTree(){
	if(root){
		return isSumTreeHelper(root);
	}
	return true;
}

bool GeneralBinaryTree::isSumTreeHelper(BinaryTreeNode* root){
	if(root==NULL || (root->left==NULL && root->right==NULL)){
		return true;
	}
	return (root->data==sumOptimized(root))&&isSumTreeHelper(root->left)&& isSumTreeHelper(root->right);
}
int GeneralBinaryTree::sum(BinaryTreeNode* root){
	int s=0,ls=0,rs=0;
	if(root==NULL){
		return 0;
	}
	if(root->left){
		ls=root->left->data;
	}
	if(root->right){
		rs=root->right->data;
	}
	s+=ls+rs+sum(root->left)+sum(root->right);
	return s;
}
bool GeneralBinaryTree::isLeaf(BinaryTreeNode* root){
	if(root){
		return (root->left==NULL && root->right==NULL);
	}
	return false;
}
int GeneralBinaryTree::sumOptimized(BinaryTreeNode* root){
	int ls=0,rs=0;
	if(root==NULL){
		return 0;
	}
    if(root->left){
	if(isLeaf(root->left)){
		ls=root->left->data;
	}
	else if(!isLeaf(root->left) ){
	    	ls=2*(root->left->data);
	    }
    }
    if(root->right){
	if(isLeaf(root->right)){
			rs=root->right->data;
	}
	else if(!isLeaf(root->right)){
		rs=2*root->right->data;
	}
    }

    return (ls+rs);
}
/********************************************************************************
 * Start Convert a given tree to Sum tree
 ********************************************************************************/
void GeneralBinaryTree::convertToSum(){
	if(root){
		convertToSumHelper(root);
		cout<<endl<<"After conversion the inorder is"<<endl;
		inorderHelper(root);
	}
}

int GeneralBinaryTree::convertToSumHelper(BinaryTreeNode* root){
	if(root==NULL){
		return 0;
	}
	int old_data=root->data;
	root->data=convertToSumHelper(root->left)+convertToSumHelper(root->right);
	return old_data+root->data;
}
/********************************************************************************
 * End Convert a given tree to Sum tree
 ********************************************************************************/

/********************************************************************************
 * Start Check if a binary tree is a subtree of another tree O(mn)
 *******************************************************************************/
bool GeneralBinaryTree::areIdentical(BinaryTreeNode* root,BinaryTreeNode* subtree){
	if(root==NULL&& subtree==NULL){
		return true;
	}
	if(root==NULL|| subtree==NULL){
			return false;
		}
	if(root->data==subtree->data){
		return areIdentical(root->left,subtree->left) && areIdentical(root->right,subtree->right);
	}
	return false;
}
bool GeneralBinaryTree::checkIfSubtree(){
	if(root){
		return checkIfSubtreeHelper(root,root2);
	}
	return false;
}
bool GeneralBinaryTree::checkIfSubtreeHelper(BinaryTreeNode* root,BinaryTreeNode* subtree){
	if(subtree==NULL){
		return true;
	}
	if(root==NULL){
		return false;
	}
	if(areIdentical(root,subtree)){
		return true;
	}
return checkIfSubtreeHelper(root->left,subtree)||checkIfSubtreeHelper(root->right,subtree);
	}
/********************************************************************************
 * End Check if a binary tree is a subtree of another tree
 *******************************************************************************/
/*********************************************************************************
 * Start Populate inorder successor for all nodes
 **********************************************************************************/
void GeneralBinaryTree::populateInorderSuccessor(){
	if(root){
		populateInorderSuccessorHelper(root);
	}
}

void GeneralBinaryTree::populateInorderSuccessorHelper(BinaryTreeNode* root){
	static BinaryTreeNode* next=NULL;
	if(root){
		//Go for reverse inorder traversal
		populateInorderSuccessorHelper(root->right);
		root->next=next;
		if(next){
			cout<<"Inorder successor for "<<root->data<<"is "<<next->data<<endl;
		}
		else{
			cout<<"Inorder successor for "<<root->data<<"is None"<<endl;
		}
		next=root;
		populateInorderSuccessorHelper(root->left);
	}
}
/*********************************************************************************
 * End Populate inorder successor for all nodes
 **********************************************************************************/

/*********************************************************************************
 * Start Connect nodes at same level Using Queue
 **********************************************************************************/
void GeneralBinaryTree::connectNodesAtSameLevel(){
	queue<BinaryTreeNode*> q;
	int size;
	if(root==NULL){
		return;
	}
	q.push(root);

	while(!q.empty()){
		size=q.size();
		int tmp_size=size;
		BinaryTreeNode* top;
		while(tmp_size!=1){
			top=q.front();
			q.pop();
			top->next=q.front();
			cout<<endl<<"Setting next right of"<<top->data<<" to "<<q.front()->data<<endl;
			if(top->left){
				q.push(top->left);
			}
			if(top->right){
				q.push(top->right);
			}
			tmp_size--;
		}
		top=q.front();
		q.pop();
		top->next=NULL;
		cout<<endl<<"Setting next right of"<<top->data<<" to NULL"<<endl;
		if(top->left){
						q.push(top->left);
					}
					if(top->right){
						q.push(top->right);
					}
	}
}
/*********************************************************************************
 * End Connect nodes at same level Using Queue
 **********************************************************************************/
/*********************************************************************************
 * Start Connect nodes at same level Using Constant storage
 **********************************************************************************/
void GeneralBinaryTree::connectNodesSameLevelConstantStorage(){
	BinaryTreeNode* current=root;
	current->next=NULL;
	while(current){
		BinaryTreeNode* q=current;
		while(q){

			if(q->left){
				if(q->right){
					q->left->next=q->right;
					if(q->left->next)
					cout<<"Setting next of "<<q->left->data<<"to "<<q->right->data<<endl;
					else
						cout<<"Setting next of "<<q->left->data<<"to NULL"<<endl;
				}
				else{
					q->left->next=nextRight(q);
					if(q->left->next)
					cout<<"Setting next of "<<q->left->data<<"to "<<q->left->next->data<<endl;
					else
					cout<<"Setting next of "<<q->left->data<<"to NULL"<<endl;
				}
			}
			if(q->right){
				q->right->next=nextRight(q);
				if(q->right->next)
				cout<<"Setting next of "<<q->right->data<<"to "<<q->right->next->data<<endl;
				else
				cout<<"Setting next of "<<q->right->data<<"to NULL"<<endl;
			}
			if(q->next){
				q=q->next;
			}
			else break;
		}
		if(current->left){
			current=current->left;
		}
		else if(current->right){
			current=current->right;
		}
		else{
			current=nextRight(current);
		}
	}
}

BinaryTreeNode* GeneralBinaryTree::nextRight(BinaryTreeNode* root){
	if(!root->next){
		return NULL;
	}
	while(root->next){
		if(root->next->left){
			return root->next->left;
		}
		else if(root->next->right){
			return root->next->right;
		}
		else {
			root=root->next;
		}
	}
	return NULL;
}
/*********************************************************************************
 * End Connect nodes at same level Using Constant storage
 **********************************************************************************/
/*********************************************************************************
 * Start Find the vertical sum in a given binary tree
 **********************************************************************************/
void GeneralBinaryTree::verticalSum(){
	int arr[150];
	if(root){
		int HD=0;
		for(int i=0;i<150;i++){
			arr[i]=0;
		}
		verticalSumHelper(root,HD,arr);
	}
	for(int i=0;i<150;i++){
		if(arr[i]){
			cout<<"Vertical sum is"<<arr[i]<<endl;
		}
	}
}

void GeneralBinaryTree::verticalSumHelper(BinaryTreeNode* root,int HD,int arr[]){
	if(root){
		verticalSumHelper(root->left,HD-1,arr);
		if(HD>0){
		arr[HD]+=root->data;}
		else{
			arr[20+HD]+=root->data;
		}
		verticalSumHelper(root->right,HD+1,arr);
	}
}
/*********************************************************************************
 * End Find the vertical sum in a given binary tree
 **********************************************************************************/
/*********************************************************************************
 * Start Find the maximum sum root to leaf path in a given binary tree
 **********************************************************************************/
void GeneralBinaryTree::findMaximumSumRootToLeafPath(){
	if(root){
		BinaryTreeNode* target_leaf;
		int maxsum=0,cur_sum=0;
		findMaximumSumRootToLeafPathHelper(root,&target_leaf,maxsum,cur_sum);
		printPath(root,target_leaf);
	}
}

bool GeneralBinaryTree::printPath(BinaryTreeNode* root,BinaryTreeNode* target){
	if(root==NULL || target==NULL){
		return false;
	}
	if(root==target || printPath(root->left,target) || printPath(root->right,target)){
		cout<<root->data<<"->";
		return true;
	}
	return false;
}
void GeneralBinaryTree::findMaximumSumRootToLeafPathHelper(BinaryTreeNode* root,BinaryTreeNode** target,int &max_sum,int curr_sum){
	if(root==NULL){
		return;
	}
	if(root->left==NULL&& root->right==NULL){
		curr_sum+=root->data;
		if(curr_sum>max_sum){
			*target=root;
			max_sum=curr_sum;
		}
	}
	else{
		curr_sum+=root->data;
		findMaximumSumRootToLeafPathHelper(root->left,target,max_sum,curr_sum);
		findMaximumSumRootToLeafPathHelper(root->right,target,max_sum,curr_sum);
	}
}
/*********************************************************************************
 * End Find the maximum sum root to leaf path in a given binary tree
 **********************************************************************************/
/*********************************************************************************
 * Start Construct a special binary tree from given preorder traversal
 **********************************************************************************/
BinaryTreeNode* GeneralBinaryTree::newNode(int data){
	BinaryTreeNode * node=new BinaryTreeNode();
	node->data=data;
	node->right=NULL;
	node->left=NULL;
	cout<<"Constructed node"<<data<<endl;
	return node;
}
void GeneralBinaryTree::constructTreeFromPreorder(int pre[],char preLn[],int size){
	int preStart=0;
	root=constructTreeFromPreorderHelper(pre,preLn,&preStart,size);
	inorderHelper(root);
}

BinaryTreeNode* GeneralBinaryTree::constructTreeFromPreorderHelper(int pre[],char preLn[],int *preStart,int preEnd){

	int index=*preStart;
	if(index>preEnd){
		return NULL;
	}

	cout<<"Index "<<index<<endl;
	BinaryTreeNode* tNode=newNode(pre[index]);

	(*preStart)++;
	if(preLn[index]=='N'){

		tNode->left=constructTreeFromPreorderHelper(pre,preLn,preStart,preEnd);
		tNode->right=constructTreeFromPreorderHelper(pre,preLn,preStart,preEnd);
	}
	return tNode;
}
/*********************************************************************************
 * End Construct a special binary tree from given preorder traversal
 **********************************************************************************/

/*********************************************************************************
 * Start Check if a binary tree is complete
 **********************************************************************************/
bool GeneralBinaryTree::isCompleteBinaryTree(){

	queue<BinaryTreeNode*> q;
	bool isFull=true;
	if(root==NULL){
		return true;
	}
	q.push(root);
	cout<<"in "<<endl;
	while(!q.empty()){
		BinaryTreeNode* top=q.front();
		q.pop();
		cout<<"Popped "<<top->data<<endl;
		if(isFull==true){
			//Identify if full or nonfull
			if(top->left&& top->right){
				isFull=true;
			}
			else{
				isFull=false;
			}
			if(isFull==false){
				if(top->left){
					q.push(top->left);
				}
				else{
					if(top->right){
						return false;
					}
				}
			}
			else{
				q.push(top->left);
				q.push(top->right);
			}
		}

		else{
			if(top->left||top->right){
				return false;
			}
		}
	}
	return true;
}
/*********************************************************************************
 * End Check if a binary tree is complete
 **********************************************************************************/
/*********************************************************************************
 * Start Print Reverse level order traversal
 **********************************************************************************/
void GeneralBinaryTree::reverseLevelOrderTraversal(){
	queue<BinaryTreeNode*> q;
	stack<BinaryTreeNode*> s;
	if(root==NULL){
		return;
	}
	q.push(root);
	while(!q.empty()){
		BinaryTreeNode* top=q.front();
		s.push(top);
		q.pop();
		if(top->right){
			q.push(top->right);
		}
		if(top->left){
			q.push(top->left);
		}
	}
	while(!s.empty()){
		BinaryTreeNode* top2=s.top();
		s.pop();
		cout<<top2->data<<"->";
	}
}
/*********************************************************************************
 * End Print Reverse level order traversal
 **********************************************************************************/

/*********************************************************************************
 * Start Iterative method to find height of tree
 **********************************************************************************/
int GeneralBinaryTree::iterativeHeight(){
	queue<BinaryTreeNode*> q;
	int height=0;
	if(root==NULL){
		return 0;
	}
	q.push(root);
	int size;
	int tmp_size;
	while(!q.empty()){
		size=q.size();
		tmp_size=size;
		height++;

		while(tmp_size>0){
			BinaryTreeNode* top=q.front();
			q.pop();
			tmp_size--;
			if(top->right){
				q.push(top->right);
			}
			if(top->left){
				q.push(top->left);
			}
		}
	}

	return height;
}
/*********************************************************************************
 * End Iterative method to find height of tree
 **********************************************************************************/
/*********************************************************************************
 * Start Boundary traversal of a binary tree
 **********************************************************************************/
void GeneralBinaryTree::boundaryTraversal(){
	if(root){
		cout<<root->data<<"->";
		printLeftMostBoundary(root->left);
		printLeaves(root->left);
		printLeaves(root->right);
		printRightMostBoundary(root->right);
	}
}

void GeneralBinaryTree::printLeftMostBoundary(BinaryTreeNode* root){
	if(root){
	if(root->left){
		cout<<root->data<<"->";
		printLeftMostBoundary(root->left);
	}
	else if(root->right){
		cout<<root->data<<"->";
		printLeftMostBoundary(root->right);
	}
}
}
void GeneralBinaryTree::printLeaves(BinaryTreeNode* root){
	if(root){
		printLeaves(root->left);
		if(!(root->left) && !(root->right)){
			cout<<root->data<<"->";
		}
		printLeaves(root->right);
	}
}

void GeneralBinaryTree::printRightMostBoundary(BinaryTreeNode* root){
	if(root){
	if(root->right){
		printRightMostBoundary(root->right);
		cout<<root->data<<"->";
		}
	else if(root->left){
		printRightMostBoundary(root->left);
		cout<<root->data<<"->";
	}
}
}

/*********************************************************************************
 * End Boundary traversal of a binary tree
 **********************************************************************************/

/*********************************************************************************
 * Start Tree Isomorphism Problem
 **********************************************************************************/
bool GeneralBinaryTree::isIsomorphic(){
	if(root){
		return isIsomorphicHelper(root,root2);
	}
	return false;
}

bool GeneralBinaryTree::isIsomorphicHelper(BinaryTreeNode* root,BinaryTreeNode* root2){
	if(root==NULL && root2==NULL){
		return true;
	}
	if(root==NULL||root2==NULL){
		return false;
	}
	if(root->data!=root2->data){
		return false;
	}
	return (isIsomorphicHelper(root->left,root2->left)&& isIsomorphicHelper(root->right,root2->right))||
			(isIsomorphicHelper(root->left,root2->right)&& isIsomorphicHelper(root->right,root2->left));
}
/*********************************************************************************
 * End Tree Isomorphism Problem
 **********************************************************************************/
