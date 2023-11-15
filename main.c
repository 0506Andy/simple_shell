#include "main.h"
#define MAX_INPUT_SIZE 1024

void run_shell(void)
{
	char input[MAX_INPUT_SIZE];
	while (1)
	{
		_putchar('M');
		_putchar('y');
		_putchar('S');
		_putchar('h');
		_putchar('e');
		_putchar('l');
		_putchar('l');
		_putchar('>');
		_putchar(' ');
		
		fgets(input, MAX_INPUT_SIZE, stdin);
		
		input[_strcspn(input, "\n")] = '\0';
		
		if (myStrcmp(input, "exit") == 0)
		{
			exit_builtin();
		}
		else if (myStrcmp(input, "env") == 0)
		{
			env_builtin();
		}
		else (myStrcmp(input, "comd") == 0)
		{
			handle_path();
		}
    }
}

int main() {
    run_shell();
    return 0;
}

