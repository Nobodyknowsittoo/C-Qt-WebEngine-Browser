#include <QApplication>
#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QIcon>
#include <QUrl>
#include <QObject>
#include <QtWebEngineWidgets/QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;

    QWebEngineView *view = new QWebEngineView(&window);
    view->setUrl(QUrl("https://www.qt.io"));
    window.setCentralWidget(view);

    QToolBar *navtb = new QToolBar("Navigation", &window);
    window.addToolBar(navtb);

    QAction *back_btn = new QAction(QIcon("back.png"), "Back", &window);

    QObject::connect(back_btn, &QAction::triggered, view, &QWebEngineView::back);
    navtb->addAction(back_btn);

    window.resize(1024, 768);
    window.show();

    return app.exec();
}
