#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>

void test_debug(void);
void test_log_err(void);
void test_log_warn(void);
void test_log_info(void);
int test_check(char *file_name);
int test_sentinel(int code);
int test_check_mem(void);
int test_check_debug(void);

int main(int argc, char **argv)
{
	check(argc == 2, "Need an argument.");

	test_debug();
	test_log_err();
	test_log_warn();
	test_log_info();

	check(test_check("ex16.1.c") == 0, "Failed with ex16.1.c");
	check(test_check(argv[1]) == -1, "Failed with argv");
	check(test_sentinel(1) == 0, "test_sentinel failed.");
	check(test_sentinel(100) == -1, "test_sentinel failed.");
	check(test_check_mem() == -1, "test_check_mem failed.");
	check(test_check_debug() == -1, "test_check_debug failed.");

	return 0;
error:
	return -1;
}

void test_debug(void)
{
	debug("I have blone hair.");
	debug("I am %d yesrs old.", 23);
}

void test_log_err(void)
{
	log_err("I believe everything is broken.");
	log_err("There are %d problems in %s.", 0, "space");
}

void test_log_warn(void)
{
	log_warn("You can safely ignore this.");
	log_err("Maybe consider looking at: %s.", "/etc/passwd");
}

void test_log_info(void)
{
	log_info("Well I did something mundane.");
	log_warn("It happened %f times today.", 1.3f);
}

int test_check(char *file_name)
{
	FILE *input = NULL;
	char *block = NULL;

	block = malloc(100);
	check_mem(block);

	input = fopen(file_name, "r");
	check(input, "Failed to open %s.", file_name);

	free(block);
	fclose(input);
	return 0;

error:
	if (block) free(block);
	if (input) fclose(input);
	return -1;
}

int test_sentinel(int code)
{
	char *temp = malloc(100);
	check_mem(temp);

	switch (code) {
		case 1:
			log_info("It worked.");
			break;
		default:
			sentinel("I shouldn't run.");
	}

	free(temp);
	return 0;

error:
	if (temp)
		free(temp);
	return -1;
}
int test_check_mem(void)
{
	char *test = NULL;
	check_mem(test);

	free(test);
	return 1;

error:
	return -1;
}

int test_check_debug(void)
{
	int i = 0;
	check_debug(i != 0, "Oops, I was 0.");

	return 0;
error:
	return -1;
}
