#ifndef OTTIENI_INFOS_H
#define OTTIENI_INFOS_H

#include "infovis_executive.h"

class OttieniInfos{				//funtore base astratto
    public:
        virtual InfoVis_Basic* operator() (const Profilo&,QTextEdit*) const = 0;  //metodo virtuale astratta
};

#endif // OTTIENI_INFOS_H
