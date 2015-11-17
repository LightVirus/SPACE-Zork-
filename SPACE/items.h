#pragma once
#include <string>
#include <vector>

using namespace std;

class items
{
public:
	items();
	~items();
	
	string name = "";
	string desc = "";
	string placedesc = "";
	string objusestr = "";
	
	bool container;
	bool canbestored;
	vector<items> contitems;


	void PutItemOnItem(items &itemtoput);
	void SetAtt(string n, string d, bool container, bool canbs, string obju);
};

