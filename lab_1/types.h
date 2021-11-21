#ifndef TYPES_H
#define TYPES_H
#define MAX_LEN_MANTISS 30
#define MAX_LEN_ORDER 5
#define MAX_LEN_NUMBER 40
#define LIMIT_MAX_ORDER 99999
#define LIMIT_MIN_ORDER -99999

enum key_error
{
    ok,
    error,
};

struct real
{
    char mantiss_sigh;
    int mantiss[MAX_LEN_MANTISS];
    int order;
};

struct integer
{
    char mantiss_sigh;
    int mantiss[MAX_LEN_MANTISS];
};

struct result
{
    char result_sigh;
    int mantiss[2 * MAX_LEN_MANTISS + 1];
};
#endif // TYPES_H
