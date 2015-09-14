#pragma once
#include "main.h"

int main()
{
	CTreeNode *pc_cnode;
	pc_cnode = new CTreeNode();
	pc_cnode = new CTreeNode(5, "Something.");
	pc_cnode = new CTreeNode(*pc_cnode);
	(*pc_cnode).addChild(*pc_cnode);
	(*pc_cnode).addChild(*pc_cnode);
	(*pc_cnode).addChild(*pc_cnode);
	std::cout << (*pc_cnode).getName() << std::endl;
	std::cout << (*pc_cnode).getMultipilier() << std::endl;
	std::cout << (*pc_cnode).ShowDirectChildsNames() << std::endl;
	
	
	
	while (true);
	return 1;
}