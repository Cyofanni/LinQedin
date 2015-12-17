#include "../headers/profilo_completo_di.h"

InfoVis_Business* ProfiloCompletoDi::operator()(const Profilo& p,QTextEdit* qed) const{
    return new InfoVis_Business(p,qed);
}
