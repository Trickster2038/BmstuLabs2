/********************************************************************************
** Form generated from reading UI file 'ex2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EX2_H
#define UI_EX2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogEx2
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout;
    QDial *dial;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogEx2)
    {
        if (DialogEx2->objectName().isEmpty())
            DialogEx2->setObjectName(QString::fromUtf8("DialogEx2"));
        DialogEx2->resize(424, 300);
        verticalLayout_2 = new QVBoxLayout(DialogEx2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        textEdit = new QTextEdit(DialogEx2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_2->addWidget(textEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dial = new QDial(DialogEx2);
        dial->setObjectName(QString::fromUtf8("dial"));

        verticalLayout->addWidget(dial);

        spinBox = new QSpinBox(DialogEx2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        verticalLayout->addWidget(spinBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(DialogEx2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(DialogEx2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(DialogEx2);
        QObject::connect(dial, SIGNAL(sliderMoved(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), DialogEx2, SLOT(reject()));
        QObject::connect(spinBox, SIGNAL(valueChanged(QString)), textEdit, SLOT(append(QString)));

        QMetaObject::connectSlotsByName(DialogEx2);
    } // setupUi

    void retranslateUi(QDialog *DialogEx2)
    {
        DialogEx2->setWindowTitle(QCoreApplication::translate("DialogEx2", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogEx2", "push button ->", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogEx2", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEx2: public Ui_DialogEx2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EX2_H
