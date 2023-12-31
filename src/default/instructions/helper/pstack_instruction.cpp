#include "operation.h"
#include "instructions.h"

#include <iostream>
#include <any>

PStackInstruction::PStackInstruction(Opcode opcode, std::any operand) 
    : Operation(opcode, operand)
{}

void PStackInstruction::execute(IContext *context) {
    IStackAccess *stackAccessor = context->getStackAccess();
    
    uint64_t stackSize = stackAccessor->size();

    std::any elements[stackSize];
    for(uint64_t i = 0; i < stackSize; i++) {
        elements[i] = stackAccessor->top();
        stackAccessor->pop();
    }

    printf("[ ");
    for(uint64_t i = stackSize; i--;) {
        stackAccessor->push(elements[i]);
        printf("%s", anyToString(elements[i]).c_str());
        if(i > 0) {
            printf(" ");
        }
    }
    printf(" ]\n");
}

std::string PStackInstruction::anyToString(std::any value) {
    std::string valueStr = "";

    switch (TypeTools::getType(std::type_index(value.type()))) {
        case Type::BOOL:
            valueStr = std::to_string(std::any_cast<bool>(value));
            break;
        case Type::CHAR:
            valueStr = std::to_string(std::any_cast<char>(value));
            break;
        case Type::INT:
            valueStr = std::to_string(std::any_cast<int>(value));
            break;
        case Type::UNSIGNED_INT:
            valueStr = std::to_string(std::any_cast<unsigned int>(value));
            break;
        case Type::FLOAT:
            valueStr = std::to_string(std::any_cast<float>(value));
            break;
        case Type::DOUBLE:
            valueStr = std::to_string(std::any_cast<double>(value));
            break;
        case Type::STRING:
            valueStr = std::any_cast<std::string>(value);
            break;
        default:
            valueStr = "None";
            break;
    }

    return valueStr;
}