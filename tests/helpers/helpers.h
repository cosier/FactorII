#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <factorii/ui/colors.h>
#include <stdio.h>

void test_run(char *name, void (*func)(void));
void test_header(char *name);
void test_footer(char *name);

#endif
