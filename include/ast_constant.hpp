#ifndef AST_CONSTANT_HPP
#define AST_CONSTANT_HPP

#include "ast_node.hpp"
#include<string>
#include<variant>

//using sLiteral = std::variant<std::string, std::wstring>;

class IntConstant : public Node
{
private:
    int value_;

public:
    IntConstant(int value) : value_(value) {}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
};

class FloatConstant : public Node
{
private:
    float value_;
public:
    FloatConstant(float value): value_(value) {}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;

};

class StringLiteral : public Node
{
private:
    //sLiteral value_;
    std::string *value_;
    std::wstring *wvalue_;

public:

    // Constructor + Destructor
    StringLiteral(std::string *value) : value_(value), wvalue_(nullptr) {}
    StringLiteral(std::wstring *wvalue) : value_(nullptr), wvalue_(wvalue) {}

    ~StringLiteral() {
        delete value_;
        delete wvalue_;
    }

    //StringLiteral(const std::string &value) : value_(value) {}
    //StringLiteral(const std::wstring &value) : value_(value) {}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;

};

#endif
