#include "principal.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Promedio_Internalizacion_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    QTranslator traducion;
    QStringList idiomas;
    idiomas << "Ruso" << "Chino" << "Albanes" << "Catalan";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                               "Idioma",
                               "Seleccione un idioma",
                               idiomas);
    if (idiomaSeleccionado == "Catalan"){
        traducion.load(":/Promedio_Internalizacion_ca_AD");
    }else if (idiomaSeleccionado == "Chino"){
        traducion.load(":/Promedio_Internalizacion_zh_CN");
    }else if (idiomaSeleccionado == "Ruso"){
        traducion.load(":/Promedio_Internalizacion_ru.qm");
    }else if (idiomaSeleccionado == "Albanes") {
        traducion.load(":/Promedio_Internalizacion_sq_AL");
    }
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }
    Principal w;
    w.show();
    return a.exec();
}
