#include "../headers/ottieni_anche_rete_di.h"

InfoVis_Executive* OttieniAncheReteDi::operator()(const Profilo& p,QTextEdit* qed) const{
    return new InfoVis_Executive(p,qed);
}
