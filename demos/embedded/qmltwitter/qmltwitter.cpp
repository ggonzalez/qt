/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtCore/QFileInfo>
#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeEngine>

#if defined(Q_OS_SYMBIAN)
#include <QtCore/QTextCodec>
#include <QtCore/QTimer>
#include "sym_iap_util.h"

class QmlAppView : public QDeclarativeView
{
Q_OBJECT
public:
    QmlAppView(QWidget *parent = 0)
        : QDeclarativeView(parent)
    {
        QTimer::singleShot(0, this, SLOT(setDefaultIap()));
    }

private slots:
    void setDefaultIap()
    {
        qt_SetDefaultIap();
    }
};
#else // Q_OS_SYMBIAN
typedef QDeclarativeView QmlAppView;
#endif // Q_OS_SYMBIAN

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    const QString mainQmlApp = QLatin1String("twitter.qml");
    QmlAppView view;
    view.setSource(QUrl(mainQmlApp));
    view.setResizeMode(QDeclarativeView::SizeRootObjectToView);

#if defined(Q_OS_SYMBIAN)
    view.showFullScreen();
#else // Q_OS_SYMBIAN
    view.setGeometry(QRect(100, 100, 360, 640));
    view.show();
#endif // Q_OS_SYMBIAN
    return application.exec();
}

#if defined(Q_OS_SYMBIAN)
#include "qmltwitter.moc"
#endif // Q_OS_SYMBIAN