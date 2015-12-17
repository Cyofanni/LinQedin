#include "../headers/infovis_basic.h"

InfoVis_Basic::InfoVis_Basic(const Profilo& p,QTextEdit* qed){
	QFont f("Arial",13);        
	qed->setText("<font color=green>l'utente cercato esiste</font>" + QString("<br/><br/>"));
	qed->setFont(f);
	qed->setReadOnly(true);
}
