#pragma once
#include "CTreeNode.h"

CTreeNode::CTreeNode()
{
	imultiplier = 0;
	pc_vChildNodes = new std::vector < CTreeNode > ;
	pc_name = new std::string;
	*pc_name = "Nothing";
}

CTreeNode::CTreeNode(int multiplier, std::string name)
{
	imultiplier = multiplier;
	pc_name = new std::string;
	*pc_name = name;
	pc_vChildNodes = new std::vector < CTreeNode >;
}

CTreeNode::CTreeNode(const CTreeNode& node)
{
	pc_name = new std::string;
	pc_vChildNodes = new std::vector < CTreeNode > ;
	*pc_name = *(node.pc_name);
	*pc_vChildNodes = *(node.pc_vChildNodes);
	imultiplier = node.imultiplier;
}

CTreeNode::~CTreeNode()
{
	delete pc_name;
	delete pc_vChildNodes;
}

std::string CTreeNode::getName()
{
	return *pc_name;
}

int CTreeNode::getMultipilier()
{
	return imultiplier;
}

std::string CTreeNode::showDirectChildsNames()
{
	int x = (*pc_vChildNodes).size();
	if (x == 0)	return "Nothing here.";
	std::string result;
	for (int i = 0; i < x;i++)
	{
		result=result + (*pc_vChildNodes).at(i).getName() + " ";
	}

	return result;
}

std::string CTreeNode::showAllChildsNames()
{
	int x = (*pc_vChildNodes).size();
	if (x == 0)	return "Nothing here.";
	std::string result;
	for (int i = 0; i < x; i++)
	{

		result = result + (*pc_vChildNodes).at(i).getName() + (*pc_vChildNodes).at(i).showAllChildsNames() + " ";
	}

	return result;
}

void CTreeNode::count(int multiplier, const CRoot& root)
{
	int x = (*(root).pc_iObjects).size();
	int multi = imultiplier*multiplier;
	std::string name = *pc_name;
	for (unsigned int i = 0; i < x; i++)
	{
		if ((*pc_name).compare((*(root).pc_sObjects).at(i))==0)
		{
			(*(root).pc_iObjects).at(i) = (*(root).pc_iObjects).at(i) + multi;
		}
		else
		{
			(*(root).pc_sObjects).push_back(name);
			(*(root).pc_iObjects).push_back(multi);
		}
	}
	if ((*(root).pc_iObjects).size() == 0)
	{
		(*(root).pc_sObjects).push_back(name);
		(*(root).pc_iObjects).push_back(multi);
	}
	for (unsigned int i = 0; i < (*pc_vChildNodes).size(); i++)
	{
		(*pc_vChildNodes).at(i).count(multi, root);
	}
}

void CTreeNode::addChild(CTreeNode node)
{
	(*pc_vChildNodes).push_back(node);
}