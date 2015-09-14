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
}

CTreeNode::CTreeNode(const CTreeNode& node)
{
	pc_name = new std::string;
	pc_vChildNodes = new std::vector < CTreeNode > ;
	*pc_name = *(node.pc_name);
	*pc_vChildNodes = *(node.pc_vChildNodes);
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

std::string CTreeNode::ShowDirectChildsNames()
{
	return "Not Implemented Yet.";
}