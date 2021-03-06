#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QMainWindow>

namespace Ui {
class VideoWindow;
}

namespace AS {
#include "../../ardusub_api/api/inc/ardusub_api.h"
}

class VideoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoWindow(QWidget *parent = nullptr);
    ~VideoWindow();

    void showVideo(bool show);

public slots:
    void on_updateVehicleDataSignal(AS::Vehicle_Data_t *vehicle_data);

signals:
    void closeWindows();

private:
    Ui::VideoWindow *ui;

    void resizeEvent(QResizeEvent* event);
    void resizeWindowsManual();

    void updateAdiCompass(AS::Vehicle_Data_t *vehicle_data);

    void closeEvent(QCloseEvent *event);
};

#endif // VIDEOWINDOW_H
