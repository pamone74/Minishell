#ifndef TOKEN
#define TOKEN

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
typedef enum  e_token_id{
    IDENTIFIER,
    INPUT,
    OUTPUT,
    HERE_DOC,
    APPEND_MODE,
    O_PARENT,
    C_PARENT, 
    AND,
    OR,
    NL,
}   t_token_id;

typedef struct s_token t_token;
typedef char *Value;
struct s_token{
    t_token_id  type;
    Value       value;
    struct  s_token *next;
    struct  s_token *prev;    
};
#endif
