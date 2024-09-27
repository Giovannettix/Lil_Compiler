#include "ast_binary_operator.hpp"

void AddOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftReg = context.GetNextReg();
    std::string rightReg = context.GetNextReg();

    GetLeft()->EmitRISC(stream, context);
    stream << "mv " << leftReg << ", a0" << std::endl;
    GetRight()->EmitRISC(stream, context);
    stream << "mv " << rightReg << ", a0" << std::endl;

    stream << "add " << "a0, " << leftReg << ", " << rightReg << std::endl;

}

void SubOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftReg = context.GetNextReg();
    std::string rightReg = context.GetNextReg();

    GetLeft()->EmitRISC(stream, context);
    stream << "mv " << leftReg << ", a0" << std::endl;
    GetRight()->EmitRISC(stream, context);
    stream << "mv " << rightReg << ", a0" << std::endl;

    stream << "sub " << "a0, " << leftReg << ", " << rightReg << std::endl;

}

void MulOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftReg = context.GetNextReg();
    std::string rightReg = context.GetNextReg();

    GetLeft()->EmitRISC(stream, context);
    stream << "mv " << leftReg << ", a0" << std::endl;
    GetRight()->EmitRISC(stream, context);
    stream << "mv " << rightReg << ", a0" << std::endl;

    stream << "mul " << "a0, " << leftReg << ", " << rightReg << std::endl;

}

void DivOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftReg = context.GetNextReg();
    std::string rightReg = context.GetNextReg();

    GetLeft()->EmitRISC(stream, context);
    stream << "mv " << leftReg << ", a0" << std::endl;
    GetRight()->EmitRISC(stream, context);
    stream << "mv " << rightReg << ", a0" << std::endl;

    stream << "div " << "a0, " << leftReg << ", " << rightReg << std::endl;

}


