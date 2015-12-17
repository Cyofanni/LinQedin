#include "../headers/infovis_business.h"

InfoVis_Business::InfoVis_Business(const Profilo& p,QTextEdit* qed): InfoVis_Basic(p,qed){
        qed->moveCursor(QTextCursor::End);
        qed->insertPlainText("\n"+ QString("Nome: ") +  p.getNome() + "\n" + QString("Cognome: ") + p.getCognome() + "\n"
		+ QString("Username: ") + p.getUsername() + "\n" + QString("Tipo account: ")  
                     + p.getTipoAccountAsString() + "\n" + QString("Skills: ") + p.getSkillsAsString() + "\n" + 
                    QString("Lingue: ") + p.getLingueAsString() + "\n" + QString("Studi: ") + p.getStudiAsString() + "\n");
}
