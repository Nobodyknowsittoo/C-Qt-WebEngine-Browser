#include <QApplication>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWebEngineView view;
    view.page()->triggerAction(QWebEnginePage::Back);
    view.page()->triggerAction(QWebEnginePage::Forward);
    view.page()->triggerAction(QWebEnginePage::InspectElement);
    view.setUrl(QUrl("https://www.qt.io"));
    view.resize(1024, 768);
    view.show();

    return app.exec();
}
