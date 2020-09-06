/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblIp;
    QLineEdit *leIP;
    QLabel *lblPort;
    QLineEdit *lePort;
    QPushButton *btnConnect;
    QLabel *lblNetElapsed;
    QLabel *lblImageInfo;
    QSpacerItem *verticalSpacer;
    QLabel *lblImage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(424, 329);
        centralWidget = new QWidget(Client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblIp = new QLabel(centralWidget);
        lblIp->setObjectName(QStringLiteral("lblIp"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblIp->sizePolicy().hasHeightForWidth());
        lblIp->setSizePolicy(sizePolicy);
        lblIp->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, lblIp);

        leIP = new QLineEdit(centralWidget);
        leIP->setObjectName(QStringLiteral("leIP"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leIP->sizePolicy().hasHeightForWidth());
        leIP->setSizePolicy(sizePolicy1);
        leIP->setMaximumSize(QSize(16777215, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, leIP);

        lblPort = new QLabel(centralWidget);
        lblPort->setObjectName(QStringLiteral("lblPort"));
        sizePolicy.setHeightForWidth(lblPort->sizePolicy().hasHeightForWidth());
        lblPort->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, lblPort);

        lePort = new QLineEdit(centralWidget);
        lePort->setObjectName(QStringLiteral("lePort"));
        sizePolicy1.setHeightForWidth(lePort->sizePolicy().hasHeightForWidth());
        lePort->setSizePolicy(sizePolicy1);
        lePort->setMaximumSize(QSize(16777215, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, lePort);

        btnConnect = new QPushButton(centralWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnConnect->sizePolicy().hasHeightForWidth());
        btnConnect->setSizePolicy(sizePolicy2);
        btnConnect->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, btnConnect);


        verticalLayout->addLayout(formLayout);

        lblNetElapsed = new QLabel(centralWidget);
        lblNetElapsed->setObjectName(QStringLiteral("lblNetElapsed"));
        lblNetElapsed->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblNetElapsed);

        lblImageInfo = new QLabel(centralWidget);
        lblImageInfo->setObjectName(QStringLiteral("lblImageInfo"));
        lblImageInfo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblImageInfo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        lblImage = new QLabel(centralWidget);
        lblImage->setObjectName(QStringLiteral("lblImage"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblImage->sizePolicy().hasHeightForWidth());
        lblImage->setSizePolicy(sizePolicy3);
        lblImage->setMinimumSize(QSize(100, 100));
        lblImage->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(lblImage, 0, 1, 1, 1);

        Client->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Client);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 424, 21));
        Client->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Client);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Client->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Client);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Client->setStatusBar(statusBar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", Q_NULLPTR));
        lblIp->setText(QApplication::translate("Client", "IP:", Q_NULLPTR));
        leIP->setText(QApplication::translate("Client", "127.0.0.1", Q_NULLPTR));
        lblPort->setText(QApplication::translate("Client", "Port:", Q_NULLPTR));
        lePort->setText(QApplication::translate("Client", "8888", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("Client", "Connect", Q_NULLPTR));
        lblNetElapsed->setText(QApplication::translate("Client", "Data received in 0 us", Q_NULLPTR));
        lblImageInfo->setText(QString());
        lblImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
