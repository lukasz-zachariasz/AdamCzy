#pragma once
#include <vector>
#include <string>
#include "CRoot.h"

class CTreeNode
{
public:
	CTreeNode();
	CTreeNode(const CTreeNode& node, CTreeNode childnode);
	CTreeNode(int multiplier, std::string name);
	CTreeNode(const CTreeNode& node);
	~CTreeNode();
	std::string getName();
	int getMultipilier();
	std::string showDirectChildsNames();
	std::string showAllChildsNames();
	void count(int multiplier, const CRoot& root);
	void addChild(CTreeNode node);

	int parse(int n, std::string in);
	int brackets(std::string in);
	int parse1(int n, std::string in);
	int find(int n, std::string in, int x); 
	//x=0-->" x=1-->(


private:
	std::vector<CTreeNode> *pc_vChildNodes;
	std::string *pc_name;
	int imultiplier;
};