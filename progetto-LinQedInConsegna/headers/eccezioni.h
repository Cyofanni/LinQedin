#ifndef ECCEZIONI_H
#define ECCEZIONI_H

#include <QMessageBox>

class UtenteEsistente{};

class UtenteNonEsistente{};

class UtenteInRete{};

class UtenteNonInRete{};

class OutputMessage{
	public:
		OutputMessage(const QString&);
};

#endif
