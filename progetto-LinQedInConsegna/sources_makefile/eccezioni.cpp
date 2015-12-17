#include "../headers/eccezioni.h"

OutputMessage::OutputMessage(const QString& msg){
	QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}
