#include <iostream>
#include "11.h"
using namespace std;

bool found = false;

void search(treeNode* currentNode, int data)
{
    if (!found)
    {
        if (currentNode != NULL)
        {
            search(currentNode->left, data);
            search(currentNode->right, data);
            if (currentNode->data == data)
            {
                found = true;
                parentNode = currentNode;
            }
        }
    }
}


void build_tree(treeNode* currentNode, int level)
{
    if (currentNode != NULL)
    {
        string numProbels;
        for (int i = 0; i < level; i++)
        {
            numProbels += "     ";
        }
        cout << numProbels << currentNode->data << endl;
        build_tree(currentNode->left, level + 1);
        build_tree(currentNode->right, level + 1);
    }
}

void in_order(treeNode* currentNode, int level)
{
    if (currentNode != NULL)
    {
        in_order(currentNode->left, level + 1);
        string numProbels;
        for (int i = 0; i < level; i++)
        {
            numProbels += "     ";
        }
        cout << numProbels << currentNode->data << endl;
        in_order(currentNode->right, level + 1);
    }
}



void in_order_back(treeNode* currentNode, int level)
{
    if (currentNode != NULL)
    {
        in_order_back(currentNode->right, level + 1);
        string numProbels;
        for (int i = 0; i < level; i++)
        {
            numProbels += "     ";
        }
        cout << numProbels << currentNode->data << endl;
        in_order_back(currentNode->left, level + 1);
    }
}


void iter_in_order(treeNode* root) {
    if (!root) return;
    int level{ 0 };
    Stack* st{ new Stack };
    st->data = root;
    treeNode* temp{ root };
    while (temp != nullptr || st->level >= 0) {
        while (temp) {
            Stack* cur{ new Stack };
            cur->next = st;
            cur->level = level;
            cur->data = temp;
            st = cur;
            temp = temp->left;
            level++;
        }
        level = st->level;
        temp = st->data;
        Stack* del{ st };
        st = st->next;
        delete del;


        cout << string(level * 4, ' ') << temp->data << '\n';

        temp = temp->right;
        level++;
    }
}


treeNode* addNode(treeNode* Node, int data)
{
    Node = new treeNode;
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

void clearTree(treeNode* currentNode)
{
    if (currentNode != NULL)
    {
        clearTree(currentNode->left);
        clearTree(currentNode->right);
        cout << "Удалили элемент дерева со значением " << currentNode->data << endl;
        delete currentNode;
    }
}


int main()
{
    setlocale(LC_ALL, "rus");
    int choice;
    int choice2;
    int element_to_add;
    int parentValue;
    while (true)
    {
        found = false;
        parentNode = NULL;
        cout << "Введите нужную вам команду:" << endl;
        cout << "1 - Добавить новый элемент в дерево" << endl;
        cout << "2 - Построчный вывод дерева на основе процедуры обхода в прямом порядке" << endl;
        cout << "3 - Построчный вывод дерева на основе процедуры обхода в симметричном порядке" << endl;
        cout << "4 - Построчный вывод дерева на основе процедуры обхода в обратно-симметричном порядке" << endl;
        cout << "5 - Построчный вывод дерева на основе процедуры обхода в симметричном порядке (итеративно)" << endl;
        cout << "6 - Очистить дерево" << endl;
        cout << "0 - Завершить программу" << endl;
        cin >> choice;
        cout << endl;
        if (choice == 1)
        {
            if (treeRoot == NULL)
            {
                cout << "Введите элемент, который хотите добавить" << endl;
                cin >> element_to_add;
                treeRoot = addNode(treeRoot, element_to_add);
            }
            else
            {
                cout << "Введите, какому элементу будем добавлять потомка" << endl;
                cin >> parentValue;
                search(treeRoot, parentValue);
                if (parentNode != NULL)
                {
                    if (parentNode->left == NULL && parentNode->right == NULL)
                    {
                        cout << "0 - Вставить новый элемент как левого потомка\n1 - Вставить новый элемент как правого потомка" << endl;
                        cin >> choice2;
                        while (choice2 != 0 && choice2 != 1) {
                            cout << "Ошибка, попробуйте снова\n0 - Вставить новый элемент как левого потомка\n1 - Вставить новый элемент как правого потомка" << endl;
                            cin >> choice2;
                        }
                        cout << "Введите элемент, который хотите добавить" << endl;
                        cin >> element_to_add;
                        if (choice2 == 0)
                        {
                            parentNode->left = addNode(parentNode->left, element_to_add);
                        }
                        else if (choice2 == 1)
                        {
                            parentNode->right = addNode(parentNode->right, element_to_add);
                        }
                    }
                    else if (parentNode->left != NULL && parentNode->right == NULL)
                    {
                        cout << "Введите элемент, который хотите добавить" << endl;
                        cin >> element_to_add;
                        parentNode->right = addNode(parentNode->right, element_to_add);
                    }
                    else if (parentNode->left == NULL && parentNode->right != NULL)
                    {
                        cout << "Введите элемент, который хотите добавить" << endl;
                        cin >> element_to_add;
                        parentNode->left = addNode(parentNode->left, element_to_add);
                    }
                    else if (parentNode->left != NULL && parentNode->right != NULL)
                    {
                        cout << "Невозможно добавить, у элемента уже есть два потомка" << endl;
                    }
                }
                else
                {
                    cout << "Такого элемента не существует" << endl;
                }
            }

        }
        else if (choice == 2)
        {
            build_tree(treeRoot, 0);
        }
        else if (choice == 3)
        {
            in_order(treeRoot, 0);
        }
        else if (choice == 4)
        {
            in_order_back(treeRoot, 0);
        }
        else if (choice == 5)
        {
            iter_in_order(treeRoot);
        }
        else if (choice == 6)
        {
            clearTree(treeRoot);
            treeRoot = NULL;
        }
        else if (choice == 0)
        {
            clearTree(treeRoot);
            break;
        }
        cout << endl;
    }
}
