#ifndef DIALOGINFO_H
#define DIALOGINFO_H

#include <QWidget>
#include <QDateTime>
#include <QUrl>
#include <QMouseEvent>
#include <QJsonDocument>
#include "ui_dialoginfo.h"
#include "session.h"
#include <windows.h>
#include "vkdatareceiver.h"
#include "abstractmessage.h"
#include "textmessage.h"
#include "stickermessage.h"

#define WIDTH  260
#define HEIGHT 100
#define MESSAGES_COUNT 100
#define GROUP_AVATAR_PATH "./Application Resources/group_avatar.png"

enum DialogType { PERSONAL, CHAT };


class DialogInfo : public QWidget
{
	Q_OBJECT

public:
	DialogInfo(	DialogType type, 
				unsigned int id, unsigned int messageId,
				QString &title,QString &lastMessage,
				QDateTime &lastMessageDateTime, bool out);
	~DialogInfo();
	DialogInfo & operator=(const DialogInfo &other);

	void loadOpponentInfo();
	void loadOpponentPhoto(QString photoUrl);
	void loadMessages();
	void addMessage(const QString &fromId, const QString &text);

	QString getId() const;
	void setLastMessage(const QString &text);

signals:
	void messagesLoaded(QWidget *scrollWidget, QString &username);

private:
	void setConnections();
	void setDataToWidgets();
	void parseMessages(const QByteArray &messages);
	void paintFrameRed();
	void paintFrameWhite();
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

	Ui::DialogInfo ui;
	unsigned int id;
	unsigned int messageId;
	QString title;
	QString username;
	QString lastMessage;
	QDateTime lastMessageDateTime;
	QByteArray photo;
	bool out;
	bool clicked;
	bool initialized;

	DialogType dialogType;
	VKDataReceiver *dataReceiver;
	QList<AbstractMessage *> userMessages;
	QWidget *messagesScrollWidget;
};

#endif // DIALOGINFO_H
