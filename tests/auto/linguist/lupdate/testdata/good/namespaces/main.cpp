/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the test suite of the Qt Toolkit.
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

#include <QtCore>

class Class : public QObject
{
    Q_OBJECT

    class SubClass
    {
        void f()
        {
            tr("nested class context");
        }
    };

    void f()
    {
        tr("just class context");
    }
};

namespace Outer {

class Class : public QObject { Q_OBJECT };

namespace Middle1 {

class Class : public QObject { Q_OBJECT };

namespace Inner1 {

class Class : public QObject { Q_OBJECT };

}

namespace I = Inner1;

class Something;
class Different;

}

namespace Middle2 {

class Class : public QObject { Q_OBJECT };

namespace Inner2 {

class Class : public QObject { Q_OBJECT };

namespace IO = Middle2;

}

namespace I = Inner2;

}

namespace MI = Middle1::Inner1;

namespace O = ::Outer;

class Middle1::Different : QObject {
Q_OBJECT
    void f() {
        tr("different namespaced class def");
    }
};

}

namespace O = Outer;
namespace OM = Outer::Middle1;
namespace OMI = Outer::Middle1::I;

int main()
{
    Class::tr("outestmost class");
    Outer::Class::tr("outer class");
    Outer::MI::Class::tr("innermost one");
    OMI::Class::tr("innermost two");
    O::Middle1::I::Class::tr("innermost three");
    O::Middle2::I::Class::tr("innermost three b");
    OM::I::Class::tr("innermost four");
    return 0;
}

class OM::Something : QObject {
Q_OBJECT
    void f() {
        tr("namespaced class def");
    }
    void g() {
        tr("namespaced class def 2");
    }
};

#include "main.moc"
