#include "mytreewidget.h"
#include <QApplication>



int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyTreeWidget w;
    w.show();

    // Add test items.
    w.addTopLevelItem(new QTreeWidgetItem(QStringList("A (type 1)"),
                                          ItemType1));
    w.addTopLevelItem(new QTreeWidgetItem(QStringList("B (type 1)"),
                                          ItemType1));

    w.addTopLevelItem(new QTreeWidgetItem(QStringList("C (type 2)"),
                                          ItemType2));
    w.addTopLevelItem(new QTreeWidgetItem(QStringList("D (type 2)"),
                                          ItemType2));

    app.exec();
    return 0;
}
