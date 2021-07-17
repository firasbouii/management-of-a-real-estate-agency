/********************************************************************************
** Form generated from reading UI file 'agent.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENT_H
#define UI_AGENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Agent
{
public:

    void setupUi(QWidget *Agent)
    {
        if (Agent->objectName().isEmpty())
            Agent->setObjectName(QString::fromUtf8("Agent"));
        Agent->resize(400, 300);

        retranslateUi(Agent);

        QMetaObject::connectSlotsByName(Agent);
    } // setupUi

    void retranslateUi(QWidget *Agent)
    {
        Agent->setWindowTitle(QCoreApplication::translate("Agent", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Agent: public Ui_Agent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENT_H
