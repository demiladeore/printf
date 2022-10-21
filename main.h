#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/*put*/
int _putchar(int c);

/* specifier.c module */
int (*get_specifier(char *s))(va_list args, params_t *params);
int get_print_func(char *s, va_list args, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list args);


/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);


/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c modoule */
char *get_precision(char *p, params_t *params, va_list args);

/* _prinf.c module */
int _printf(const char *format, ...);
/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2
/**
 * struct buffer_s - A new type defining a buffer struct
 * @buffer: A pointer to a character array
 * @start: A pointer to start the buffer
 * @len: the length of the string
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct converter_s - A new type defining a converter
 * @specifier: A character
 * @func: A pointer to a conversion function
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *, unsigned char, int, int, unsigned char);
} converter_t;

/**
 * struct flag_s - A new type defining a flags struct
 * @flag: A character representing a flag
 * @value: the integer value of the flag
 */

typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

/* conversion specifier functions */
unsigned int convert_c(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_s(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_di(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_precent(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_b(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_u(va_list args, buffe_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_o(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned cahr len);
unsigned int convert_x(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_X(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_S(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_p(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_r(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_R(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);

/* Handlers */
unsigned char handle_flags(const char *flags, char *index);
unsigned char handle_length(const char *modifier, char *index);
int handle_width(va_list args, const char *modifier, char *index);
int handle_precision(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *, unsigned char, int, int, unsigned char);

/* Modifiers */
unsigned int print_width(buffer_t *output, unsigned int printed, unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output, unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed, unsigned char flags, int wid);

/* Helper Functions */
buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
unsigned int convert_sbase(buffer_t *output, long int num, char *base, unsigned char flags, int wid, int prec);
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base, unsigned char flags, int wid, int prec);

#endif /*_MAIN_H_*/
