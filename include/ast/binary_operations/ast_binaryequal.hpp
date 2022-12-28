#ifndef ast_binaryequal_hpp
#define ast_binaryequal_hpp

#include <string>
#include <iostream>
#include <ast/ast_binaryop.hpp>

class BinaryEqual
    : public BinaryOp
    
{
    using BinaryOp::BinaryOp;
    void codegen(std::ostream &output, std::string destreg, Context &context) const {
        getLeft()->codegen(output, "$2", context);
        getRight()->codegen(output, "$3", context);
        output << "xor " << destreg << ", $2, " << "$3" << std::endl;
        output << "sltiu " << destreg <<", " << destreg << ", 1" << std::endl; 
    }    
};
#endif