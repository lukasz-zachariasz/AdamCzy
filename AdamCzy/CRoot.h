#pragma once
#include <string>
#include <vector>

class CRoot
{
	friend class CTreeNode;
public:
	CRoot();
	std::string show();
private:
	std::string *pc_name;
	CTreeNode *pc_child;
	std::vector<std::string> *pc_sObjects;
	std::vector<int> *pc_iObjects;
};