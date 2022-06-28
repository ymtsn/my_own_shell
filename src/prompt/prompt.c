#include <unistd.h>
#include "mysh_prompt.h"

void prompt(void){
	write(1, "> ", 2);
}
