#ifndef MINISHELL_H
#define MINISHELL_H

typedef struct s_parse{
    int value;
    int type;

}t_parse ;

/*
    shell syntax: Lexical analysis:
        uses of quotes and how does it plays the role in parsing:
        -> Quoting can be used to reserve some literal meaning of some characters 
        -> Prevent reserved words from being interpreted as commands
        -> Prevent command expansion and subsitiution within the here-document
        -> You can quote the following characters to prevent from being recognised as command
            -> | & ; < > ( ) $ - \ "  '
            so in the parsing, when those characters are found inside the quote, they will be treated as regular words not command.
            for example echo " hello | here" this will be echoed as its, another example echo "helllo ""hello" -> helllo hello

*/
#endif