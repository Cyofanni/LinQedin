#include "../headers/infovis_executive.h"

InfoVis_Executive::InfoVis_Executive(const Profilo& p,QTextEdit* qed): InfoVis_Business(p,qed){
        qed->moveCursor(QTextCursor::End);
        qed->insertPlainText(QString("Contatti: ") + p.getContattiAsString());
}
