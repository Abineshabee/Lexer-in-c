# Lexer-in-c
Lexer in C


    (py-run) abinesh@abinesh-Lenovo-E41-25:~/Programs/c/ToyLanguage\>> ls

    cParser.py                       Lexer                             Lexer.c
//
    
    (py-run) abinesh@abinesh-Lenovo-E41-25:~/Programs/c/ToyLanguage\>> gcc Lexer.c -o Lexer
    (py-run) abinesh@abinesh-Lenovo-E41-25:~/Programs/c/ToyLanguage\>> ./Lexer
    
//

    Token: Type=INT                  Value=int

    Token: Type=IDENTIFIER           Value=main

    Token: Type=LEFT_PAREN           Value=(

    Token: Type=RIGHT_PAREN          Value=)

    Token: Type=LEFT_BRACE           Value={

    Token: Type=INT                  Value=int

    Token: Type=IDENTIFIER           Value=x

    Token: Type=ASSIGN               Value==

    Token: Type=NUMBER               Value=5

    Token: Type=SEMICOLON            Value=;

    Token: Type=FLOAT                Value=float

    Token: Type=IDENTIFIER           Value=y

    Token: Type=ASSIGN               Value==

    Token: Type=NUMBER               Value=3.14

    Token: Type=SEMICOLON            Value=;

    Token: Type=CHAR                 Value=char

    Token: Type=MULTIPLY             Value=*

    Token: Type=STR                  Value=str

    Token: Type=ASSIGN               Value==

    Token: Type=STRING_LITERAL       Value="Hello, World!"

    Token: Type=SEMICOLON            Value=;

    Token: Type=IF                   Value=if

    Token: Type=LEFT_PAREN           Value=(

    Token: Type=IDENTIFIER           Value=x

    Token: Type=GREATER_THAN         Value=>

    Token: Type=NUMBER               Value=0

    Token: Type=AND                  Value=&&

    Token: Type=IDENTIFIER           Value=y

    Token: Type=LESS_THAN            Value=<

    Token: Type=NUMBER               Value=10.0

    Token: Type=RIGHT_PAREN          Value=)

    Token: Type=LEFT_BRACE           Value={

    Token: Type=IDENTIFIER           Value=printf

    Token: Type=LEFT_PAREN           Value=(

    Token: Type=STRING_LITERAL       Value="%d %f\n"

    Token: Type=COMMA                Value=,

    Token: Type=IDENTIFIER           Value=x

    Token: Type=COMMA                Value=,

    Token: Type=IDENTIFIER           Value=y

    Token: Type=RIGHT_PAREN          Value=)

    Token: Type=SEMICOLON            Value=;

    Token: Type=RIGHT_BRACE          Value=}

    Token: Type=RETURN               Value=return

    Token: Type=NUMBER               Value=0

    Token: Type=SEMICOLON            Value=;

    Token: Type=FALSE                Value=false

    Token: Type=RIGHT_BRACE          Value=}

    Token: Type=ABS                  Value=abs

    Token: Type=CEIL                 Value=ceil

    Token: Type=FLOOR                Value=floor

    Token: Type=ROUND                Value=round

    Token: Type=IDENTIFIER           Value=include

(py-run) abinesh@abinesh-Lenovo-E41-25:~/Programs/c/ToyLanguage\>> 

