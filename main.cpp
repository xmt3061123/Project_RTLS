#include "RTLSDisplayApplication.h"
#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QStyleFactory>
#include "myhelper.h"

/**
* @brief this is the application main entry point
*
*/
int main(int argc, char *argv[])
{


    RTLSDisplayApplication app(argc, argv);


    QTextCodec * textCodec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForLocale(textCodec);

    //QTranslator translator;
    //translator.load(":/testTranslate/testtranslate_zh.qm");
    //a.installTranslator(&translator);

    QTranslator translator;
    bool b = false;
    b = translator.load(":/tr_en.qm");
    qDebug() << "load:" << b;
    app.installTranslator(&translator);

    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    /* 设置全局风格 */
    //QApplication::setStyle(QStyleFactory::create("fusion"));

    myHelper::SetUTF8Code();
//    myHelper::SetStyle("black");//黑色风格
    myHelper::SetStyle("blue");//蓝色风格
    //myHelper::SetStyle("gray");//灰色风格
    //myHelper::SetStyle("navy");//天蓝色风格
    //myHelper::SetChinese();
    app.mainWindow()->show();


    return app.QApplication::exec();
}
