#pragma once
#include <vector>
#include <string>
#include "CRoot.h"

class CTreeNode
{
public:
	CTreeNode();
	CTreeNode(int multiplier, std::string name);
	CTreeNode(const CTreeNode& node);
	~CTreeNode();
	std::string getName();
	int getMultipilier();
	std::string showDirectChildsNames();
	std::string showAllChildsNames();
	void count(int multiplier, const CRoot& root);
	void addChild(CTreeNode node);

private:
	std::vector<CTreeNode> *pc_vChildNodes;
	std::string *pc_name;
	int imultiplier;
};