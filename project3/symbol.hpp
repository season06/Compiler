#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

/* enum (int) to string */
string IDtype2str(int type)
{
	switch(type)
	{
		case 0:
			return "";
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
			return "";
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

/* ID infomation */
enum IDtype
{
	t_unknown = 0,
	t_int,
	t_float,
	t_char,
	t_string,
	t_bool
};

enum IDscope
{
	s_unknown = 0,
	s_object,
	s_function,
	s_variable,
	s_const,
	s_array,
};

typedef struct IDvalue
{
	int 	v_int;
	float 	v_float;
	char 	v_char;
	string 	v_string;
	bool 	v_bool;
} IDvalue;

class IDinfo
{
public:
	string id;
	IDvalue value;
	int type;
	int scope;
	// init or not
	bool init;

	bool global;
	int stackIndex;

	// for array
	vector<IDinfo> arr_value;
	int arr_size;

	// for function
	int return_type = 0;
	vector<IDinfo> args_value;
	IDinfo *return_value;

	// constructor
	IDinfo()
	{
		id = "";
		type = 0;
		scope = 0;
		init = false;
	}
	IDinfo(const IDinfo &f)
	{
		id = f.id;
		type = f.type;
		scope = f.scope;
		init = f.init;
		setValue(f.value);
	}
	IDinfo(int _type, int _scope, bool _init)
	{
		type = _type;
		scope = _scope;
		init = _init;
	}
	void setValue(const IDvalue &v)
	{
		value.v_int = v.v_int;
		value.v_float = v.v_float;
		value.v_char = v.v_char;
		value.v_string = v.v_string;
		value.v_bool = v.v_bool;
	}
};

IDinfo *set_int(int val)
{
	IDinfo *f = new IDinfo(t_int, s_variable, true);
	f->value.v_int = val;
	return f;
}
IDinfo *set_float(float val)
{
	IDinfo *f = new IDinfo(t_float, s_variable, true);
	f->value.v_float = val;
	return f;
}
IDinfo *set_char(char val)
{
	IDinfo *f = new IDinfo(t_char, s_variable, true);
	f->value.v_char = val;
	return f;
}
IDinfo *set_string(string val)
{
	IDinfo *f = new IDinfo(t_string, s_variable, true);
	f->value.v_string = val;
	return f;
}
IDinfo *set_bool(bool val)
{
	IDinfo *f = new IDinfo(t_bool, s_variable, true);
	f->value.v_bool = val;
	return f;
}


/* A Symbol Table */
class Symbol
{
public:
	map<string, IDinfo> idmap;
	vector<string> id_name;		// map has no order, user vector instead
	Symbol() {}
	int insert(string id, const IDinfo &f, bool global)
	{
		if(isexist(id))
			return -1;
		else
		{
			id_name.push_back(id);
			idmap[id].id = id;
			idmap[id].type = f.type;
			idmap[id].scope = f.scope;
			idmap[id].init = f.init;
			idmap[id].value = f.value;
			idmap[id].global = global;
			return 1;
		}
	}
	void insert_arr(string id, int type, int size)
	{
		idmap[id].arr_size = size;
		idmap[id].arr_value = vector<IDinfo>(size);
		for(auto &i : idmap[id].arr_value)
		{
			i.type = type;
			i.scope = s_variable;
		}
	}
	int insert_args(string now_func, string id, const IDinfo f)
	{
		for(int i=0;i<idmap[now_func].args_value.size();i++)
			if(idmap[now_func].args_value[i].id == id)
				return -1;
		IDinfo tmp;
		tmp.id = id;
		tmp.type = f.type;
		tmp.scope = f.scope;
		tmp.init = f.init;
		tmp.value = f.value;
		idmap[now_func].args_value.push_back(tmp);
		return 1;
	}
	int isexist(string id)
	{
		if(idmap.count(id))
			return 1;
		return 0;
	}

	IDinfo* lookup(string id)
	{
		if(isexist(id))
			return &idmap[id];
		return NULL;
	}
	void dump()
	{
		cout <<setw(10)<<"ID"<<setw(10)<<"TYPE"<<setw(10)<<"SCOPE"<<setw(20)<<"INFO\n";
		for(int n=0; n<id_name.size(); n++)
		{
			string output;
			IDinfo f = idmap[id_name[n]];
			output = f.id;
			cout <<setw(10) << output << setw(10);
			output = IDtype2str(f.type);
			cout << output << setw(10);
			output = IDscope2str(f.scope);
			cout << output << setw(20);
			output = "";
			if(f.scope == s_variable || f.scope == s_const)
			{
				output = "value = ";
				if(f.type == t_int)
					output += to_string(f.value.v_int);
				if(f.type == t_float)
					output += to_string(f.value.v_float);
				if(f.type == t_char)
					output += f.value.v_char;
				if(f.type == t_string)
					output += f.value.v_int;
				if(f.type == t_bool)
					output += to_string(f.value.v_bool);
			}
			else if(f.scope == s_array)
			{
				output = "size = ";
				output += to_string(f.arr_size);
			}
			else if(f.scope == s_function)
			{
				output = "  argument = { ";
				for(int i=0; i<f.args_value.size(); i++)
				{
					output += IDtype2str(f.args_value[i].type);
					output += " ,";
				}
				output += " }";
			}
			cout << output << "\n";
		}
		cout << "\n";
	}
};

/* All Symbol Tables */
class SymbolTables
{
public:
	vector<Symbol> list;
	int top;
	SymbolTables()
	{
		top = -1;
	}
	bool isGlobal()
	{
		if(top == 0)
			return true;
		return false;
	}
	int insert(string id, const IDinfo &c)
	{
		return list[top].insert(id, c, isGlobal());
	}
	void push_table()
	{
		list.push_back(Symbol());
		top++;
	}
	int pop_table()
	{
		list.pop_back();
		top--;
	}
	IDinfo* lookup(string id)
	{
		for(int i=top; i>=0; i--)
		{
			if(list[i].isexist(id))
				return list[i].lookup(id);
		}
		return NULL;
	}
	void dump()
	{
		if(top >= 0)
		{
			cout << "=================Dump SymbolTable=================\n";
			cout << "            =======Layer: "<< top << " ======\n";
			list[top].dump();
		}
	}
};