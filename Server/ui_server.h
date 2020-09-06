/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblImgElapsed;
    QLabel *lblNetElapsed;
    QLabel *lblFps;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(345, 262);
        centralWidget = new QWidget(Server);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblImgElapsed = new QLabel(centralWidget);
        lblImgElapsed->setObjectName(QStringLiteral("lblImgElapsed"));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        lblImgElapsed->setFont(font);
        lblImgElapsed->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblImgElapsed);

        lblNetElapsed = new QLabel(centralWidget);
        lblNetElapsed->setObjectName(QStringLiteral("lblNetElapsed"));
        lblNetElapsed->setFont(font);
        lblNetElapsed->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblNetElapsed);

        lblFps = new QLabel(centralWidget);
        lblFps->setObjectName(QStringLiteral("lblFps"));
        lblFps->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblFps);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Server->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Server);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 345, 21));
        Server->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Server);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Server->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Server);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Server->setStatusBar(statusBar);

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QMainWindow *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", Q_NULLPTR));
        lblImgElapsed->setText(QApplication::translate("Server", "Image generate in 0 us", Q_NULLPTR));
        lblNetElapsed->setText(QApplication::translate("Server", "Data sent in 0 us", Q_NULLPTR));
        lblFps->setText(QApplication::translate("Server", "FPS 0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
