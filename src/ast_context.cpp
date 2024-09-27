#include "ast_context.hpp"

SymbolTableNode::~SymbolTableNode(){

    for(auto it : children ){
        delete it;
    }

    for(auto it = table.begin(); it!=table.end(); ++it){
        delete it->second;
    }

    table.clear();

}

Context::~Context(){
    delete root_;
}

void Context::NewScope(std::string label){
    SymbolTableNode *table = new SymbolTableNode(label, current_scope_, current_scope_->scope);
    current_scope_->children.push_back(table);
    current_scope_ = table;
}

void Context::ExitScope(){
    current_scope_ = current_scope_->parent;
}

void Context::Insert(std::string label, Symbol* symbol){
    current_scope_->table.insert_or_assign(label, symbol);
}

SymbolTableNode* Context::GetCurrentScope(){
    return current_scope_;
}

std::string Context::GetNextReg(){
    if (!available_registers_.empty()) {
        std::string reg = available_registers_.back();
        available_registers_.pop_back();
        register_stack_.push(reg);
        return reg;
    } else {
        throw std::runtime_error("No more registers available");
    }

}

void Context::FreeReg(std::string reg){
    if (!register_stack_.empty()) {
            std::string reg = register_stack_.top();
            register_stack_.pop();
            available_registers_.push_back(reg);
        }
    else{
        throw std::runtime_error("No registers in use currently");
    }
}
