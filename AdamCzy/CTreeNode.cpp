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


int CTreeNode::parse(int n, std::string in)
{
	CTreeNode no³d;
	if (brackets(in) == 1) return 1;
	return 0;
}

int CTreeNode::brackets(std::string in)
{
	int okragle = 0;
	int kwadratowe = 0;
	int cudzyslowy = 0;
	for (int i = 0; i < in.size(); i++)
	{
		if (cudzyslowy % 2 == 0)
		{
			if (in.at(i) == '[') kwadratowe++;
			if (in.at(i) == '(') okragle++;
			if (in.at(i) == ']') kwadratowe--;
			if (in.at(i) == ')') okragle--;
		}
		if (in.at(i) == '"') cudzyslowy++;

		if (kwadratowe < 0) return 1;
		if (okragle < 0) return 1;
	}
	if (kwadratowe % 2 == 1) return 1;
	if (okragle % 2 == 1) return 1;
	if (cudzyslowy % 2 == 1) return 1;

	return 0;
}

int CTreeNode::parse1(int n, std::string in)
{
	int i = 0;
	int x = 0;
	std::string nazwa;
	std::string sliczba;
	int iliczba;
	if (!in.at( n ) == '[') return 1;
	if (!in.at( n+1 ) == '"') return 1;
	x = find( n+2, in, 0);
	nazwa = in.substr( n+2, x-(n+2) );
	if (!in.at(x+1) == ',') return 1;
	if (!in.at(x+2) == ' ') return 1;
	i = find(x + 3, in, 1);
	sliczba = in.substr(x + 3, i - (x + 3));
	iliczba = std::stoi(sliczba, nullptr, 0);
}

//stworzyæ weze³ i w parametrze przy tworzeniu przekazaæ resztê do stworzenia dziecka tego wezla jako konstruktor

int CTreeNode::find(int n, std::string in, int x)
{
	if (x == 0)
	{
		for (int i = n; i < in.size(); i++)
		{
			if (in.at(i) == '"') return i;
		}
	}
	if (x == 1)
	{
		for (int i = n; i < in.size(); i++)
		{
			if (in.at(i) == '(') return i;
		}
	}
	return -1;
}


//["Paleta", 1(
/*
1. [
2. cudzyslow
3. nazwa
4. cudzyslow
5. przecinek
6. spacja
7. liczba
8. nawias*/








/*int CTreeNode::parser(int n, std::string in)
{
	int liczniknawiasow=0;
	bool cudzyslow=false;
	bool nowynawias = false;
	bool pocudzyslow = false;
	int mno¿nik = 0;
	std::string nazwa = "";
	int poczatek = 0;
	int koniec = 0;
	CTreeNode node;
	bool pierwszy = true;

	for (int i = 0; i < in.size; i++)
	{
		if (liczniknawiasow == 0)
		{
			if (!in.at(i)=='[')		return 1; // B³¹d
			else
			{
				nowynawias = true;
				liczniknawiasow++;
			}
		}
		if (nowynawias)
		{
			if (!in.at(i) == '"')	return 2; // B³¹d
			else
			{
				cudzyslow = true;
				poczatek = i;
				i++;
				for (; i < in.size; i++)
				{
					if (in.at(i)=='"')
					{
						cudzyslow = false;
						koniec = i;
						nazwa = in.at.substr(poczatek + 1, koniec - poczatek);
						pocudzyslow = true;
					}
				}
				if (cudzyslow)		return 3; //B³¹d
			}
			nowynawias = false;
		}
		if (pocudzyslow)
		{
			if (in.at(i) != ',') return 4; //B³¹d
			else
			{
				poczatek = i + 2;
				for (; i < in.size; i++)
				{
					if (in.at(i) == ',')
					{
						pocudzyslow = false;
						koniec = i;
					}
				}
				if (pocudzyslow) return 5; //B³¹d
			}
		}


		if (liczniknawiasow == 0)	return 4; // B³¹d
	}
}*/