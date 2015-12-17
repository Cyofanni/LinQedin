#ifndef INFOVIS_EXECUTIVE_H
#define INFOVIS_EXECUTIVE_H

#include "infovis_business.h"

class InfoVis_Executive: public InfoVis_Business{   //deve contenere tutto il profilo, anche la rete
public:
    InfoVis_Executive(const Profilo&,QTextEdit*);
};

#endif // INFOVIS_EXECUTIVE_H
