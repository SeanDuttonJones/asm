#ifndef INSTRUCTIONS_CLASS_H
#define INSTRUCTIONS_CLASS_H

#include "operation.hpp"

class PushIInstruction : public Operation {
    public:
        PushIInstruction(IContext *context, any value);
        void install();
        void execute();
};

#endif