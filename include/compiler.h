#ifndef BELISH_COMPILER_H
#define BELISH_COMPILER_H

#include <map>
#include <list>
#include "ast.h"
using std::map;

#define MBDKV "\x01"
#define SBDKV "\x01"

namespace Belish {
    enum OPID {
        PUSH_NUM = 0, PUSH_STR, PUSH_OBJ, PUSH_NULL, PUSH_UND, REFER, DEB, PUSH, ADD, SUB, MUL, DIV, MOD,
        EQ, NEQ, LEQ, MEQ, LESS, MORE,
        MAND, MOR, MXOR, MNOT,
        LAND, LOR, LNOT, POW,
        MOV, POP, POPC, JT, JF, JMP,
        SAV, BAC, SL, SR
    };
    class Compiler {
    public:
        Compiler() : filename("untitled.bel") { }
        Compiler(const string& fn) : filename(fn) { }
        Compiler(const string& fn, const string& s) : script(s), ast(s), filename(fn) { }
        bool compile(string&);
        bool compile_(string&, bool = false, std::list<UL>* = nullptr, std::list<UL>* = nullptr);
    private:
        UL stkOffset = 0;
        string filename;
        string script;
        AST ast;
        map<string, UL> sym;
        std::list<string> newVars;
        bool independent = true;
    };
}

#endif //BELISH_COMPILER_H
