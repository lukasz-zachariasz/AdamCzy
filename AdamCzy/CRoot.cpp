#pragma once
#include "CRoot.h"
#include "CTreeNode.h"

CRoot::CRoot()
{
	pc_name = new std::string;
	*pc_name = "Nothing.";
	pc_child = new CTreeNode();
	pc_sObjects = new std::vector < std::string > ;
	pc_iObjects = new std::vector < int > ;
}

std::string CRoot::show(){
	std::string result = "";
	for (int i = 0; i < (*pc_iObjects).size(); i++)
	{
		result = result + std::to_string(i+1) + ". " + std::to_string((*pc_iObjects).at(i)) + " x " + (*pc_sObjects).at(i) + "\n";
	}
	return result;
}