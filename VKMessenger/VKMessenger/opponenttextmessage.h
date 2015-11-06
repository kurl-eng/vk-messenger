#ifndef OPPONENTTEXTMESSAGE_H
#define OPPONENTTEXTMESSAGE_H

#include "ui_opponenttextmessage.h"
#include "abstractmessage.h"

class OpponentTextMessage : public AbstractMessage
{
	Q_OBJECT

public:
	OpponentTextMessage(QString &message, QByteArray &photo);
	~OpponentTextMessage();

	virtual void setDataToWidgets();

private:
	Ui::OpponentTextMessage ui;
};

#endif // OPPONENTTEXTMESSAGE_H
