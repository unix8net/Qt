#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QWidget>

#include <QApplication>

#include <QMenu>
#include <QMouseEvent>
#include <QTreeWidget>
#include <QTreeWidgetItem>

// Qt documentation states that user types should begin at this value.
static const int ItemType1 = QTreeWidgetItem::UserType;
static const int ItemType2 = QTreeWidgetItem::UserType + 1;

class MyTreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    MyTreeWidget()
    {
        setContextMenuPolicy(Qt::CustomContextMenu);

        connect(this,
                SIGNAL(customContextMenuRequested(const QPoint&)),
                SLOT(onCustomContextMenuRequested(const QPoint&)));
    }

private slots:
    void onCustomContextMenuRequested(const QPoint& pos) {
        printf("hi\n");
        QTreeWidgetItem* item = itemAt(pos);

        if (item) {
            // Note: We must map the point to global from the viewport to
            // account for the header.
            showContextMenu(item, viewport()->mapToGlobal(pos));
        }
    }

    void showContextMenu(QTreeWidgetItem* item, const QPoint& globalPos) {
        QMenu menu;

        switch (item->type()) {
            case ItemType1:
                menu.addAction("This is a type 1");
                break;

            case ItemType2:
                menu.addAction("This is a type 2");
                break;
        }

        menu.exec(globalPos);
    }
};
#endif // MYTREEWIDGET_H
