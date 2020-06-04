#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string IDtype2str(int type);
string IDscope2str(int scope);

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

typedef union
{
	int v_int;
	float v_float;
	char v_char;
	string v_str;
	bool v_bool;
	int v_none;
} IDvalue;

typedef struct IDinfo
{
	string id;
	int type = 0;
	int scope = 0;
	IDvalue *value = NULL;

	int arr_size = 0;
	int arr_type = 0;
	vector<IDvalue*> arr_value;

	int func_type = 0;
	map<string, IDinfo*> argu_value;
	IDvalue *return_value = NULL;
} IDinfo;

class Symbol
{
public:
	Symbol();

	map<string, IDinfo*> idmap;
	IDinfo *search(string id);

	int insert(string id, int type, int scope);
	int insert_init(string id, int type, int scope, IDvalue *value);
	int insert_arr(string id, int type, int scope, int value, int size);
	int insert_funcArgs(string id, map<string, IDinfo*> args);
};

class SymbolTables
{
public:
	SymbolTables();

	int size = 0;
	vector<Symbol> list;

	IDinfo *lookup(string id);
	void push_table();
	int pop_table();
	void dump();
};


