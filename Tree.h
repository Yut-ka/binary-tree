#pragma once
#include "../menu.h"
#include <string>
#include <iostream>
#include <time.h>
#include <string>

struct Tree_Item {
public:
	int inf;
	Tree_Item* left;
	Tree_Item* right;
};

int stop = false;
Tree_Item* pRoot;
Tree_Item* pFind = new Tree_Item();




void Search(int inf, Tree_Item* pCurrent) {
	if (!stop) {
		if (pCurrent != NULL) {
			if (pCurrent->inf == inf) { stop = true; pFind = pCurrent; }
			Search(inf, pCurrent->left);
			Search(inf, pCurrent->right);
		}
	}
}

bool Add(Tree_Item*& pCurrent) {
	if (pCurrent == NULL) {
		pCurrent = new Tree_Item();
		int inf = std::stoi(Get_el_console("The Tree is empty. Enter the Root vertex:"));
		pCurrent->inf = inf;
		pCurrent->left = NULL;
		pCurrent->right = NULL;
		field ADD_ROOT[2] = { "Element was successfully added", "Back" };
		if (menu(ADD_ROOT, 2) == 1) return true;
	}
	else {
		int inf = std::stoi(Get_el_console("Enter the inf of parent vertex:"));
		stop = false;
		Search(inf, pRoot);
		std::string res = "The new vertex was successfully added";
		Tree_Item* pTemp = new Tree_Item();

		if (stop == true) {
			int inf = std::stoi(Get_el_console("Enter the inf of new vertex:"));
			if (pFind->left == NULL && pFind->right == NULL) {
				field ADD_TWO[2] = { "Add the left descendant vertex", "Add the right descendant vertex" };
				int ADD_TWO_choice = menu(ADD_TWO, 2);
				if (ADD_TWO_choice == 0) {
					pFind->left = pTemp;
					pTemp->inf = inf;
				}
				else if (ADD_TWO_choice == 1) {
					pFind->right = pTemp;
					pTemp->inf = inf;
				}
			}
			else if (pFind->left != NULL && pFind->right == NULL) {
				field ADD_ONER[1] = { "Add the right descendant vertex" };
				if (menu(ADD_ONER, 1) == 0) {
					pFind->right = pTemp;
					pTemp->inf = inf;
				}
			}
			else if (pFind->left == NULL && pFind->right != NULL) {
				field ADD_ONER[1] = { "Add the left descendant vertex" };
				if (menu(ADD_ONER, 1) == 0) {
					pFind->left = pTemp;
					pTemp->inf = inf;
				}
			}
			else{
				res = "Add impossible.The parent vertex has two descendant vertex";
			}
		}
		else {
			res = "Add impossible.The parent vertex not found";
		}
		field ADD[2] = { res, "Back" };
		if (menu(ADD, 2) == 1) return true;
	}
}

void Delete(Tree_Item*& pCurrent = pRoot) {
	if (pCurrent != NULL) {
		Delete(pCurrent->left);
		Delete(pCurrent->right);
		delete(pCurrent);
	}
}

void Preorder_traversal(std::string& str, Tree_Item* pCurrent, int t = 0) {
	if (pCurrent != NULL) {
		std::string line = "";
		for (int i = 0; i < t; i++) line += "\t";
		line = line + std::to_string(pCurrent->inf);
		str = str + line + "\n";
		Preorder_traversal(str, pCurrent->left, t + 1);
		Preorder_traversal(str, pCurrent->right, t + 1);
	}
}

void Inorder_traversal(std::string& str, Tree_Item* pCurrent, int t = 0) {
	if (pCurrent != NULL) {
		Inorder_traversal(str, pCurrent->left, t + 1);
		std::string line = "";
		for (int i = 0; i < t; i++) line += "\t";
		line = line + std::to_string(pCurrent->inf);
		str = str + line + "\n";
		Inorder_traversal(str, pCurrent->right, t + 1);
	}
}

void Reverse_Inorder_traversal(std::string& str, Tree_Item* pCurrent, int t = 0) {
	if (pCurrent != NULL) {
		Reverse_Inorder_traversal(str, pCurrent->right, t + 1);
		std::string line = "";
		for (int i = 0; i < t; i++) line += "\t";
		line = line + std::to_string(pCurrent->inf);
		str = str + line + "\n";
		Reverse_Inorder_traversal(str, pCurrent->left, t + 1);
	}
}