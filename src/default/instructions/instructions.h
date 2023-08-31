#ifndef INSTRUCTIONS_CLASS_H
#define INSTRUCTIONS_CLASS_H

#include "operation.h"

class PushIInstruction : public Operation {
    public:
        PushIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PushFInstruction : public Operation {
    public:
        PushFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class AddIInstruction : public Operation {
    public:
        AddIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class SubIInstruction : public Operation {
    public:
        SubIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class NegIInstruction : public Operation {
    public:
        NegIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class MulIInstruction : public Operation {
    public:
        MulIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class DivIInstruction : public Operation {
    public:
        DivIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class ModIInstruction : public Operation {
    public:
        ModIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class AddFInstruction : public Operation {
    public:
        AddFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class SubFInstruction : public Operation {
    public:
        SubFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class NegFInstruction : public Operation {
    public:
        NegFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class MulFInstruction : public Operation {
    public:
        MulFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class DivFInstruction : public Operation {
    public:
        DivFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PStackInstruction : public Operation {
    private:
        std::string anyToString(std::any value);

    public:
        PStackInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class PMemInstruction : public Operation {
    public:
        PMemInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class StoreCInstruction : public Operation {
    public:
        StoreCInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class StoreIInstruction : public Operation {
    public:
        StoreIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class StoreFInstruction : public Operation {
    public:
        StoreFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class LoadCInstruction : public Operation {
    public:
        LoadCInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class LoadIInstruction : public Operation {
    public:
        LoadIInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

class LoadFInstruction : public Operation {
    public:
        LoadFInstruction(Opcode opcode, std::any operand);
        void execute(IContext *context);
};

#endif