
#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include "model.h"

namespace Ui{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

private:
    ui::MainDialog *ui;

    Model *model_;
}
#endif          //MAINDIALOG_H

/*
#pragma once

class QDialog;

class MainDialog : public QDialog
{
	QOBJECT

public:
	MainDialog(QWidget *parent = 0);
	~MainDialog();

public:
	Init();
};
*/

