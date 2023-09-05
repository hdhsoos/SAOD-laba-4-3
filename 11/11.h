#pragma once

struct treeNode
{
    int data;
    treeNode* left;
    treeNode* right;
} *treeRoot, * parentNode;

typedef struct Stack {
    int level = -1;
    treeNode* data{};
    Stack* next{ nullptr };
};

void search(treeNode* currentNode, int data);
void build_tree(treeNode* currentNode, int level);
void in_order(treeNode* currentNode, int level);
void in_order_back(treeNode* currentNode, int level);
void iter_in_order(treeNode* root);
treeNode* addNode(treeNode* Node, int data);
void clearTree(treeNode* currentNode);
int main();
