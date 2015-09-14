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
	std::string showDirectChildsNames();
	std::string showAllChildsNames();
	std::string count();
	std::string count(int multiplier);
	void addChild(CTreeNode node);

private:
	std::vector<CTreeNode> *pc_vChildNodes;
	std::string *pc_name;
	int imultiplier;
};