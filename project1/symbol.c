#define SIZE 37

enum TYPE {
    INT,
    FLOAT,
    STRING,
    BOOL
};

typedef struct {
    char *key;
    void *next;
    enum TYPE type;
} Node;

typedef struct {
    void *parent;
    Node **symtable;
} Table;

unsigned int hash(char *str);
Table *create(Table *parent);
int lookup(Table *T, char *name);
int insert(Table *T, char *name);
void dump();

// global variable
Table *TABLE;
Table *NOW = NULL;

unsigned int hash(char *str)
{
	// convert string into unsigned int number
	unsigned int num = 0;
    while(*(str)!=0)
        num += *(str++);
	// hash code
    unsigned int index = num % SIZE;
    return index;
}

Table *create(Table *parent)
{
    Table *t = malloc(sizeof(Table));
    //Set Outer Scope Table;
    t->parent = parent;
    //Allocate Table
    t->symtable = malloc(sizeof(Node) *SIZE);
    //Initialize Table
    memset(t->symtable, 0, sizeof(Node) *SIZE);
    return t;
}

// insert a symbol in a the table
int insert(Table *T, char *name)
{
    unsigned int index = hash(name);
    Node *current = T->symtable[index];
	Node *newNode = malloc(sizeof(Node));
    if(current == NULL) // first node
    {
        newNode->key = malloc(yyleng+1);
        strcpy(newNode->key, name);
        newNode->next = NULL;
        T->symtable[index] = newNode;
        return 1;
    }
    else
    {
        for(; current!=NULL; current=current->next)
        {
            if(strcmp(name, current->key) == 0)
                return 0;
        }
        newNode->key = malloc(yyleng+1);
        strcpy(newNode->key, name);
        newNode->next = current;
        T->symtable[index] = newNode;

        return 1;
    }
}

// search for the symbol in the table
int lookup(Table *T, char *name)
{
    unsigned int index = hash(name);
    for(Node *it=T->symtable[index]; it!=NULL; it=it->next)
    {
        if(strcmp(name, it->key) == 0)
            return 1;
    }
    return 0;
}


// print all symbol in the table
void dump()
{
    printf("\nSymbol Table:\n");
    for(int i = 0; i < SIZE; i++)
    {
        for(Node *current = TABLE->symtable[i]; current!=NULL; current=current->next)
        {
            printf("%s\n", current->key);  
        }
    }
}

