#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_TOKEN 50
#define MAX_CHAR 20
#define MAX_EXPRESSION 100

typedef enum token_types{
    TOKEN_NUMBER,
    TOKEN_VARIABLE,
    TOKEN_CONSTANT,
    TOKEN_OPERATOR,
    TOKEN_FUNCTION,
    TOKEN_PAREN_LEFT,
    TOKEN_PAREN_RIGHT,
    TOKEN_COMMA
} TokenType;

typedef struct token{
    TokenType type;
    char *value;
} TOKEN;

typedef enum nodeTypes {
    NODE_NUMBER,
    NODE_VARIABLE,
    NODE_CONSTANT,
    NODE_FUNCTION,
    NODE_OPERATOR
} NODE_TYPE;

typedef struct node{
    NODE_TYPE type;
    char *value;
    struct node* right;
    struct node* left;
} NODE;

int Tokenizer(char *exp, TOKEN *tokens, int *token_count);
int InsertImplicitMultiplications(TOKEN *tokens, int *token_count);
void display_tokens(TOKEN *tokens, int *token_count);
NODE* create_node(NODE_TYPE type, char* value, NODE* left, NODE* right);
NODE* parse_factor(TOKEN* tokens, int* curr);
NODE* parse_function_args(TOKEN* tokens, int* curr);
NODE* parse_power(TOKEN* tokens, int* curr);
NODE* parse_term(TOKEN* tokens, int* curr);
NODE* parse_expression(TOKEN* tokens, int* curr);
void print_node(NODE* node, int depth);
double evaluate(NODE* node, double x);
void free_tokens(TOKEN* tokens, int token_count);
void free_node(NODE* node);
void bisection_method();
void regula_falsi_method();
void newton_raphson_method();
void inverse_matrix();
double** allocate_matrix(int n);
void free_matrix(double** matrix, int n);
void cholesky_method();
void gauss_seidel_method();
int make_diagonally_dominant(double** A, double* C, int n);
void numerical_derivative_method();
void simpson_method();
void trapez_method();
void gregory_newton_method();


int main() {
    int choice = 0;
    while (1) {
        printf("\n==============================\n");
        printf(" NUMERICAL ANALYSIS MENU\n");
        printf("==============================\n");
        printf("1) Bisection Method\n");
        printf("2) Regula-Falsi Method\n");
        printf("3) Newton-Raphson Method\n");
        printf("4) Inverse Matrix\n");
        printf("5) Cholesky Method\n");
        printf("6) Gauss-Seidel Method\n");
        printf("7) Numerical Derivative\n");
        printf("8) Simpson Method\n");
        printf("9) Trapez Method\n");
        printf("10) Gregory-Newton Interpolation\n");
        printf("11) EXIT\n");
        printf("------------------------------\n");
        printf("Select an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        // clear stdin buffer
        int ch;
        do {
            ch = getchar();
        } while (ch != '\n' && ch != EOF);

        switch (choice) {
            case 1:
                bisection_method();
                break;
            case 2:
                regula_falsi_method();
                break;
            case 3:
                newton_raphson_method();
                break;
            case 4:
                inverse_matrix();
                break;
            case 5:
                cholesky_method();// ***
                break;
            case 6:
                gauss_seidel_method();
                break;
            case 7:
                numerical_derivative_method();
                break;
            case 8:
                simpson_method();
                break;
            case 9:
                trapez_method();
                break;
            case 10:
                gregory_newton_method();
                break;
            case 11:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter number between 1-11.\n");
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\nPress ENTER to continue");
        while (getchar() != '\n');
    }
    return 0;
}
int Tokenizer(char *exp, TOKEN *tokens, int *token_count){
    int i=0, j;
    int len = strlen(exp);
    *token_count = 0;

    while(i<len){
        if(isspace(*(exp+i)))
            i++;
        else if(isdigit(*(exp+i)) || (*(exp+i) == '.' && isdigit(*(exp+i+1)))){     // number token
            (tokens + *token_count)->type = TOKEN_NUMBER;
            (tokens + *token_count)->value = (char *)malloc(MAX_CHAR);  // max 20 character for token
            if((tokens + *token_count)->value == NULL){
                printf("Memory allocation failed for token value!\n");
                return -1;
            }
            j=0;
            while(isdigit(*(exp+i)) || (*(exp+i) == '.')){
                (tokens + *token_count)->value[j] = *(exp+i);
                i++; j++;
            }
            (tokens + *token_count)->value[j] = '\0';
            (*token_count)++;
        }
        else if(isalpha(*(exp+i))){                                    // variable and function token
            (tokens + *token_count)->value = (char *)malloc(MAX_CHAR);  // max 20 character for token
            if((tokens + *token_count)->value == NULL){
                printf("Memory allocation failed for token value!\n");
                return -1;
            }
            j = 0;
            while(isalpha(*(exp+i))){
                (tokens + *token_count)->value[j] = *(exp+i);
                i++; j++;
            }
            (tokens + *token_count)->value[j] = '\0';

            if(strlen((tokens + *token_count)->value) == 1){
                if((tokens + *token_count)->value[0] == 'e')
                    (tokens + *token_count)->type = TOKEN_CONSTANT;
                else
                    (tokens + *token_count)->type = TOKEN_VARIABLE;
            }
            else{
                if(!strcmp((tokens + *token_count)->value , "pi"))
                    (tokens + *token_count)->type = TOKEN_CONSTANT;
                else
                    (tokens + *token_count)->type = TOKEN_FUNCTION;
            }
            (*token_count)++;
        }
        else if(strchr("+-*/^",*(exp+i))){                      // operator token
            (tokens + *token_count)->type = TOKEN_OPERATOR;
            (tokens + *token_count)->value = (char *)malloc(2);  
            if((tokens+ *token_count)->value == NULL){
                printf("Memory allocation failed for token value!\n");
                return -1;
            }
            (tokens + *token_count)->value[0] = *(exp+i);
            (tokens + *token_count)->value[1] = '\0';
            i++;
            (*token_count)++;
        }
        else if(*(exp+i) == '('){                               // left parenthesis token
            (tokens + *token_count)->type = TOKEN_PAREN_LEFT;
            (tokens + *token_count)->value = (char *)malloc(2);  
            if((tokens+ *token_count)->value == NULL){
                printf("Memory allocation failed for token value!\n");
                return -1;
            }
            (tokens + *token_count)->value[0] = *(exp+i);
            (tokens + *token_count)->value[1] = '\0';
            i++;
            (*token_count)++;
        }
        else if(*(exp+i) == ')'){                               // right paranthesis token
            (tokens + *token_count)->type = TOKEN_PAREN_RIGHT;
            (tokens + *token_count)->value = (char *)malloc(2);  
            if((tokens+ *token_count)->value == NULL){
                printf("Memory allocation failed for token value!\n");
                return -1;
            }
            (tokens + *token_count)->value[0] = *(exp+i);
            (tokens + *token_count)->value[1] = '\0';
            i++;
            (*token_count)++;
        }
        else if(*(exp+i) == ','){                               // comma token
            tokens[*token_count].type = TOKEN_COMMA;
            tokens[*token_count].value = (char *)malloc(2);
            if(tokens[*token_count].value == NULL){
                printf("Memory allocation failed for token value!\n");
                return -1;
            }
            tokens[*token_count].value[0] = *(exp+i);
            tokens[*token_count].value[1] = '\0';
            i++;
            (*token_count)++;
        }
        else{
            printf("Invalid character. %c",*(exp+i));
            return 1;
        }
    }
    return 0;
}
int InsertImplicitMultiplications(TOKEN *tokens, int *token_count){
    int i = 0;
    while(i < *token_count - 1){
        TOKEN current = tokens[i];
        TOKEN next = tokens[i + 1];
        int insert = 0;

        if((current.type == TOKEN_NUMBER || current.type == TOKEN_PAREN_RIGHT || current.type == TOKEN_VARIABLE) &&
            (next.type == TOKEN_VARIABLE || next.type == TOKEN_FUNCTION || next.type == TOKEN_PAREN_LEFT || next.type == TOKEN_NUMBER)){
            insert = 1;
        }
        if(insert){
            // shift tokens
            for (int j = *token_count; j > i + 1; j--) {
                tokens[j] = tokens[j - 1];
            }
            // add multiplication token
            tokens[i + 1].type = TOKEN_OPERATOR;
            tokens[i + 1].value = malloc(2);
            if (tokens[i + 1].value == NULL) {
                printf("Memory allocation failed while inserting *\n");
                return -1;
            }
            strcpy(tokens[i + 1].value, "*");

            (*token_count)++;
            i++;
        }
        i++;
    }
    return 0;
}
void display_tokens(TOKEN *tokens, int *token_count){
    int i;
    for(i=0;i<*token_count;i++){
        printf("  %s (%d)\n", tokens[i].value, tokens[i].type);
    }
}
NODE* create_node(NODE_TYPE type, char* value, NODE* left, NODE* right){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("Memory allocation failed for newnode!");
        exit(1);
    }
    newNode->type = type;
    newNode->left = left;
    newNode->right = right;
    newNode->value = (char*)malloc(strlen(value) + 1);
    if (newNode->value == NULL){
        printf("Memory allocation failed for node value!");
        exit(1);
    }
    strcpy(newNode->value,value);
    return newNode;
}
NODE* parse_factor(TOKEN* tokens, int* curr){
    TOKEN t = tokens[*curr];
    // for negative node
    if(t.type == TOKEN_OPERATOR && t.value[0] == '-'){
        (*curr)++;
        NODE* minus = parse_factor(tokens, curr);
        return create_node(NODE_OPERATOR, "n-", minus, NULL);  // n- = negative
    }
    if(t.type == TOKEN_CONSTANT){
        (*curr)++;
        return create_node(NODE_CONSTANT, t.value, NULL, NULL);
    }
    if(t.type == TOKEN_NUMBER || t.type == TOKEN_VARIABLE){
        (*curr)++;
        return create_node(t.type == TOKEN_NUMBER ? NODE_NUMBER : NODE_VARIABLE, t.value, NULL, NULL);
    }
    if(t.type == TOKEN_FUNCTION){
        char* func_name = (char*)malloc(strlen(t.value)+1);
        if(func_name == NULL){
            printf("Memory allocation failed for funcname!");
            exit(1);
        }
        strcpy(func_name, t.value);
        (*curr)++;
        if(tokens[*curr].type != TOKEN_PAREN_LEFT){ 
            printf("Missing '('\n"); 
            exit(1);
        }
        (*curr)++;

        NODE* args = parse_function_args(tokens, curr);
        if(tokens[*curr].type != TOKEN_PAREN_RIGHT){ 
            printf("Missing ')' \n");
            exit(1);
        }
        (*curr)++;
        return create_node(NODE_FUNCTION, func_name, args, NULL);
    }
    if(t.type == TOKEN_PAREN_LEFT){
        (*curr)++;
        NODE* node = parse_expression(tokens, curr);
        if(tokens[*curr].type != TOKEN_PAREN_RIGHT){ 
        printf("Missing ')'\n"); 
        exit(1); 
        }
        (*curr)++;
        return node;
    }
  printf("Unexpected token: %s\n", t.value);
  return NULL;
}
NODE* parse_function_args(TOKEN* tokens, int* curr){
    NODE* first_arg = parse_expression(tokens, curr);
    NODE* last_arg = first_arg;

    while(tokens[*curr].type == TOKEN_COMMA){
        (*curr)++;
        NODE* next_arg = parse_expression(tokens, curr);
        last_arg->right = next_arg;
        last_arg = next_arg;
    }
    return first_arg;
}
// (^)
NODE* parse_power(TOKEN* tokens, int* curr){
    NODE* node = parse_factor(tokens, curr);
    while(tokens[*curr].type == TOKEN_OPERATOR && tokens[*curr].value[0] == '^'){
        (*curr)++;
        NODE* right = parse_factor(tokens, curr);
        node = create_node(NODE_OPERATOR, "^", node, right);
    }
    return node;
}
// (* and /)
NODE* parse_term(TOKEN* tokens, int* curr){
  NODE* node = parse_power(tokens, curr);
  while(tokens[*curr].type == TOKEN_OPERATOR && (tokens[*curr].value[0] == '*' || tokens[*curr].value[0] == '/')){
        char op = tokens[*curr].value[0];
        (*curr)++;
        NODE* right = parse_power(tokens, curr);
        char op_str[2] = {op, '\0'};
        node = create_node(NODE_OPERATOR, op_str, node, right);
    }
    return node;
}
// (+ and -)
NODE* parse_expression(TOKEN* tokens, int* curr){
  NODE* node = parse_term(tokens, curr);
  while(tokens[*curr].type == TOKEN_OPERATOR && (tokens[*curr].value[0] == '+' || tokens[*curr].value[0] == '-')){
        char op = tokens[*curr].value[0];
        (*curr)++;
        NODE* right = parse_term(tokens, curr);
        char op_str[2] = {op, '\0'};
        node = create_node(NODE_OPERATOR, op_str, node, right);
    }
    return node;
}
void print_node(NODE* node, int depth){
    if(node == NULL) return;
    for(int i = 0; i < depth; i++) printf("  ");
    printf("%s (%s)\n", node->value,
        node->type == NODE_NUMBER ? "NUMBER" :
        node->type == NODE_VARIABLE ? "VARIABLE" :
        node->type == NODE_OPERATOR ? "OPERATOR" : "FUNCTION");
    print_node(node->left, depth + 1);
    print_node(node->right, depth + 1);
}
double evaluate(NODE* node, double x){
    if(node == NULL){
        printf("The node is NULL.\n");
        exit(1);
    }
    if(node->type == NODE_NUMBER){
        return atof(node->value);  // string to double
    }
    if(node->type == NODE_VARIABLE){
        return x;
    }
    if(node->type == NODE_CONSTANT){
        if(node->value[0] == 'e')
            return exp(1);
        else if (strcmp(node->value, "pi") == 0)
            return 2 * asin(1);
        else {
            printf("Unknown constant '%s'\n", node->value);
            exit(1);
        }
    }
    if(node->type == NODE_OPERATOR){
        double left = 0.0, right = 0.0;
        // for negative node
        if(strcmp(node->value, "n-") == 0){
            return -evaluate(node->left, x);
        }
        left = evaluate(node->left, x);
        right = evaluate(node->right, x);

        if (strcmp(node->value, "+") == 0) return left + right;
        if (strcmp(node->value, "-") == 0) return left - right;
        if (strcmp(node->value, "*") == 0) return left * right;
        if (strcmp(node->value, "/") == 0) return left / right;
        if (strcmp(node->value, "^") == 0) return pow(left, right);

        printf("Unknown operator '%s'\n", node->value);
        exit(1);
    }
    if(node->type == NODE_FUNCTION){
        NODE* arg_node = node->left;

        if(strcmp(node->value, "log") == 0){
            if(arg_node == NULL){
                printf("Teher is no argument for log function!\n");
                exit(1);
            }
            double base = 10;  // default base 10
            double value;
            if(arg_node->right != NULL){
                // log(base, value)
                base = evaluate(arg_node, x);
                value = evaluate(arg_node->right, x);
                if(base <= 1 || value <= 0){
                    printf("Invalid arguments to log(base, value)\n");
                    exit(1);
                }
                return log(value) / log(base);
            } 
            else{
                // log(value)
                value = evaluate(arg_node, x);
                if(value <= 0){
                    printf("Invalid argument to log(value)\n");
                    exit(1);
                }
                return log10(value);
            }
        }
        double arg = evaluate(arg_node, x);

        if (strcmp(node->value, "sin") == 0) return sin(arg);
        if (strcmp(node->value, "cos") == 0) return cos(arg);
        if (strcmp(node->value, "tan") == 0) return tan(arg);
        if (strcmp(node->value, "cot") == 0) return 1 / tan(arg);
        if (strcmp(node->value, "arcsin") == 0) return asin(arg);
        if (strcmp(node->value, "arccos") == 0) return acos(arg);
        if (strcmp(node->value, "arctan") == 0) return atan(arg);
        if (strcmp(node->value, "arccot") == 0) return atan(1/arg);
        if (strcmp(node->value, "exp") == 0) return exp(arg);
        if (strcmp(node->value, "sqrt") == 0) return sqrt(arg);
        if (strcmp(node->value, "abs") == 0) return fabs(arg);
        if (strcmp(node->value, "ln") == 0) return log(arg);     
    
        printf("Unknown function '%s'\n", node->value);
        exit(1);
    }
    printf("Invalid node type!\n");
    exit(1);
}
void free_tokens(TOKEN* tokens, int token_count){
    for(int i = 0; i < token_count; i++){
        free(tokens[i].value);
    }
    free(tokens);
}
void free_node(NODE* node){
    if(node != NULL){
        free_node(node->left);
        free_node(node->right);
        free(node->value);
        free(node);
    }
}
// 1. Method
void bisection_method(){
    char* input = (char*)malloc(MAX_EXPRESSION * sizeof(char));
    TOKEN* tokens = (TOKEN*)malloc(MAX_TOKEN * sizeof(TOKEN));
    if(input == NULL || tokens == NULL){
        printf("Memory allocation failed.\n");
        free(input);
        return;
    }
    int token_count = 0;
    int curr = 0;
    double a, b, eps;

    printf("\n[BISECTION METHOD]\nEnter the function (exp: x^3 - x - 2):\n> ");

    fgets(input, MAX_EXPRESSION, stdin);
    input[strcspn(input, "\n")] = 0; // clear \n end of the string

    if(Tokenizer(input, tokens, &token_count)){
        printf("Tokenize error.\n");
        free_tokens(tokens, token_count);
        free(input);
        return;
    }
    InsertImplicitMultiplications(tokens, &token_count);

    curr = 0;
    NODE* func = parse_expression(tokens, &curr);
    if(curr != token_count){
        printf("Wrong token: '%s'\n", tokens[curr].value);
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the value of epsilon: ");
    scanf("%lf", &eps);

    if(eps <= 0) {
        printf("h must be greater than 0.\n");
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    double fa = evaluate(func, a);
    double fb = evaluate(func, b);
    if(fa * fb >= 0){
        printf("f(a) * f(b) >= 0. There isn't any root.\n");
        free_tokens(tokens, token_count);
        free_node(func);
        return;
    }
    double c, fc;
    int iter = 0;
    printf("\nIter |     a      |     b      |     c      |    f(a)    |    f(b)    |    f(c)    |   |b - a|  \n");
    printf("------------------------------------------------------------------------------------------------------\n");

    while(fabs(b - a) >= eps){
        c = (a + b) / 2;
        fc = evaluate(func, c);

        printf("%4d | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf\n", iter+1, a, b, c, fa, fb, fc, fabs(b-a));

        if(fa * fc < 0){
            b = c;
            fb = fc;
        }
        else{
            a = c;
            fa = fc;
        }
        iter++;
        if(iter > 1000){
            printf("Iteration limit exceeded.\n");
            return;
        }
    }
    printf("\nError(end): %5lf",fabs(b-a));
    printf("\nApproximate root: x = %.5lf\n", c);

    free_tokens(tokens, token_count);
    free_node(func);
    free(input);
}
// 2. Method
void regula_falsi_method(){
    char* input = (char*)malloc(MAX_EXPRESSION * sizeof(char));
    TOKEN* tokens = (TOKEN*)malloc(MAX_TOKEN * sizeof(TOKEN));
    int token_count = 0;
    int curr = 0;
    double a, b, eps;

    if(input == NULL || tokens == NULL){
        printf("Memory allocation failed.\n");
        free(input);
        return;
    }

    printf("\n[REGULA-FALSI METHOD]\nEnter the function (exp: x^3 - x - 2):\n> ");

    fgets(input, MAX_EXPRESSION, stdin);
    input[strcspn(input, "\n")] = 0;

    if(Tokenizer(input, tokens, &token_count)){
        printf("Tokenize error.\n");
        free_tokens(tokens, token_count);
        free(input);
        return;
    }
    InsertImplicitMultiplications(tokens, &token_count);

    curr = 0;
    NODE* func = parse_expression(tokens, &curr);
    if(curr != token_count){
        printf("Parse error: remaining token '%s'\n", tokens[curr].value);
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }

    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the epsilon: ");
    scanf("%lf", &eps);

    if(eps <= 0){
        printf("epsilon must be positive.\n");
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    double fa = evaluate(func, a);
    double fb = evaluate(func, b);
    if(fa * fb >= 0){
        printf("f(a) * f(b) >= 0. No root guaranteed in [a, b]\n");
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    double c = 0, fc = 0;
    int iter = 0;
    printf("\nIter |     a      |     b      |     c      |    f(a)    |    f(b)    |    f(c)    |   error  \n");
    printf("--------------------------------------------------------------------------------------------------\n");
    do{
        c = (b * fa - a * fb) / (fa - fb);
        fc = evaluate(func, c);

        printf("%4d | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf\n", iter+1, a, b, c, fa, fb, fc, fabs(b-a));

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

        iter++;
        if(iter > 1000){
            printf("Iteration limit exceeded.\n");
            return;
        }
    } while(fabs(fc) >= eps);

    printf("\nError(end): %5lf",fabs(b-a));
    printf("\nApproximate root: x = %.5lf\n", c);

    free_tokens(tokens, token_count);
    free_node(func);
    free(input);
}
// 3. Method
void newton_raphson_method(){
    char* input = (char*)malloc(MAX_EXPRESSION * sizeof(char));
    TOKEN* tokens = (TOKEN*)malloc(MAX_TOKEN * sizeof(TOKEN));
    int token_count = 0, curr = 0;
    double a, b, x0, eps;

    if(input == NULL || tokens == NULL){
        printf("Memory allocation failed.\n");
        free(input);
        return;
    }

    printf("\n[NEWTON-RAPHSON METHOD]\nEnter the function (exp: x^3 - x - 2):\n> ");

    fgets(input, MAX_EXPRESSION, stdin);
    input[strcspn(input, "\n")] = 0;

    if(Tokenizer(input, tokens, &token_count)){
        printf("Tokenize error.\n");
        free_tokens(tokens, token_count);
        free(input);
        return;
    }
    InsertImplicitMultiplications(tokens, &token_count);

    curr = 0;
    NODE* func = parse_expression(tokens, &curr);
    if(curr != token_count){
        printf("Parse error: remaining token '%s'\n", tokens[curr].value);
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    char dec;
    printf("Do you want to enter a starting point? (Y/N)");
    scanf("%c",&dec);

    double x;
    if(dec == 'y' || dec == 'Y'){
        printf("Enter x0: ");
        scanf("%lf", &x0);
        x = x0;
    }
    else{
        printf("Enter the value of a: ");
        scanf("%lf", &a);
        printf("Enter the value of b: ");
        scanf("%lf", &b);
        x = a < b ? a : b;
    }
    printf("Enter epsilon: ");
    scanf("%lf", &eps);
    if(eps <= 0){
        printf("Tolerance must be positive.\n");
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    double old, x_next, fx, dfx;
    int iter = 0;
    printf("\nIter |      x_n     |    x_(n+1)  |    f(x_n)   |   f'(x_n)   |   error\n");
    printf("--------------------------------------------------------------------------------\n");

    do{
        old = x;
        fx = evaluate(func, x);
        dfx = (evaluate(func, x + eps) - evaluate(func, x - eps)) / (2 * eps);

        x_next = x - fx / dfx;

        printf("%4d | %12.6lf | %12.6lf | %12.6lf | %12.6lf | %10.6lf\n", iter, x, x_next, fx, dfx, fabs(x_next - x));

        x = x_next;
        iter++;
        if(iter > 1000){
            printf("Iteration limit exceeded.\n");
            return;
        }
    } while(fabs(x - old) >= eps);

    printf("Error(end): %5lf",fabs(x - old));
    printf("\nApproximate root: x = %.5lf\n", x);

    free_tokens(tokens, token_count);
    free_node(func);
    free(input);
}
// 4. Method
void inverse_matrix(){
    int n,i,j,k;
    printf("\n[INVERSE OF MATRIX - GAUSS-JORDAN METHOD]\n");
    printf("Enter the size N of NxN matrix: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Matrix size must be positive.\n");
        return;
    }

    double** mat = allocate_matrix(n);
    double** identity = allocate_matrix(n);

    if (mat == NULL || identity == NULL) {
        printf("Memory allocation failed.\n");
        if (mat != NULL) free_matrix(mat, n);
        if (identity != NULL) free_matrix(identity, n);
        return;
    }

    printf("Enter values in the matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            identity[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    // Gauss-Jordan process
    for(i = 0; i < n; i++) {
        // If the pivot is zero, swap the pivot row
        if (fabs(mat[i][i]) < 1e-10) {
            int swap_row = -1;
            int k = i + 1;
            while (k < n && swap_row == -1) {
                if (fabs(mat[k][i]) > 1e-10) {
                    swap_row = k;
                }
                k++;
            }
            if (swap_row == -1) {
                printf("Matrix is singular. Cannot invert.\n");
                free_matrix(mat, n);
                free_matrix(identity, n);
                return;
            }
            // swap the rows
            double* temp = mat[i];
            mat[i] = mat[swap_row];
            mat[swap_row] = temp;

            temp = identity[i];
            identity[i] = identity[swap_row];
            identity[swap_row] = temp;

            printf("Row %d swapped with row %d for pivoting.\n", i, swap_row);
        }
        double pivot = mat[i][i];
        for (j = 0; j < n; j++) {
            mat[i][j] /= pivot;
            identity[i][j] /= pivot;
        }
        // Zero all elements except the pivot
        for (k = 0; k < n; k++) {
            if (k != i){
                double factor = mat[k][i];
                for (int j = 0; j < n; j++) {
                    mat[k][j] -= factor * mat[i][j];
                    identity[k][j] -= factor * identity[i][j];
                }
            }
        }
    }
    printf("\nInverse matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%10.5lf ", identity[i][j]);
        }
        printf("\n");
    }
    free_matrix(mat, n);
    free_matrix(identity, n);
}
double** allocate_matrix(int n){
    int i,j;
    double** mat = (double**)malloc(n * sizeof(double*));
    if(mat == NULL) return NULL;

    for(i=0;i<n;i++){
        mat[i] = (double*)malloc(n * sizeof(double));
        if (mat[i] == NULL) {
            for(j=0;j<i;j++) free(mat[j]);
            free(mat);
            return NULL;
        }
    }
    return mat;
}
void free_matrix(double** matrix, int n){
    int i;
    for(i=0;i<n;i++){
        free(matrix[i]);
    }
    free(matrix);
}
// 5. Method
void cholesky_method(){
    int n,i,j,k;
    printf("\n[CHOLESKY METHOD]\n");
    printf("Enter the size of the system (n): ");
    scanf("%d", &n);

    double** A = allocate_matrix(n);
    double** L = allocate_matrix(n);
    double** U = allocate_matrix(n);
    double* C = malloc(n * sizeof(double));
    double* Y = malloc(n * sizeof(double));
    double* X = malloc(n * sizeof(double));
    if (A == NULL || L == NULL || U == NULL || C == NULL || Y == NULL || X == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the coefficients matrix ([A]):\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("A[%d][%d]:",i,j);
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Enter the result of equations ([C]):\n");
    for (i = 0; i < n; i++){
        printf("C[%d]:",i);
        scanf("%lf", &C[i]);
    }
    // LU Faktörizasyonu (U'nun diagonal elemanları 1)
    for (i = 0; i < n; i++) {
        U[i][i] = 1.0;
        for (j = 0; j <= i; j++) {
            double sum = 0.0;
            for (k = 0; k < j; k++)
                sum += L[i][k] * U[k][j];
            L[i][j] = A[i][j] - sum;
        }
        for (j = i + 1; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < i; k++)
                sum += L[i][k] * U[k][j];
            if (L[i][i] == 0) {
                printf("LU factorization failed: zero pivot.\n");
                free_matrix(A, n);
                free_matrix(L, n);
                free_matrix(U, n);
                free(C);
                free(Y);
                free(X);
                return;
            }
            U[i][j] = (A[i][j] - sum) / L[i][i];
        }
    }
    // L*Y = C
    for (i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < i; j++)
            sum += L[i][j] * Y[j];
        Y[i] = (C[i] - sum) / L[i][i];
    }
    // U*X = Y
    for (i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (j = i + 1; j < n; j++)
            sum += U[i][j] * X[j];
        X[i] = Y[i] - sum;
    }
    printf("\nValues of x:\n");
    for (i = 0; i < n; i++)
        printf("x[%d] = %.6lf\n", i+1, X[i]);
    
    printf("\nValues of y:\n");
    for (i = 0; i < n; i++)
        printf("y[%d] = %.6lf\n", i+1, Y[i]);

    free_matrix(A, n);
    free_matrix(L, n);
    free_matrix(U, n);
    free(C);
    free(Y);
    free(X);
}
// 6. Method
void gauss_seidel_method(){
    int n,i,j, max_iter;
    double eps;

    printf("\n[GAUSS-SEIDEL METHOD]\n");
    printf("Enter the number of variables (n): ");
    scanf("%d", &n);

    double** A = allocate_matrix(n);
    double* C = malloc(n * sizeof(double));
    double* x = malloc(n * sizeof(double));
    double* x_old = malloc(n * sizeof(double));
    if(A == NULL || C == NULL || x == NULL || x_old == NULL){
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter coefficient matrix ([A]):\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("A[%d][%d]:",i,j);
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Enter result of equations ([C]):\n");
    for(i = 0; i < n; i++){
        printf("C[%d]: ", i);
        scanf("%lf", &C[i]);
    }
    printf("Enter epsilon: ");
    scanf("%lf", &eps);

    /*printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iter);*/

    printf("Enter the starting values:\n");
    for(i = 0; i < n; i++){
        printf("x[%d]:", i);
        scanf("%lf",&x[i]);
    }
    // diagonal dominant check
    int diagonally_dominant = 1;
    i=0;
    while(i < n && diagonally_dominant){
        double diag = fabs(A[i][i]);
        double sum = 0.0;
        for(j = 0; j < n; j++){
            if(j != i) sum += fabs(A[i][j]);
        }
        if(diag < sum){
            diagonally_dominant = 0;
        }
        i++;
    }

    if(!diagonally_dominant){
        printf("\nMatrix is not diagonally dominant.\n");
        if(make_diagonally_dominant(A, C, n)){
            printf("Matrix successfully reordered to be diagonally dominant.\n");
        } 
        else{
            printf("[ERROR] Could not make the matrix diagonally dominant. Aborting.\n");
            free_matrix(A,n);
            free(C);
            free(x);
            free(x_old);
            return;
        }
    }
    printf("\n%-10s", "Iter");
    for(i = 0; i < n; i++)
        printf("x[%d]%-10s", i, "");
    printf("\n----------------------------------------------------------\n");

    int dec = 1, iter = 0;
    while(dec){  // iter < max_iter && dec
        for (i = 0; i < n; i++)
            x_old[i] = x[i];

        for (i = 0; i < n; i++) {
            double sum1 = 0.0, sum2 = 0.0;

            for (j = 0; j < i; j++)
                sum1 += A[i][j] * x[j];

            for (j = i + 1; j < n; j++)
                sum2 += A[i][j] * x_old[j];

            x[i] = (C[i] - sum1 - sum2) / A[i][i];
        }

        double err = 0.0;
        for (i = 0; i < n; i++) {
            double diff = fabs(x[i] - x_old[i]);
            if (diff > err) err = diff;
        }
        printf("%-7d", iter + 1);
        for(i = 0; i < n; i++)
            printf("%.10lf  ", x[i]);
        printf("\n");

        if (err < eps) dec = 0;
        iter ++;
    }
    if (iter == max_iter)
        printf("Warning: Maximum iterations reached without convergence.\n");

    printf("\nSolution after %d iterations:\n", iter);
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.10lf\n", i, x[i]);

    free_matrix(A,n);
    free(C);
    free(x);
    free(x_old);
}
int make_diagonally_dominant(double** A, double* C, int n){
    int* used = (int*)calloc(n, sizeof(int));
    if (used == NULL) return 0;

    double** newA = (double**)malloc(n * sizeof(double*));
    if (newA == NULL) {
        free(used);
        return 0;
    }
    double* newC = (double*)malloc(n * sizeof(double));
    if (newC == NULL) {
        free(used);
        free(newA);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        newA[i] = (double*)malloc(n * sizeof(double));
        if (newA[i] == NULL) {
            for (int k = 0; k < i; k++) free(newA[k]);
            free(newA);
            free(newC);
            free(used);
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int best_row = -1;
        for (int j = 0; j < n; j++) {
            if (used[j]) continue;

            double diag = fabs(A[j][i]);
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                if (k != i) sum += fabs(A[j][k]);
            }

            if (diag >= sum) {
                best_row = j;
                break;
            }
        }

        if (best_row == -1) {
            for (int k = 0; k < n; k++) free(newA[k]);
            free(newA);
            free(newC);
            free(used);
            return 0;  // Başarısız
        }

        used[best_row] = 1;
        for (int k = 0; k < n; k++)
            newA[i][k] = A[best_row][k];
        newC[i] = C[best_row];
    }

    // Eski matrisi yeni düzenlemeyle güncelle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            A[i][j] = newA[i][j];
        C[i] = newC[i];
    }

    for (int i = 0; i < n; i++) free(newA[i]);
    free(newA);
    free(newC);
    free(used);

    return 1;  // Başarılı
}
// 7. Method
void numerical_derivative_method(){
    char* input = (char*)malloc(MAX_EXPRESSION * sizeof(char));
    TOKEN* tokens = (TOKEN*)malloc(MAX_TOKEN * sizeof(TOKEN));
    int token_count = 0, curr = 0;
    double x, h;

    if(input == NULL || tokens == NULL){
        printf("Memory allocation failed.\n");
        free(input);
        return;
    }

    printf("\n[NUMERICAL DERIVATIVE]\nEnter the function (exp: x^2 + sin(x)):\n> ");

    fgets(input, MAX_EXPRESSION, stdin);
    input[strcspn(input, "\n")] = 0;

    if(Tokenizer(input, tokens, &token_count)){
        printf("Tokenize error.\n");
        free_tokens(tokens,token_count);
        free(input);
        return;
    }
    InsertImplicitMultiplications(tokens, &token_count);

    curr = 0;
    NODE* func = parse_expression(tokens, &curr);
    if(curr != token_count){
        printf("Parse error: remaining token '%s'\n", tokens[curr].value);
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    printf("Enter the point x at which to compute derivative: ");
    scanf("%lf", &x);
    printf("Enter the step size h: ");
    scanf("%lf", &h);

    if(h <= 0){
        printf("h must be greater than 0.\n");
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    double fx = evaluate(func, x);
    double fx_plus_h = evaluate(func, x + h);
    double fx_minus_h = evaluate(func, x - h);

    double forward_diff = (fx_plus_h - fx) / h;
    double backward_diff = (fx - fx_minus_h) / h;
    double central_diff = (fx_plus_h - fx_minus_h) / (2 * h);

    printf("Forward Difference   = %.5lf\n", forward_diff);
    printf("Backward Difference  = %.5lf\n", backward_diff);
    printf("Central Difference   = %.5lf\n", central_diff);

    free_tokens(tokens, token_count);
    free_node(func);
    free(input);
}
// 8. Method
void simpson_method(){
    char* input = (char*)malloc(MAX_EXPRESSION * sizeof(char));
    TOKEN* tokens = (TOKEN*)malloc(MAX_TOKEN * sizeof(TOKEN));
    int token_count = 0, curr = 0;
    double a, b;
    int n;
    int ch;

    if(input == NULL || tokens == NULL){
        printf("Memory allocation failed.\n");
        free(input);
        return;
    }

    printf("\n[SIMPSON METHOD]\nEnter the function (exp: x^2 + sin(x)):\n> ");

    fgets(input, MAX_EXPRESSION, stdin);
    input[strcspn(input, "\n")] = 0;

    if(Tokenizer(input, tokens, &token_count)){
        printf("Tokenize error.\n");
        free_tokens(tokens,token_count);
        free(input);
        return;
    }
    InsertImplicitMultiplications(tokens, &token_count);

    curr = 0;
    NODE* func = parse_expression(tokens, &curr);
    if(curr != token_count){
        printf("Parse error: remaining token '%s'\n", tokens[curr].value);
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    printf("Enter lower limit a: ");
    scanf("%lf", &a);
    printf("Enter upper limit b: ");
    scanf("%lf", &b);
    printf("Enter number of n: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Number of n must be positive.\n");
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    double h = (b - a) / n;
    // Simpson 1/3
    if (n % 2 == 0) {
        printf("SIMPSON 1/3\n");
        printf("  i\t  x\t\tf(x)\n");
        printf("--------------------------------------");
        printf("%3d %12.6lf %12.6lf\n", 0, a, evaluate(func, a));
        double result_1_3 = evaluate(func, a) + evaluate(func, b);
        int i;
        for(i = 1; i < n; i++){
            double x = a + i * h;
            double fx = evaluate(func,x);
            if(i % 2 == 0)
                result_1_3 += 2 * fx;
            else
                result_1_3 += 4 * fx;
            printf("%3d %12.6lf %12.6lf\n", i, x, fx);
        }
        result_1_3 *= h / 3;

        printf("%3d %12.6lf %12.6lf\n", i, b, evaluate(func, b));
        printf("Simpson 1/3 Rule Result: %.8lf\n", result_1_3);
    } 
    else
        printf("\nSimpson 1/3 rule requires even n. Skipping 1/3 rule.\n");

    // Simpson 3/8
    if (n % 3 == 0) {
        printf("SIMPSON 3/8");
        printf("\t i\t   x\t\tf(x)\n");
        printf("%3d %12.6lf %12.6lf\n", 0, a, evaluate(func, a));
        double result_3_8 = evaluate(func, a) + evaluate(func, b);
        int i;
        for(i = 1; i < n; i++){
            double x = a + i * h;
            double fx = evaluate(func, x);
            if(i % 3 == 0)
                result_3_8 += 2 * fx;  
            else
                result_3_8 += 3 * fx;
            printf("%3d %12.6lf %12.6lf\n", i, x, fx);
        }
        result_3_8 *= (3 * h) / 8;

        printf("%3d %12.6lf %12.6lf\n", i, b, evaluate(func, b));
        printf("Simpson 3/8 Rule Result: %.8lf\n", result_3_8);
    } 
    else
        printf("Simpson 3/8 rule requires n to be divisible by 3. Skipping 3/8 rule.\n");

    free_tokens(tokens, token_count);
    free_node(func);
    free(input);
}
// 9. Method
void trapez_method(){
    char* input = (char*)malloc(MAX_EXPRESSION * sizeof(char));
    TOKEN* tokens = (TOKEN*)malloc(MAX_TOKEN * sizeof(TOKEN));
    int token_count = 0, curr = 0;
    double a, b;
    int i,n;

    if(input == NULL || tokens == NULL){
        printf("Memory allocation failed.\n");
        free(input);
        return;
    }

    printf("\n[TRAPEZ METHOD]\nEnter the function (exp: x^2 + sin(x)):\n> ");

    fgets(input, MAX_EXPRESSION, stdin);
    input[strcspn(input, "\n")] = 0;

    if(Tokenizer(input, tokens, &token_count)){
        printf("Tokenize error.\n");
        free_tokens(tokens,token_count);
        free(input);
        return;
    }
    InsertImplicitMultiplications(tokens, &token_count);

    curr = 0;
    NODE* func = parse_expression(tokens, &curr);
    if(curr != token_count){
        printf("Parse error: remaining token '%s'\n", tokens[curr].value);
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the number of n: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Number of n must be positive.\n");
        free_tokens(tokens, token_count);
        free_node(func);
        free(input);
        return;
    }
    double h = (b - a) / n;
    double sum = evaluate(func, a) + evaluate(func, b);
    for(i = 1; i < n; i++){
        double x = a + i * h;
        sum += 2 * evaluate(func, x);
    }
    double result = (h / 2) * sum;

    printf("\nApproximate integral of f(x) from %.3lf to %.3lf is: %.5lf\n", a, b, result);

    free_tokens(tokens, token_count);
    free_node(func);
    free(input);
}
// 10. Method
void gregory_newton_method(){
    int n;
    printf("\n[GREGORY-NEWTON INTERPOLATION]\n");
    printf("Enter the number of datas:");
    scanf("%d",&n);

    double* x_vals = (double*)malloc(sizeof(double)*n);
    double* fx_vals = (double*)malloc(sizeof(double)*n);
    if(x_vals == NULL || fx_vals == NULL){
        printf("Memory allocation failed.\n");
        free(x_vals);
        free(fx_vals);
        return;
    }
    char dec;
    int i,k,j;  // i -> number of rows
    // x values
    printf("Enter x values (equal spacing required):\n");
    for(i=0;i<n;i++){
        printf("x[%d]: ", i);
        scanf("%lf", &x_vals[i]);
    }
    // equal spacing check
    double h = x_vals[1] - x_vals[0];
    for(k=0;k<n-1;k++){
        if(fabs((x_vals[k+1] - x_vals[k]) - h) > 0.000001){
            printf("Error: x values are not equally spaced.\n");
            free(x_vals);
            free(fx_vals);
            return;
        }
    }
    // create diff matrix
    double** diff = (double**)calloc(n, sizeof(double*));
    if(diff == NULL){
        printf("Memory allocation failed.\n");
        free(x_vals);
        free(fx_vals);
        return;
    }
    for(k=0;k<n;k++){
        diff[k] = (double*)calloc(n, sizeof(double));
        if(diff[k] == NULL){
            for(i=0; i<k; i++) free(diff[i]);
            free(diff);
            free(x_vals);
            free(fx_vals);
            printf("Memory allocation failed.\n");
            return;
        }
    }
    // fx values
    printf("Enter fx values:\n");
    for(j=0;j<n;j++){
        printf("fx[%d]: ", j);
        scanf("%lf", &fx_vals[j]);
        diff[j][0] = fx_vals[j];
    }
    // difference matrix
    for(k=1;k<n;k++){
        printf("Forward Difference^%d -> ", k);
        for(j=0;j<(n-k);j++){
            diff[j][k] = diff[j+1][k-1] - diff[j][k-1];
            printf("%.6lf  ",diff[j][k]);
        }
        printf("\n");
    }
    // polynomial equation
    printf("\nInterpolating polynomial:\n");
    printf("f(x) = %.1lf", fx_vals[0]);
    for(j=1;j<n;j++){
        if(diff[0][j] != 0){
            printf(" + (%.1lf / (%d!*%.1lf^%d))", diff[0][j], j, h, j);
            for(k=0;k<j;k++){
                printf("*(x - %.1lf)", x_vals[k]);
            }
            printf("\n");
        }
    }
    // calculate interpolation
    printf("\nDo you want to calculate interpolation for any given x value?(Y/N)");
    getchar();
    scanf("%c",&dec);
    if(dec == 'y' || dec == 'Y'){
        double x;
        double result = fx_vals[0];
        double term = 1;
        int fact = 1;
        printf("Enter x to estimate f(x): ");
        scanf("%lf", &x);
        double u = (x - x_vals[0]) / h;
        for(j=1;j<n;j++){
            term *= (u - (j - 1));
            fact *= j;
            result += (term / fact) * diff[0][j];
        }
        printf("\n\nEstimated f(%.5lf) = %.10lf\n", x, result);
    }
    free(x_vals);
    free(fx_vals);
    for (i = 0; i < n; i++) {
        free(diff[i]);
    }
    free(diff);
}