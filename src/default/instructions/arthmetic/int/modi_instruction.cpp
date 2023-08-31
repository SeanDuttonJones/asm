#include "operation.h"
#include "instructions.h"

#include <iostream>
#include <any>

ModIInstruction::ModIInstruction(Opcode opcode, std::any operand)
    : Operation(opcode, operand)
{}

void ModIInstruction::execute(IContext *context) {
    // std::cout << "PushI: executing" << std::endl;
    IStackAccess *stackAccessor = context->getStackAccess();
    
    std::any operand1 = stackAccessor->top();
    stackAccessor->pop();
    std::any operand2 = stackAccessor->top();
    stackAccessor->pop();
    
    if(TypeTools::getType(std::type_index(operand1.type())) != Type::INT 
        || TypeTools::getType(std::type_index(operand2.type())) != Type::INT) {
        
        std::cerr << "Invalid operands for instruction ModI" << std::endl;
    }

    int a = std::any_cast<int>(operand2);
    int b = std::any_cast<int>(operand1);

    int rem = a % b;

    stackAccessor->push(rem);
}