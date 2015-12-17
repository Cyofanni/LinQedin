#include "../headers/profilo.h"


Profilo::Profilo(const QString& n/*nome*/,const QString& c/*cognome*/,const Username& u,const TipoAccount& t,const QList<QString>& s/*skills*/,
                 const QList<QString>& l/*lingue*/,const QList<QString>& u1/*università*/,
                 const QList<Username>& c1/*contatti*/,const QString& p): infos(n,c,u,t,s,l,u1,c1,p) {}

QString Profilo::getNome() const{
    return infos.nome;
}

QString Profilo::getCognome() const{
    return infos.cognome;
}

Username Profilo::getUsername() const{
    return infos.uname;
}

TipoAccount Profilo::getTipoAccount() const{
    return infos.tAcc;
}

QString Profilo::getTipoAccountAsString() const{
    QString tAccAsString;
    switch(infos.tAcc){
    case basic:
        tAccAsString = "Basic";
        break;
    case business:
        tAccAsString = "Business";
        break;
    case executive:
        tAccAsString = "Executive";
        break;
    }

    return tAccAsString;
}

QList<QString> Profilo::getSkills() const{
    return infos.skills;
}

QList<QString> Profilo::getLingue() const{
    return infos.lingue;
}

QList<QString> Profilo::getStudi() const{
    return infos.studi;
}

QList<Username> Profilo::getContatti() const{
    return infos.contatti;
}

QString Profilo::getPassword() const{
    return infos.password;
}

void Profilo::setTipoAccount(const TipoAccount& t){
    infos.tAcc = t;
}

QString Profilo::getSkillsAsString() const{
    QString sk;    //contiene la lista di skills come stringa con virgole separatrici
    for (int i = 0; i < (infos.skills).size(); ++i){
       sk.append((infos.skills).at(i));
       if (i < (infos.skills).size() - 1){
           sk.append(",");
       }
    }

    return sk;
}

QString Profilo::getLingueAsString() const{
    QString li;    //contiene la lista di skills come stringa con virgole separatrici
    for (int i = 0; i < (infos.lingue).size(); ++i){
       li.append((infos.lingue).at(i));
       if (i < (infos.lingue).size() - 1){
           li.append(",");
       }
    }

    return li;
}

QString Profilo::getStudiAsString() const{
    QString st;    //contiene la lista di skills come stringa con virgole separatrici
    for (int i = 0; i < (infos.studi).size(); ++i){
       st.append((infos.studi).at(i));
       if (i < (infos.studi).size() - 1){
           st.append(",");
       }
    }

    return st;
}

QString Profilo::getContattiAsString() const{
    QString co;    //contiene la lista di skills come stringa con virgole separatrici
    for (int i = 0; i < (infos.contatti).size(); ++i){
       co.append(((infos.contatti).at(i)).getUsernameAsQString());
       if (i < (infos.contatti).size() - 1){
          if ((infos.contatti).size() > 1){ 
				co.append(",");
		  }
       }
    }
    
    return co;
}

/*Metodo utilizzato (indirettamente da ClientWidget),riceve i dati dal textEdit "editMyProfilo"
 * al client non è permesso né modificare la tipologia del proprio account,né il proprio Username,
 * inoltre la rete viene modificata tramite i bottoni add e remove
*/
void Profilo::modificaProfilo(const QString& n/*nome*/,const QString&/*cognome*/c,
                              const QList<QString>& s/*skills*/,
                              const QList<QString>& l/*lingue*/,const QList<QString>& s1/*studi*/){
    infos.nome = n;
    infos.cognome = c;
    infos.skills = s;
    infos.lingue = l;
    infos.studi = s1;
}

void Profilo::addContattoText(const Username& u){
    (infos.contatti).push_back(u.getUsernameAsQString());
}

void Profilo::removeContattoText(const Username& u){
    int pos;
    for (int i = 0; i < (infos.contatti).size(); ++i){
        if ((infos.contatti).at(i) == u){   //#####
            pos = i;
            break;
        }
    }
    (infos.contatti).removeAt(pos);    //rimuove contatto con Username u
}

void Profilo::visualizzaProfilo(QTextEdit* show,QLineEdit** show1) const{
    QFont f("Arial",13);
    if (show){
		show->setText(/*"Nome: "*/"<font color=green>Nome: </font>" + infos.nome + "<br/><br/>" + "<font color=green>Cognome: </font>" + infos.cognome + "<br/><br/>"
         + "<font color=green>Username: </font>" + (infos.uname).getUsernameAsQString() + "<br/><br/>" + "<font color=green>Tipo account: </font>" +
                  getTipoAccountAsString() + "<br/><br/>"
          + "<font color=green>Skills: </font>" + getSkillsAsString() + "<br/><br/>" + "<font color=green>Lingue: </font>" + getLingueAsString() + "<br/><br/>"
          + "<font color=green>Studi: </font>" + getStudiAsString() + "<br/><br/>" + "<font color=green>Contatti: </font>" + getContattiAsString());
		show->setFont(f);
		show->setReadOnly(true);
	}
	else if (show1){
		/*show->setText("<br/>" + infos.nome + "<br/><br/><br/>" + infos.cognome + "<br/><br/><br/>"
         + (infos.uname).getUsernameAsQString() + "<br/><br/><br/><br/>" +
                  getTipoAccountAsString() + "<br/><br/><br/><br/>"
          + getSkillsAsString() + "<br/><br/><br/>" + getLingueAsString() + "<br/><br/><br/><br/>"
          + getStudiAsString() + "<br/><br/><br/>" + getContattiAsString());
		show->setFont(f);*/
		show1[0]->setText(infos.nome);
		show1[1]->setText(infos.cognome);
		show1[2]->setText((infos.uname).getUsernameAsQString());
		show1[2]->setReadOnly(true);
		show1[3]->setText(getTipoAccountAsString());
		show1[3]->setReadOnly(true);
		show1[4]->setText(getSkillsAsString());
		show1[5]->setText(getLingueAsString());
		show1[6]->setText(getStudiAsString());
		show1[7]->setText(getContattiAsString());
		show1[7]->setReadOnly(true);
	}
}
