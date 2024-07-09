#include <QCoreApplication>
#include "client_test.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    client_test mTest;
    mTest.test();
    return a.exec();
}
