#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum ResultType { RT_error, RT_int, RT_float };

struct RetType {
  enum ResultType result_type;
  union {
    int int_result;
    double float_result;
    const char *error_msg;
  };
};

struct RetType int_division(int a, int b) {
  if (b == 0)
    return (struct RetType){.result_type = RT_error,
                            .error_msg = "Division by zero."};
  else {
    if (a % b == 0)
      return (struct RetType){.result_type = RT_int, .int_result = a / b};
    else
      return (struct RetType){.result_type = RT_float,
                              .float_result = (double)a / b};
  }
}

int main(void) {
  int a, b;
  scanf("%d%d", &a, &b);
  struct RetType ret = int_division(a, b);
  if (ret.result_type == RT_error)
    puts(ret.error_msg);
  else if (ret.result_type == RT_int)
    printf("%d\n", ret.int_result);
  else
    printf("%lf\n", ret.float_result);
  return 0;
}