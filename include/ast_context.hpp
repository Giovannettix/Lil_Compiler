#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

// An object of class Context is passed between AST nodes during compilation.
// This can be used to pass around information about what's currently being
// compiled (e.g. function scope and variable names).

//will be more helpful to figure out the functionality of Context when you encounter situations in the parser

struct Symbol{

    std::string type;
    bool is_initialized;
    bool is_function;
    int size;
    //other metadata

    Symbol(std::string itype): type(itype){};

};

struct SymbolTableNode{

    std::string label;
    int scope;
    std::unordered_map<std::string, Symbol*> table;

    SymbolTableNode* parent;
    std::vector<SymbolTableNode*> children;

    SymbolTableNode(): label("global"), parent(nullptr), scope(0){

    };

    SymbolTableNode(std::string ilabel, SymbolTableNode* parent, int currentScope): parent(parent), scope(currentScope+1), label(ilabel){

    };

    virtual ~SymbolTableNode();

};

class Context
{

    private:
        SymbolTableNode *root_;
        SymbolTableNode *current_scope_;

        std::vector<std::string> available_registers_;
        std::stack<std::string> register_stack_;

    public:

    Context(): root_(new SymbolTableNode), current_scope_(root_){
       available_registers_ = {"a1", "a2", "a3"};
    };
    ~Context();
    void NewScope(std::string label);
    void ExitScope();
    void Insert(std::string label, Symbol* symbol);
    SymbolTableNode* GetCurrentScope();

    //register management
    std::string GetNextReg();
    void FreeReg(std::string reg);

    //Symbol *Lookup(std::string label);
    //void ListCurrentScope(std::ostream& stream);
    //void ClearCurrentScope();


};

#endif
