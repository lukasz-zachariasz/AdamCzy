#pragma once
#include "main.h"

int main()
{
	CTreeNode *pc_cnode;
	CRoot *pc_croot;
	pc_croot = new CRoot();
	pc_cnode = new CTreeNode();
	pc_cnode = new CTreeNode(5, "Something.");
	pc_cnode = new CTreeNode(*pc_cnode);
	(*pc_cnode).addChild(*pc_cnode);
	(*pc_cnode).addChild(*pc_cnode);
	(*pc_cnode).addChild(*pc_cnode);
	std::cout << (*pc_cnode).getName() << std::endl;
	std::cout << (*pc_cnode).getMultipilier() << std::endl;
	std::cout << (*pc_cnode).showDirectChildsNames() << std::endl;
	std::cout << (*pc_cnode).showAllChildsNames() << std::endl;
	(*pc_cnode).count(1, *pc_croot);
	std::cout << (*pc_croot).show();
	std::cout << a;
	
	while (true);
	return 1;
}