#include <QCoreApplication>
#include "server_test.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    server_test mserver;
    return a.exec();
}
