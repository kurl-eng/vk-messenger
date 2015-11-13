#ifndef USERTEXTMESSAGE_H
#define USERTEXTMESSAGE_H

#include "ui_textmessage.h"
#include "abstractmessage.h"

class TextMessage : public AbstractMessage
{
	Q_OBJECT

public:
	TextMessage(const QString &message, const QByteArray &photo);
	TextMessage(const TextMessage &other);
	~TextMessage();

	/* ���������� ������ � ������ */
	virtual void setDataToWidgets(bool out);
	
	/* ������������ ������ ������ */
	virtual TextMessage * clone() const;

private:
	Ui::UserTextMessage ui;
	QString message;
};

#endif // USERTEXTMESSAGE_H
