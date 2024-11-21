typedef struct double_stack DS;
typedef struct char_stack CS;

DS *double_stack_init();
CS *char_stack_init();
void double_stack_push(DS *s, double d);
double double_stack_pop(DS *s);
void char_stack_push(CS *s, char c);
char char_stack_pop(CS *s);
void double_stack_free(DS *s);
void char_stack_free(CS *s);