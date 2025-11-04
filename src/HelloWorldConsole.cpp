#include <QTextStream>
#include <QtCore/qstring.h>
#include <QtCore/qtextstream.h>

int addnum(int a, int b)
{
    QString name = "Qt";
    QString greeting = QString("Hello, %1!").arg(name);
    QTextStream out(stdout);
    out << greeting << Qt::endl;
    if (a == b) {
        return a*b;
    }
    return a + b;
}

int main() {
  int result = addnum(3, 4);
  auto out = QTextStream {stdout};
  out << "Hello, World!" << Qt::endl;
}

// This code produces the following output :
//
// Hello, World!
