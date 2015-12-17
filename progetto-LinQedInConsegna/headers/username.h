#ifndef USERNAME_H
#define USERNAME_H

#include <QString>

class Username{
    private:
        QString login;
    public:
        Username(const QString&);
        operator QString();
        QString getUsernameAsQString() const;
        bool operator==(const Username&) const;				//operatore di confronto tra oggetti Username
        bool operator!=(const Username&) const;
};

#endif
