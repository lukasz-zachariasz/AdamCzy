#pragma once
#include <string>
#include <vector>

class CRoot
{
	friend class CTreeNode;
public:

private:
	std::string *pc_name;
	CTreeNode *pc_Child;
	std::vector<std::string> *pc_sObjects;
	std::vector<int> *pc_iObcjects;
};