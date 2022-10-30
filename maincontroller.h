#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include <QObject>
#include <QFileInfo>
#include <QThread>
#include <QFileDialog>
#include <QStringList>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QWidget>
#include "singlescan.h"
#include "updatecontroller.h"
#include "directoryscan.h"
#include "database.h"

class MainController:  public QWidget{
    Q_OBJECT

public:
    MainController(QWidget *parent = nullptr);

signals:
    void change(QString);
    void scanStarted(void);
    void scanComplete(void);
    void sendResultToQml(QString singleScanResult);
    void sSRToQMLDone(void);
    void totalBytesToQml(int tBTQML);
    void bytesReadToQml(int bRTQML);
    void txtBytesReadToQml(QString txtBRTQML);
    void pBarActivity(QString);
    void pBarVisibility(bool);
    void fileCountInfo(QString numFilesScanned_);

public slots:
    void singleFileScan();
    void scanDirectory();
    void handleScanStart();
    void handleScanOpsInfo(QString);
    void handleScanComplete();
    void test();
    void displayInfectedFiles(QString);
    void stopThread();
    QString getFiles();
    int getCurrentValue();
    QString getTxtCurrentValue();
    int getTotalBytesValue();
    QString getpBarText();
    bool getpBarVisibility();
    void setFiles(QString);
    void downloadSignatures();
    void updateProgressBar(int, int);
    void updateProgBarFileOps(int);
    void updateStatus(QString);

    QString getDirScanFileCount();

private:
    SingleScan *singleFileScanThread;
    bool checkTextOne;
    bool checkTextTwo;
    QString *fileName;
    QString theInfectedFile;
    UpdateController *updateController;
    QThread *updateThread;
    int currentValue;
    int totBytesVal;
    QString gValBarActivity;
    bool gValBarVisibility;
    DirectoryScan *directoryScan;
    int fileCount;
    QString txtBytestoQML = "50";
    QString dirScanedFileCount;

    Database *database;

};

#endif // MAINCONTROLLER_H
