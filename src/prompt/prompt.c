#include <unistd.h>
#include "mosh_prompt.h"

void prompt(void){
	write(1, "> ", 2);
}
