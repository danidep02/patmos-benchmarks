/* MDH WCET BENCHMARK SUITE.
 * Benchmark: fdct
 * File: fdct-test.c
 * Version: 1.0
 */
/* Compilation
 *   $(CC) $(DEFS) -o fdct.bin fdct-test.c fdct.o
 * DEFS
 *   TEST_PRINT_RESULTS     ... write test result to stdout
 *   TEST_PRINT_VERSION     ... print version of benchmark
 *   TEST_NO_RUNTIME_CHECK  ... do not check test result at runtime
 */

#ifdef TEST_PRINT_VERSION
#include <stdio.h>
static void print_version()
{
    puts("fdct v1.0");
}
#endif /* TEST_PRINT_VERSION */

#ifdef TEST_PRINT_RESULTS
#include <stdio.h>
/**
 * Generate reference output.
 */
static void dump_result(int in, int out)
{
  printf("in: %d, out: %d\n", in, out);
}
#else /* TEST_PRINT_RESULTS */
#define dump_result(in,out) do { (void) in; } while(0)
#endif /* TEST_PRINT_RESULTS */

#ifndef TEST_NO_RUNTIME_CHECK
#define CHECK(out,ref) ((out)==(ref))
#else /* TEST_NO_RUNTIME_CHECK */
#define CHECK(out,ref) 1 /* ok */
#endif /* TEST_NO_RUNTIME_CHECK */

static int process_result(int in, int out, int ref)
{
  dump_result(in,out);
  return CHECK(out,ref);
}

/* external declarations */
int main_test(int seed);

/* test cases */
static int tests_in[]  = { 0, 12, 57, 113 };
static int tests_ref[] = { 699, 1019, 835, 737 };

static int test_case(int in, int ref)
{
  return process_result(in, main_test(in), ref);
}

int main(int argc, char **argv)
{
#ifdef TEST_PRINT_VERSION
  print_version();
#endif
  int ok = 1;
  int i;
  /* perform all tests */
  for(i = 0; i < sizeof(tests_in)/sizeof(tests_in[0]); i++) {
      ok &= test_case(tests_in[i], tests_ref[i]);
  }
  /* exit code 0 if all tests succeeded, otherwise 1 */
  return (ok != 0) ? 0 : 1;
}
