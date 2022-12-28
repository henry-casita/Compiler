#ifndef ast_assignmentor_hpp
#define ast_assignmentor_hpp

#include <string>
#include <iostream>
#include <ast/ast_assignmentexpression.hpp>

class AssignmentOr
    : public AssignmentExpression
{
    using AssignmentExpression::AssignmentExpression;
    void codegen(std::ostream &output, std::string destreg, Context &context) const {
        getReg()->codegen(output, "$2", context);
        getVariable()->codegen(output, "$3", context);
        output << "or " << destreg  << ", $2, " << "$3" << std::endl;
        std::string name = getReg()->getIdentifier();
        if (context.Localexists(name)){
                //std::cout << "thinks the variable exists" << std::endl;
                int offset = context.LocalgetOffset(name);
                output << "sw " << destreg << "," << offset << "($fp)" << std::endl;
            }
            else{
                //std::cout << "variable does not exist" << std::endl;
                int offset = context.LocalgetMapSize()*4+8;
                context.LocalinsertVariable(name, offset);
                output << "sw $2, " << destreg << ", " <<  "($fp)" << std::endl;
            }
    }
};
#endif
