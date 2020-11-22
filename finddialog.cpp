#include "finddialog.h"
#include "abonnee.h"
FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    id_rech_abonne_2 *findLabel = new QLabel(tr("Enter the name of a contact:"));
    lineEdit = new QLineEdit;

    findButton = new QPushButton(tr("&Find"));
    findText = "";

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(findLabel);
    layout->addWidget(lineEdit);
    layout->addWidget(findButton);

    setLayout(layout);
    setWindowTitle(tr("Find a Contact"));
    connect(findButton, &QPushButton::clicked,
            this, &FindDialog::findClicked);
    connect(findButton, &QPushButton::clicked,
            this, &FindDialog::accept);
}
