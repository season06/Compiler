#include "symbol.h"

string IDtype2str(int type)
{
	switch(type)
	{
		case 0:
			return "unknown";
		case 1:
			return "int";
		case 2:
			return "float";
		case 3:
			return "char";
		case 4:
			return "string";
		case 5:
			return "bool";
	}
}

string IDscope2str(int scope)
{
	switch(scope)
	{
		case 0:
			return "unknown";
		case 1:
			return "object";
		case 2:
			return "function";
		case 3:
			return "variable";
		case 4:
			return "const";
		case 5:
			return "array";
	}
}

Symbol::Symbol()
{
	idmap.clear();
}
IDinfo *Symbol::search(string id)
{
	if(idmap.find(id) != idmap.end())
		return idmap[id];
	return NULL;
}
int Symbol::insert(string id, int type, int scope)
{
	if(idmap.find(id) != idmap.end())
		return -1;

	IDinfo *tmp;
	tmp->id = id;
	tmp->type = type;
	tmp->scope = scope;

	idmap[id] = tmp;
}
int Symbol::insert_init(string id, int type, int scope, IDvalue *value)
{
	if(idmap.find(id) != idmap.end())
		return -1;

	IDinfo *tmp;
	tmp->id = id;
	tmp->type = type;
	tmp->scope = scope;
	tmp->value = value;

	idmap[id] = tmp;
}
int Symbol::insert_arr(string id, int type, int scope, int value, int size)
{
	if(idmap.find(id) != idmap.end())
		return -1;
	IDinfo *tmp;
	tmp->id = id;
	tmp->type = type;
	tmp->scope = scope;

	idmap[id] = tmp;
}

int Symbol::insert_funcArgs(string func_id, map<string, IDinfo*> args)
{
	if(idmap.find(func_id) != idmap.end())
		return -1;
	idmap[func_id]->argu_value = args;
}



SymbolTables::SymbolTables()
{
	list.push_back(Symbol());
	size++;
}

IDinfo *SymbolTables::lookup(string id)
{
	for(int i = size; i>=0; i--)
	{
		IDinfo *temp = list[i].search(id);
		if(temp == NULL)
			return NULL;
		return temp;
	}
}

void SymbolTables::push_table()
{
	// create new symbol table
	list.push_back(Symbol());
	size++;
}
int SymbolTables::pop_table()
{
	list.pop_back();
	size--;
}
void SymbolTables::dump()
{
	cout << "=============Dump SymbolTable=============\n";
	for(int i=0; i<list.size(); i++)
	{
		map<string, IDinfo*>::iterator it;
		for(it = list[i].idmap.begin(); it!=list[i].idmap.end(); it++)
		{
			cout << "ID = " << it->first;
			cout << ", scope = " << IDscope2str(it->second->scope);
			cout << "\n";
		}
	}
}









