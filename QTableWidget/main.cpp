#include <QApplication> 
#include "tabdlg.h" 
 
int main(int argc,char* argv[]) 
{ 
  QApplication app(argc,argv); 
  TabDialog tabdlg("./main.cpp"); 
  tabdlg.show(); 
  return app.exec(); 
} 