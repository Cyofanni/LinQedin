#ifndef INFOVIS_BUSINESS_H
#define INFOVIS_BUSINESS_H

#include "infovis_basic.h"

class InfoVis_Business: public InfoVis_Basic{  //deve contenere tutto il profilo eccetto la rete
public:
    InfoVis_Business(const Profilo&,QTextEdit*);
};

#endif // INFOVIS_BUSINESS_H
