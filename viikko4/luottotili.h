#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"


class luottoTili : public pankkiTili
{
public:
    luottoTili(string, double);
    ~luottoTili();
    bool withdraw(double) override;
    bool deposit(double) override;

protected:
    double luottoRaja = 0;
};

#endif // LUOTTOTILI_H
