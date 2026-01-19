//including necessary libarys
#include <QApplication>
#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QIcon>
#include <QUrl>
#include <QObject>
#include <QtWebEngineWidgets/QWebEngineView>

//main function
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;

    QWebEngineView *view = new QWebEngineView(&window);
    view->setUrl(QUrl("https://www.qt.io"));
    window.setCentralWidget(view);

    //adding Toolbar
    QToolBar *navtb = new QToolBar("Navigation", &window);
    navtb->setMovable(false); 
    window.addToolBar(navtb);

    //initializing navigationButtons
    QAction *back_btn = new QAction("←", &window);
    QAction *forward_btn = new QAction("→", &window);
    QAction *reload_btn = new QAction("↻", &window);

    //connecting navigationButtons and adding them to the navbar
    QObject::connect(back_btn, &QAction::triggered, view, &QWebEngineView::back);
    navtb->addAction(back_btn);

    QObject::connect(forward_btn, &QAction::triggered, view, &QWebEngineView::forward);
    navtb->addAction(forward_btn);

    QObject::connect(reload_btn, &QAction::triggered, view, &QWebEngineView::reload);
    navtb->addAction(reload_btn);

    //window init
    window.resize(1024, 768);
    window.show();

    return app.exec();
}
