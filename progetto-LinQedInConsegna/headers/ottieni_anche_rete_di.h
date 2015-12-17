#ifndef OTTIENI_ANCHE_RETE_DI_H
#define OTTIENI_ANCHE_RETE_DI_H

#include "profilo_completo_di.h"

class OttieniAncheReteDi: public ProfiloCompletoDi{  //Funtore per servizio Executive: permette inoltre di ottenere anche la rete dei contatti di un utente
    public:
        InfoVis_Executive* operator () (const Profilo&,QTextEdit*) const;
};

#endif // OTTIENI_ANCHE_RETE_DI_H
