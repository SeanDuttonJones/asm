#ifndef TYPE_H
#define TYPE_H

#include <typeindex>
#include <map>

enum class Type {
    BOOL,
    CHAR,
    INT,
    UNSIGNED_INT,
    FLOAT,
    DOUBLE,
    STRING,
    NONE
};

class TypeTools {
    private:
        static std::map<std::type_index, Type> typeMap;
        static std::map<Type, std::string> typeStringMap;
    
    public:
        static Type getType(std::type_index);
        static std::string toString(Type);

};

#endif