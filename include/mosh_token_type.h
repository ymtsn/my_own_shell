#ifndef MOSH_TOKEN_TYPE_H
#define MOSH_TOKEN_TYPE_H
typedef enum {
	WORD,
	ASSIGNMENT_WORD,
	NAME,
	NEWLINE,
	IO_NUMBER,
	PIPE,
	LESS,		/* '<' */
	GREAT,		/* '>' */
	DLESS,		/* '<<' */
	DGREAT,		/* '>>' */
	LESSAND,	/* '<&' */
	GREATAND	/* '>&' */
} token_type
#endif
