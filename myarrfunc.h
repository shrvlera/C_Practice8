#define SIZE 100
#define ERR -1
#define NOT_FOUND -2
#define OK 0

void fill_array(int *arrptr, int n);
void print_array(const int *arrptr, int n);

int find_min_range(const int *arrptr, int n, int k, int m, int *res);
int find_diff_range(const int *arrptr, int n, int k, int m, int *res);
int find_below_k(const int *arrptr, int n, int k, int *idx_arr, int *count);
