#ifndef AST_BINARY_OPERATOR_HPP
#define AST_BINARY_OPERATOR_HPP

#include "ast_node.hpp"
#include<string>

class BinaryOperator : public Node{
    private:
        Node* left_;
        Node* right_;
        char op_;

    public:

    BinaryOperator(Node* ileft, Node* iright, char iop): left_(ileft), right_(iright), op_(iop){}
    ~BinaryOperator(){
        delete left_;
        delete right_;
    }

    Node* GetLeft() const
    { return left_; }

    Node* GetRight() const
    { return right_; }

    void Print(std::ostream &stream) const
    {
        stream<<"( ";
        left_->Print(stream);
        stream<<" ";
        stream<<op_;
        stream<<" ";
        right_->Print(stream);
        stream<<" )";
    }

    virtual void EmitRISC(std::ostream &stream, Context &context) const override = 0;

};

class AddOperator : public BinaryOperator{

    public:

    AddOperator(Node* _left, Node* _right): BinaryOperator(_left, _right, '+'){}

    void EmitRISC(std::ostream &stream, Context &context) const override;

};

class SubOperator : public BinaryOperator{

    public:

    SubOperator(Node* _left, Node* _right): BinaryOperator(_left, _right, '-'){}

    void EmitRISC(std::ostream &stream, Context &context) const override;

};

class MulOperator : public BinaryOperator{

    public:

    MulOperator(Node* _left, Node* _right): BinaryOperator(_left, _right, '*'){}

    void EmitRISC(std::ostream &stream, Context &context) const override;

};

class DivOperator : public BinaryOperator{

    public:

    DivOperator(Node* _left, Node* _right): BinaryOperator(_left, _right, '/'){}

    void EmitRISC(std::ostream &stream, Context &context) const override;

};

/* class ModOperator : public BinaryOperator{

    public:

    ModOperator(Node* _left, Node* _right): BinaryOperator(_left, _right, '%'){}

    void EmitRISC(std::ostream &stream, Context &context) const override;

}; */

#endif
