# include "pr01ej02a.h"

struct _rep_info
{
    unsigned int n;
    double r;
};

TInfo crearInfo(unsigned int natural, double real)
{
    TInfo info = new _rep_info;
    info->n = natural;
    info->r = real;
    return info;
}

unsigned int natInfo(TInfo info)
{
    return info->n;
}

double realInfo(TInfo info)
{
    return info->r;
}
