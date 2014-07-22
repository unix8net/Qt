#include<QApplication>
#include"MyTableView.h"


int main(int argc,char *argv[])
{
	QApplication app(argc,argv);

	MyTableView * table=new MyTableView;
	table->show();
	return app.exec();
}
