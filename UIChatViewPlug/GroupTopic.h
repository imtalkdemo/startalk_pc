﻿#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef _GROUPTOPIC_H_
#define _GROUPTOPIC_H_

#include <QFrame>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

class GroupTopic : public QFrame
{
	Q_OBJECT
public:
	explicit GroupTopic(QWidget* parent = nullptr);
	~GroupTopic() override;

public:
	void setTopic(const QString& topic);

protected:
	void initUi();
    bool eventFilter(QObject *, QEvent *) override;

private:
	QTextEdit*   _pTopicEdit;
	QPushButton* _pBtnShowMore;
};

#endif//_GROUPTOPIC_H_