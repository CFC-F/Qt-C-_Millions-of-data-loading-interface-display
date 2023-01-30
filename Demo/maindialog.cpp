#include "maindialog.h"
#include "delegate.h"
#include "model.h"

MainDialog::MainDialog(QWidget *parent) : QDialog(parent), 
    //ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model_ = new Model(this);

    Delegate *delegate = new Delegate(this);

    ui->tableView->setItemDelegateForColumn(OperationColumn, delegate);
    ui->tableView->setModel(model_);
}

Dialog::~Dialog()
{
    delete ui;
}