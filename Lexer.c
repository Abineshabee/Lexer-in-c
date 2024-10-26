#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 150

enum TokenType {
    // Basic types
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    // Operators
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_MODULO,
    TOKEN_ASSIGN,
    TOKEN_EQUAL,
    TOKEN_NOT_EQUAL,
    TOKEN_LESS_THAN,
    TOKEN_GREATER_THAN,
    TOKEN_LESS_EQUAL,
    TOKEN_GREATER_EQUAL,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_NOT,
    TOKEN_BIT_AND,
    TOKEN_BIT_OR,
    TOKEN_BIT_XOR,
    TOKEN_BIT_NOT,
    TOKEN_LEFT_SHIFT,
    TOKEN_RIGHT_SHIFT,
    
    // Delimiters
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_BRACE,
    TOKEN_RIGHT_BRACE,
    TOKEN_LEFT_BRACKET,
    TOKEN_RIGHT_BRACKET,
    TOKEN_SEMICOLON,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_DOT,
    TOKEN_ARROW,
    
    // Keywords
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_FOR,
    TOKEN_DO,
    TOKEN_SWITCH,
    TOKEN_CASE,
    TOKEN_DEFAULT,
    TOKEN_BREAK,
    TOKEN_CONTINUE,
    TOKEN_RETURN,
    TOKEN_GOTO,
    TOKEN_TYPEDEF,
    TOKEN_STRUCT,
    TOKEN_UNION,
    TOKEN_ENUM,
    TOKEN_SIZEOF,
    TOKEN_STATIC,
    TOKEN_EXTERN,
    TOKEN_AUTO,
    TOKEN_REGISTER,
    TOKEN_CONST,
    TOKEN_VOLATILE,
    TOKEN_INLINE,
    
    // Types
    TOKEN_VOID,
    TOKEN_CHAR,
    TOKEN_SHORT,
    TOKEN_INT,
    TOKEN_LONG,
    TOKEN_FLOAT,
    TOKEN_DOUBLE,
    TOKEN_SIGNED,
    TOKEN_UNSIGNED,
    
    // Preprocessor
    TOKEN_HASH,
    TOKEN_ITOKEN_ABS,
    TOKEN_CEIL,
    TOKEN_FLOOR,
    TOKEN_ROUND,
    TOKEN_INCLUDE,
    TOKEN_DEFINE,
    TOKEN_UNDEF,
    TOKEN_IFDEF,
    TOKEN_IFNDEF,
    TOKEN_ENDIF,
    TOKEN_PRAGMA,
    
    // C++ specific
    TOKEN_CLASS,
    TOKEN_PRIVATE,
    TOKEN_PROTECTED,
    TOKEN_PUBLIC,
    TOKEN_VIRTUAL,
    TOKEN_FRIEND,
    TOKEN_OPERATOR,
    TOKEN_NEW,
    TOKEN_DELETE,
    TOKEN_THIS,
    TOKEN_TEMPLATE,
    TOKEN_NAMESPACE,
    TOKEN_USING,
    TOKEN_TRY,
    TOKEN_CATCH,
    TOKEN_THROW,
    TOKEN_EXCEPT,
    
    // Additional types
    TOKEN_BOOL,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL,
    
    // Additional keywords
    TOKEN_CONST_CAST,
    TOKEN_DYNAMIC_CAST,
    TOKEN_REINTERPRET_CAST,
    TOKEN_STATIC_CAST,
    TOKEN_EXPLICIT,
    TOKEN_EXPORT,
    TOKEN_MUTABLE,
    TOKEN_TYPENAME,
    
    // Additional operators
    TOKEN_SCOPE_RESOLUTION,
    TOKEN_PLUS_PLUS,
    TOKEN_MINUS_MINUS,
    TOKEN_PLUS_EQUAL,
    TOKEN_MINUS_EQUAL,
    TOKEN_MULTIPLY_EQUAL,
    TOKEN_DIVIDE_EQUAL,
    TOKEN_MODULO_EQUAL,
    TOKEN_AND_EQUAL,
    TOKEN_OR_EQUAL,
    TOKEN_XOR_EQUAL,
    TOKEN_LEFT_SHIFT_EQUAL,
    TOKEN_RIGHT_SHIFT_EQUAL,
    
    // Special tokens
    TOKEN_ELLIPSIS,
    TOKEN_STRING_LITERAL,
    TOKEN_CHAR_LITERAL,
    
    // Built-In-Function
    TOKEN_BFUNCTIONS,
    // I/O
    TOKEN_PRINT,
    TOKEN_INPUT,
    
    //STRING
    TOKEN_STR,
    TOKEN_UPPER,
    TOKEN_LOWER,
    TOKEN_CAPITALIZE,
    TOKEN_COUNT,
    TOKEN_FIND,
    TOKEN_INDEX,
    TOKEN_ISALNUM,
    TOKEN_ISALPHA,
    TOKEN_ISDIGIT,
    TOKEN_ISNUMERIC,
    TOKEN_ISSPACE,
    TOKEN_ISTITLE,
    TOKEN_ISUPPER,
    TOKEN_ISLOWER,
    TOKEN_REPLACE,
    TOKEN_TITLE,
    TOKEN_POP,
    TOKEN_REVERSE,
    TOKEN_LEN,
    
    TOKEN_ABS,
    
    // Type
    TOKEN_TYPE,
    
    // END LINE , TAB
    TOKEN_ENDL,
    TOKEN_TAB,
    
    TOKEN_IN,
    TOKEN_NOTIN,
    TOKEN_IS,
    TOKEN_ISNOT,
    TOKEN_AS,
    TOKEN_PASS,
    TOKEN_ELIF,
    TOKEN_FROM,
    TOKEN_IMPORT,
    
    
    // End token
    TOKEN_END
};

struct Token {
    enum TokenType type;
    char value[MAX_TOKEN_LEN];
};

const char* token_type_to_string(enum TokenType type) {
    switch (type) {
        case TOKEN_IDENTIFIER: return "IDENTIFIER";
        case TOKEN_NUMBER: return "NUMBER";
        case TOKEN_PLUS: return "PLUS";
        case TOKEN_MINUS: return "MINUS";
        case TOKEN_MULTIPLY: return "MULTIPLY";
        case TOKEN_DIVIDE: return "DIVIDE";
        case TOKEN_MODULO: return "MODULO";
        case TOKEN_ASSIGN: return "ASSIGN";
        case TOKEN_EQUAL: return "EQUAL";
        case TOKEN_NOT_EQUAL: return "NOT_EQUAL";
        case TOKEN_LESS_THAN: return "LESS_THAN";
        case TOKEN_GREATER_THAN: return "GREATER_THAN";
        case TOKEN_LESS_EQUAL: return "LESS_EQUAL";
        case TOKEN_GREATER_EQUAL: return "GREATER_EQUAL";
        case TOKEN_AND: return "AND";
        case TOKEN_OR: return "OR";
        case TOKEN_NOT: return "NOT";
        case TOKEN_BIT_AND: return "BIT_AND";
        case TOKEN_BIT_OR: return "BIT_OR";
        case TOKEN_BIT_XOR: return "BIT_XOR";
        case TOKEN_BIT_NOT: return "BIT_NOT";
        case TOKEN_LEFT_SHIFT: return "LEFT_SHIFT";
        case TOKEN_RIGHT_SHIFT: return "RIGHT_SHIFT";
        case TOKEN_LEFT_PAREN: return "LEFT_PAREN";
        case TOKEN_RIGHT_PAREN: return "RIGHT_PAREN";
        case TOKEN_LEFT_BRACE: return "LEFT_BRACE";
        case TOKEN_RIGHT_BRACE: return "RIGHT_BRACE";
        case TOKEN_LEFT_BRACKET: return "LEFT_BRACKET";
        case TOKEN_RIGHT_BRACKET: return "RIGHT_BRACKET";
        case TOKEN_SEMICOLON: return "SEMICOLON";
        case TOKEN_COLON: return "COLON";
        case TOKEN_COMMA: return "COMMA";
        case TOKEN_DOT: return "DOT";
        case TOKEN_ARROW: return "ARROW";
        case TOKEN_IF: return "IF";
        case TOKEN_ELSE: return "ELSE";
        case TOKEN_WHILE: return "WHILE";
        case TOKEN_FOR: return "FOR";
        case TOKEN_DO: return "DO";
        case TOKEN_SWITCH: return "SWITCH";
        case TOKEN_CASE: return "CASE";
        case TOKEN_DEFAULT: return "DEFAULT";
        case TOKEN_BREAK: return "BREAK";
        case TOKEN_CONTINUE: return "CONTINUE";
        case TOKEN_RETURN: return "RETURN";
        case TOKEN_GOTO: return "GOTO";
        case TOKEN_TYPEDEF: return "TYPEDEF";
        case TOKEN_STRUCT: return "STRUCT";
        case TOKEN_UNION: return "UNION";
        case TOKEN_ENUM: return "ENUM";
        case TOKEN_SIZEOF: return "SIZEOF";
        case TOKEN_STATIC: return "STATIC";
        case TOKEN_EXTERN: return "EXTERN";
        case TOKEN_AUTO: return "AUTO";
        case TOKEN_REGISTER: return "REGISTER";
        case TOKEN_CONST: return "CONST";
        case TOKEN_VOLATILE: return "VOLATILE";
        case TOKEN_INLINE: return "INLINE";
        case TOKEN_VOID: return "VOID";
        case TOKEN_CHAR: return "CHAR";
        case TOKEN_SHORT: return "SHORT";
        case TOKEN_INT: return "INT";
        case TOKEN_LONG: return "LONG";
        case TOKEN_FLOAT: return "FLOAT";
        case TOKEN_DOUBLE: return "DOUBLE";
        case TOKEN_SIGNED: return "SIGNED";
        case TOKEN_UNSIGNED: return "UNSIGNED";
        case TOKEN_HASH: return "HASH";
        case TOKEN_INCLUDE: return "INCLUDE";
        case TOKEN_DEFINE: return "DEFINE";
        case TOKEN_UNDEF: return "UNDEF";
        case TOKEN_IFDEF: return "IFDEF";
        case TOKEN_IFNDEF: return "IFNDEF";
        case TOKEN_ENDIF: return "ENDIF";
        case TOKEN_PRAGMA: return "PRAGMA";
        case TOKEN_CLASS: return "CLASS";
        case TOKEN_PRIVATE: return "PRIVATE";
        case TOKEN_PROTECTED: return "PROTECTED";
        case TOKEN_PUBLIC: return "PUBLIC";
        case TOKEN_VIRTUAL: return "VIRTUAL";
        case TOKEN_FRIEND: return "FRIEND";
        case TOKEN_OPERATOR: return "OPERATOR";
        case TOKEN_NEW: return "NEW";
        case TOKEN_DELETE: return "DELETE";
        case TOKEN_THIS: return "THIS";
        case TOKEN_TEMPLATE: return "TEMPLATE";
        case TOKEN_NAMESPACE: return "NAMESPACE";
        case TOKEN_USING: return "USING";
        case TOKEN_TRY: return "TRY";
        case TOKEN_CATCH: return "CATCH";
        case TOKEN_THROW: return "THROW";
        case TOKEN_BOOL: return "BOOL";
        case TOKEN_TRUE: return "TRUE";
        case TOKEN_FALSE: return "FALSE";
        case TOKEN_NULL: return "NULL";
        case TOKEN_CONST_CAST: return "CONST_CAST";
        case TOKEN_DYNAMIC_CAST: return "DYNAMIC_CAST";
        case TOKEN_REINTERPRET_CAST: return "REINTERPRET_CAST";
        case TOKEN_STATIC_CAST: return "STATIC_CAST";
        case TOKEN_EXPLICIT: return "EXPLICIT";
        case TOKEN_EXPORT: return "EXPORT";
        case TOKEN_MUTABLE: return "MUTABLE";
        case TOKEN_TYPENAME: return "TYPENAME";
        case TOKEN_SCOPE_RESOLUTION: return "SCOPE_RESOLUTION";
        case TOKEN_PLUS_PLUS: return "PLUS_PLUS";
        case TOKEN_MINUS_MINUS: return "MINUS_MINUS";
        case TOKEN_PLUS_EQUAL: return "PLUS_EQUAL";
        case TOKEN_MINUS_EQUAL: return "MINUS_EQUAL";
        case TOKEN_MULTIPLY_EQUAL: return "MULTIPLY_EQUAL";
        case TOKEN_DIVIDE_EQUAL: return "DIVIDE_EQUAL";
        case TOKEN_MODULO_EQUAL: return "MODULO_EQUAL";
        case TOKEN_AND_EQUAL: return "AND_EQUAL";
        case TOKEN_OR_EQUAL: return "OR_EQUAL";
        case TOKEN_XOR_EQUAL: return "XOR_EQUAL";
        case TOKEN_LEFT_SHIFT_EQUAL: return "LEFT_SHIFT_EQUAL";
        case TOKEN_RIGHT_SHIFT_EQUAL: return "RIGHT_SHIFT_EQUAL";
        case TOKEN_ELLIPSIS: return "ELLIPSIS";
        case TOKEN_STRING_LITERAL: return "STRING_LITERAL";
        case TOKEN_CHAR_LITERAL: return "CHAR_LITERAL";
        // I/O Functions
        case TOKEN_PRINT: return "PRINT";
        case TOKEN_INPUT: return "INPUT";
        // String Functions
        case TOKEN_STR: return "STR";
        case TOKEN_UPPER: return "UPPER";
        case TOKEN_LOWER: return "LOWER";
        case TOKEN_CAPITALIZE: return "CAPITALIZE";
        case TOKEN_COUNT: return "COUNT";
        case TOKEN_FIND: return "FIND";
        case TOKEN_INDEX: return "INDEX";
        case TOKEN_ISALNUM: return "ISALNUM";
        case TOKEN_ISALPHA: return "ISALPHA";
        case TOKEN_ISDIGIT: return "ISDIGIT";
        case TOKEN_ISNUMERIC: return "ISNUMERIC";
        case TOKEN_ISSPACE: return "ISSPACE";
        case TOKEN_ISTITLE: return "ISTITLE";
        case TOKEN_ISUPPER: return "ISUPPER";
        case TOKEN_ISLOWER: return "ISLOWER";
        case TOKEN_REPLACE: return "REPLACE";
        case TOKEN_TITLE: return "TITLE";
        case TOKEN_POP: return "POP";
        case TOKEN_REVERSE: return "REVERSE";
        // Type Function
        case TOKEN_TYPE: return "TYPE";
        // ENDL , TAB
        case TOKEN_ENDL: return "ENDL";
        case TOKEN_TAB: return "TAB" ; 
        case TOKEN_LEN: return "LEN" ;
        case TOKEN_EXCEPT: return "EXCEPT" ;
        case TOKEN_IN: return "IN" ;
        case TOKEN_NOTIN: return "NOTIN";
        case TOKEN_IS: return "IS" ;
        case TOKEN_ISNOT: return "ISNOT";
        case TOKEN_AS: return "AS";
        case TOKEN_PASS: return "PASS" ;
        case TOKEN_ELIF: return "ELIF" ;
        case TOKEN_FROM: return "FROM" ;
        case TOKEN_IMPORT: return "IMPORT" ;
        
        case TOKEN_ABS: return "ABS" ;
        case TOKEN_CEIL: return "CEIL" ;
        case TOKEN_FLOOR: return "FLOOR" ;
        case TOKEN_ROUND: return "ROUND" ;
        
        case TOKEN_END: return "END";
        default: return "UNKNOWN";
    }
}

struct Token get_next_token(const char** input) {
    struct Token token = {TOKEN_END, ""};
    int i = 0;

    // Skip whitespace
    while (isspace(**input)) {
        (*input)++;
    }

    if (**input == '\0') {
        return token;
    }

    // Identifier or keyword
    if (isalpha(**input) || **input == '_') {
        while (isalnum(**input) || **input == '_') {
            token.value[i++] = **input;
            (*input)++;
        }
        token.value[i] = '\0';
        token.type = TOKEN_IDENTIFIER;
        
        // Check if it's a keyword
       if (strcmp(token.value, "bool") == 0) token.type = TOKEN_BOOL;
        else if (strcmp(token.value, "true") == 0) token.type = TOKEN_TRUE;
        else if (strcmp(token.value, "false") == 0) token.type = TOKEN_FALSE;
        else if (strcmp(token.value, "NULL") == 0) token.type = TOKEN_NULL;
        else if (strcmp(token.value, "if") == 0) token.type = TOKEN_IF;
        else if (strcmp(token.value, "else") == 0) token.type = TOKEN_ELSE;
        else if (strcmp(token.value, "while") == 0) token.type = TOKEN_WHILE;
        else if (strcmp(token.value, "for") == 0) token.type = TOKEN_FOR;
        else if (strcmp(token.value, "do") == 0) token.type = TOKEN_DO;
        else if (strcmp(token.value, "switch") == 0) token.type = TOKEN_SWITCH;
        else if (strcmp(token.value, "case") == 0) token.type = TOKEN_CASE;
        else if (strcmp(token.value, "default") == 0) token.type = TOKEN_DEFAULT;
        else if (strcmp(token.value, "break") == 0) token.type = TOKEN_BREAK;
        else if (strcmp(token.value, "continue") == 0) token.type = TOKEN_CONTINUE;
        else if (strcmp(token.value, "return") == 0) token.type = TOKEN_RETURN;
        else if (strcmp(token.value, "typedef") == 0) token.type = TOKEN_TYPEDEF;
        else if (strcmp(token.value, "struct") == 0) token.type = TOKEN_STRUCT;
        else if (strcmp(token.value, "union") == 0) token.type = TOKEN_UNION;
        else if (strcmp(token.value, "enum") == 0) token.type = TOKEN_ENUM;
        else if (strcmp(token.value, "sizeof") == 0) token.type = TOKEN_SIZEOF;
        else if (strcmp(token.value, "static") == 0) token.type = TOKEN_STATIC;
        else if (strcmp(token.value, "extern") == 0) token.type = TOKEN_EXTERN;
        else if (strcmp(token.value, "const") == 0) token.type = TOKEN_CONST;
        else if (strcmp(token.value, "volatile") == 0) token.type = TOKEN_VOLATILE;
        else if (strcmp(token.value, "void") == 0) token.type = TOKEN_VOID;
        else if (strcmp(token.value, "char") == 0) token.type = TOKEN_CHAR;
        else if (strcmp(token.value, "short") == 0) token.type = TOKEN_SHORT;
        else if (strcmp(token.value, "int") == 0) token.type = TOKEN_INT;
        else if (strcmp(token.value, "long") == 0) token.type = TOKEN_LONG;
        else if (strcmp(token.value, "float") == 0) token.type = TOKEN_FLOAT;
        else if (strcmp(token.value, "double") == 0) token.type = TOKEN_DOUBLE;
        else if (strcmp(token.value, "signed") == 0) token.type = TOKEN_SIGNED;
        else if (strcmp(token.value, "unsigned") == 0) token.type = TOKEN_UNSIGNED;
        else if (strcmp(token.value, "print") == 0) token.type = TOKEN_PRINT;
        else if (strcmp(token.value, "input") == 0) token.type = TOKEN_INPUT;
        else if (strcmp(token.value, "count") == 0) token.type = TOKEN_COUNT;
        else if (strcmp(token.value, "find") == 0) token.type = TOKEN_FIND;
        else if (strcmp(token.value, "index") == 0) token.type = TOKEN_INDEX;
        else if (strcmp(token.value, "isalnum") == 0) token.type = TOKEN_ISALNUM;
        else if (strcmp(token.value, "isalpha") == 0) token.type = TOKEN_ISALPHA;
        else if (strcmp(token.value, "isdigit") == 0) token.type = TOKEN_ISDIGIT;
        else if (strcmp(token.value, "isnumeric") == 0) token.type = TOKEN_ISNUMERIC;
        else if (strcmp(token.value, "isspace") == 0) token.type = TOKEN_ISSPACE;
        else if (strcmp(token.value, "istitle") == 0) token.type = TOKEN_ISTITLE;
        else if (strcmp(token.value, "isupper") == 0) token.type = TOKEN_ISUPPER;
        else if (strcmp(token.value, "islower") == 0) token.type = TOKEN_ISLOWER;
        else if (strcmp(token.value, "title") == 0) token.type = TOKEN_TITLE;
        else if (strcmp(token.value, "pop") == 0) token.type = TOKEN_POP;
        else if (strcmp(token.value, "reverse") == 0) token.type = TOKEN_REVERSE;
        else if (strcmp(token.value, "upper") == 0) token.type = TOKEN_UPPER;
        else if (strcmp(token.value, "lower") == 0) token.type = TOKEN_LOWER;
        else if (strcmp(token.value, "str") == 0) token.type = TOKEN_STR;
        else if (strcmp(token.value, "capitalize") == 0) token.type = TOKEN_CAPITALIZE;
        else if (strcmp(token.value, "type") == 0) token.type = TOKEN_TYPE;
        else if (strcmp(token.value, "replace") == 0) token.type = TOKEN_REPLACE;
        else if (strcmp(token.value, "endl") == 0) token.type = TOKEN_ENDL;
        else if (strcmp(token.value, "tab") == 0) token.type = TOKEN_TAB;
        else if (strcmp(token.value, "len") == 0) token.type = TOKEN_LEN;
        else if (strcmp(token.value, "except") == 0) token.type = TOKEN_EXCEPT;
        else if (strcmp(token.value, "and") == 0) token.type = TOKEN_AND;
        else if (strcmp(token.value, "or") == 0) token.type = TOKEN_OR;
        else if (strcmp(token.value, "not") == 0) token.type = TOKEN_NOT;
        
        else if (strcmp(token.value, "in") == 0) token.type = TOKEN_IN;
        else if (strcmp(token.value, "notin") == 0) token.type = TOKEN_NOTIN ;
        else if (strcmp(token.value, "is") == 0) token.type = TOKEN_IS;
        else if (strcmp(token.value, "isnot") == 0) token.type = TOKEN_ISNOT;
        else if (strcmp(token.value, "as") == 0) token.type = TOKEN_AS;
        else if (strcmp(token.value, "pass") == 0) token.type = TOKEN_PASS;
        else if (strcmp(token.value, "elif") == 0) token.type = TOKEN_ELIF;
        else if (strcmp(token.value, "from") == 0) token.type = TOKEN_FROM;
        else if (strcmp(token.value, "import") == 0) token.type = TOKEN_IMPORT;
        else if (strcmp(token.value, "try") == 0) token.type = TOKEN_TRY;
        else if (strcmp(token.value, "throw") == 0) token.type = TOKEN_THROW;
        else if (strcmp(token.value, "catch") == 0) token.type = TOKEN_CATCH;
        else if (strcmp(token.value, "ceil") == 0) token.type = TOKEN_CEIL;
        else if (strcmp(token.value, "floor") == 0) token.type = TOKEN_FLOOR;
        else if (strcmp(token.value, "round") == 0) token.type = TOKEN_ROUND;
        else if (strcmp(token.value, "abs") == 0) token.type = TOKEN_ABS;
        
        // Add more keywords as needed

        return token;
    }

    // Number
    if (isdigit(**input)) {
        token.type = TOKEN_NUMBER;
        while (isdigit(**input) || **input == '.') {
            token.value[i++] = **input;
            (*input)++;
        }
        token.value[i] = '\0';
        return token;
    }

    // Operators and punctuation
    switch (**input) {
        case '+':
            token.type = TOKEN_PLUS;
            if ((*input)[1] == '+') {
                token.type = TOKEN_PLUS_PLUS;
                strcpy(token.value, "++");
                (*input) += 2;
            } else if ((*input)[1] == '=') {
                token.type = TOKEN_PLUS_EQUAL;
                strcpy(token.value, "+=");
                (*input) += 2;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '-':
            token.type = TOKEN_MINUS;
            if ((*input)[1] == '-') {
                token.type = TOKEN_MINUS_MINUS;
                strcpy(token.value, "--");
                (*input) += 2;
            } else if ((*input)[1] == '=') {
                token.type = TOKEN_MINUS_EQUAL;
                strcpy(token.value, "-=");
                (*input) += 2;
            } else if ((*input)[1] == '>') {
                token.type = TOKEN_ARROW;
                strcpy(token.value, "->");
                (*input) += 2;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '*':
            token.type = TOKEN_MULTIPLY;
            if ((*input)[1] == '=') {
                token.type = TOKEN_MULTIPLY_EQUAL;
                strcpy(token.value, "*=");
                (*input) += 2;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '/':
            token.type = TOKEN_DIVIDE;
            if ((*input)[1] == '=') {
                token.type = TOKEN_DIVIDE_EQUAL;
                strcpy(token.value, "/=");
                (*input) += 2;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '%':
            token.type = TOKEN_MODULO;
            if ((*input)[1] == '=') {
                token.type = TOKEN_MODULO_EQUAL;
                strcpy(token.value, "%=");
                (*input) += 2;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '=':
            token.type = TOKEN_ASSIGN;
            if ((*input)[1] == '=') {
                token.type = TOKEN_EQUAL;
                strcpy(token.value, "==");
                (*input) += 2;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '<':
            token.type = TOKEN_LESS_THAN;
            if ((*input)[1] == '=') {
                token.type = TOKEN_LESS_EQUAL;
                strcpy(token.value, "<=");
                (*input) += 2;
            } else if ((*input)[1] == '<') {
                if ((*input)[2] == '=') {
                    token.type = TOKEN_LEFT_SHIFT_EQUAL;
                    strcpy(token.value, "<<=");
                    (*input) += 3;
                } else {
                    token.type = TOKEN_LEFT_SHIFT;
                    strcpy(token.value, "<<");
                    (*input) += 2;
                }
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '>':
            token.type = TOKEN_GREATER_THAN;
            if ((*input)[1] == '=') {
                token.type = TOKEN_GREATER_EQUAL;
                strcpy(token.value, ">=");
                (*input) += 2;
            } else if ((*input)[1] == '>') {
                if ((*input)[2] == '=') {
                    token.type = TOKEN_RIGHT_SHIFT_EQUAL;
                    strcpy(token.value, ">>=");
                    (*input) += 3;
                } else {
                    token.type = TOKEN_RIGHT_SHIFT;
                    strcpy(token.value, ">>");
                    (*input) += 2;
                }
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '&':
            token.type = TOKEN_BIT_AND;
            if ((*input)[1] == '&') {
                token.type = TOKEN_AND;
                strcpy(token.value, "&&");
                (*input) += 2;
            } else if ((*input)[1] == '=') {
                token.type = TOKEN_AND_EQUAL;
                strcpy(token.value, "&=");
                (*input) += 2;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '|':
            token.type = TOKEN_BIT_OR;
            if ((*input)[1] == '|') {
                token.type = TOKEN_OR;
                strcpy(token.value, "||");
                (*input) += 2;
            } else if ((*input)[1] == '=') {
                token.type = TOKEN_OR_EQUAL;
                strcpy(token.value, "|=");
                (*input) += 2;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '^':
            token.type = TOKEN_BIT_XOR;
            if ((*input)[1] == '=') {
                token.type = TOKEN_XOR_EQUAL;
                strcpy(token.value, "^=");
                (*input) += 2;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '!':
            token.type = TOKEN_NOT;
            if ((*input)[1] == '=') {
                token.type = TOKEN_NOT_EQUAL;
                strcpy(token.value, "!=");
                (*input) += 2;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '~':
            token.type = TOKEN_BIT_NOT;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case '(':
            token.type = TOKEN_LEFT_PAREN;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case ')':
            token.type = TOKEN_RIGHT_PAREN;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case '{':
            token.type = TOKEN_LEFT_BRACE;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case '}':
            token.type = TOKEN_RIGHT_BRACE;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case '[':
            token.type = TOKEN_LEFT_BRACKET;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case ']':
            token.type = TOKEN_RIGHT_BRACKET;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case ';':
            token.type = TOKEN_SEMICOLON;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case ':':
            token.type = TOKEN_COLON;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case ',':
            token.type = TOKEN_COMMA;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case '.':
            token.type = TOKEN_DOT;
            if ((*input)[1] == '.' && (*input)[2] == '.') {
                token.type = TOKEN_ELLIPSIS;
                strcpy(token.value, "...");
                (*input) += 3;
            } else {
                token.value[0] = **input;
                token.value[1] = '\0';
                (*input)++;
            }
            break;
        case '#':
            token.type = TOKEN_HASH;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
        case '"':
            token.type = TOKEN_STRING_LITERAL;
            token.value[i++] = **input;
            (*input)++;
            while (**input != '"' && **input != '\0') {
                if (**input == '\\' && *(*input + 1) != '\0') {
                    token.value[i++] = **input;
                    (*input)++;
                }
                token.value[i++] = **input;
                (*input)++;
            }
            if (**input == '"') {
                token.value[i++] = **input;
                (*input)++;
            }
            token.value[i] = '\0';
            break;
        case '\'':
            token.type = TOKEN_CHAR_LITERAL;
            token.value[i++] = **input;
            (*input)++;
            while (**input != '\'' && **input != '\0') {
                if (**input == '\\' && *(*input + 1) != '\0') {
                    token.value[i++] = **input;
                    (*input)++;
                }
                token.value[i++] = **input;
                (*input)++;
            }
            if (**input == '\'') {
                token.value[i++] = **input;
                (*input)++;
            }
            
            token.value[i] = '\0';
            break;
        default:
            token.type = TOKEN_END;
            token.value[0] = **input;
            token.value[1] = '\0';
            (*input)++;
            break;
    }

    return token;
}

int main() {
    const char* input = "int main() {\n"
                        "    int x = 5;\n"
                        "    float y = 3.14;\n"
                        "    char* str = \"Hello, World!\";\n"
                        "    if (x > 0 && y < 10.0) {\n"
                        "        printf(\"%d %f\\n\", x, y);\n"
                        "    }\n"
                        "    return 0;\n"
                        " false } abs ceil floor round include";

    const char* current = input;
    
    while (1) {
        struct Token token = get_next_token(&current);
        if (token.type == TOKEN_END) {
            break;
        }
        
        printf("Token: Type=%-20s Value=%s\n", token_type_to_string(token.type), token.value);
    }
    
    return 0;
}
