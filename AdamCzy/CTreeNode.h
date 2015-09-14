#pragma once
#include <vector>
#include <string>

class CTreeNode
{
public:
	CTreeNode();
	CTreeNode(int multiplier, std::string name);
	CTreeNode(const CTreeNode& node);
	~CTreeNode();
	std::string getName();
	int getMultipilier();
	std::string ShowDirectChildsNames();

private:
	std::vector<CTreeNode> *pc_vChildNodes;
	std::string *pc_name;
	int imultiplier;
};