
#include "../menu.h"
#include <iostream>
#include <windows.h>
#include <locale.h>
#include "../Tree.h"
#include <limits>
#include <stdlib.h>


int main()
{ 
	FontsSettings(0, 16);
	console = GetConsoleWindow();
	SetWindowPos(console, NULL, PosConsole.x, PosConsole.y, sizeConsole.x, sizeConsole.y, NULL);
	SetWindowLong(console, GWL_STYLE, WS_BORDER);
	ShowWindow(console, SW_SHOW);
	ExConsole();
	loading();		
				
	

	while (1) {
		field A[6] = { "Add new vertex to Tree", "line-by-line tree output based on Preorder_traversal", "line-by-line tree output based on Inorder_traversal", "line-by-line tree output based on Reverse_Inorder_traversal", "delete the tree", "Exit" };
		bool back = 0;
		int choice = menu(A, 6);

		if (choice == 0) {	
			while (!back) {
				back = Add(pRoot);
			}
		}

		else if (choice == 1) {
			while (!back) {
				field GET[3] = {"Tree output based on Preorder_traversal:" , "Back", ""};
				std::string res = "\n";
				Preorder_traversal(res, pRoot);
				GET[2].name = res;
				if (menu(GET, 3) == 1) {back = 1;}
			}
		}

		else if (choice == 2) {
			while (!back) {
				field GET[3] = { "Tree output based on Inorder_traversal:" , "Back", "" };
				std::string res = "\n";
				Inorder_traversal(res, pRoot);
				GET[2].name = res;
				if (menu(GET, 3) == 1) { back = 1; }
			}
		}

		else if (choice == 3) {
			while (!back) {
				field GET[3] = { "Tree output based on Reverse_Inorder_traversal:" , "Back", "" };
				std::string res = "\n";
				Reverse_Inorder_traversal(res, pRoot);
				GET[2].name = res;
				if (menu(GET, 3) == 1) { back = 1; }
			}
		}

		else if (choice == 4) {
			while (!back) {
				field DEL[2] = { "The tree was succesfully deleted" , "Back"};
				Delete(pRoot);
				pRoot = NULL;
				if (menu(DEL, 2) == 1) { back = 1; }
			}
		}

		else if (choice == 5) {
			exit(0);
		}
	}
		
	
	return 0;
}

