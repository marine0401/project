#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<queue>
using namespace std;

typedef struct BinTreeNode{
	char data;
	struct BinTreeNode *left;
	struct BinTreeNode *right;
}BinTreeNode;

void midLastTree(BinTreeNode **root, char *LVR, char *LRV, int n){
	if(n == 0){
		*root = NULL;
		return;
	}else{
		int k = 0;
		while(LVR[k] != LRV[n-1]){
			k++;
		}

		(*root) = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		(*root)->data = LRV[n-1];
		midLastTree(&(*root)->right, LVR+k+1, LRV+k, n-k-1);
		midLastTree(&(*root)->left, LVR, LRV, k);

	}
}

void levelTree(BinTreeNode *root){
	queue<BinTreeNode *> qu;

	if(root){
		qu.push(root);
		while(!qu.empty()){
			BinTreeNode *p = qu.front();
			qu.pop();
			printf("%c ", p->data);
			if(p->left){
				qu.push(p->left);
			}
			if(p->right){
				qu.push(p->right);
			}
		}
	}
}	

void preShow(BinTreeNode *root){
	if(root){
		printf("%c ", root->data);
		preShow(root->left);
		preShow(root->right);
	}
}

int main(void){
	char *LVR;
	char *LRV;
	int n;
	BinTreeNode *root = NULL;

	printf("������������Ϊ: ");
	scanf("%d", &n);
	fflush(stdin);
	LVR = (char *)malloc(sizeof(char) * n);
	LRV = (char *)malloc(sizeof(char) * n);
	printf("������������(�ַ�����ʽ����): ");
	gets(LVR);
	fflush(stdin);
	printf("�����������(�ַ�����ʽ����): ");
	gets(LRV);
	midLastTree(&root, LVR, LRV, n);

	printf("���α���Ϊ: ");
	levelTree(root);
	printf("\n��ǰ�����Ϊ: ");
	preShow(root);
	printf("\n");

	return 0;
}
