#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QGamepadManager>
#include <QtGamepad/QGamepad>

#include "VLCQtWidgets/WidgetVideo.h"
#include "VLCQtCore/Common.h"
#include "VLCQtCore/Media.h"
#include "VLCQtCore/Instance.h"
#include "VLCQtCore/MediaPlayer.h"

#include "chart.h"

namespace AS {
#include "./ardusub_api/api/inc/ardusub_api.h"
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setChartsSize();

private slots:

    void on_actionVideo_triggered();

    void on_actionAnalyze_triggered();

    void on_armCheckBox_stateChanged(int state);

    void on_modeComboBox_currentIndexChanged(int index);

    void on_vehicleComboBox_currentIndexChanged(const QString &index);

    void on_actionDisarm_triggered();

    void on_actionSetings_triggered();

    void on_depthPidCheckBox_stateChanged(int arg1);

    void on_depthHoldCheckBox_stateChanged(int arg1);

    void on_stackedWidgetMain_currentChanged(int arg1);

    void on_connectedGamepadsChanged();

    void on_listWidget_currentRowChanged(int currentRow);

    // joystick
    void on_joystick_axisLeftXChanged(double value);
    void on_joystick_axisLeftYChanged(double value);
    void on_joystick_axisRightXChanged(double value);
    void on_joystick_axisRightYChanged(double value);

private:
    Ui::MainWindow *ui;

    YawRollChart *m_yawRollChart;
    QGraphicsScene *m_yawRollScene;

    PitchChart *m_pitchChart;
    QGraphicsScene *m_pitchScene;

    DepthChart *m_depthChart;
    QGraphicsScene *m_depthScene;

    QLabel *vehicleLable;
    QComboBox *vehicleComboBox;
    QCheckBox *armCheckBox;
    QLabel *modeLable;
    QComboBox *modeComboBox;

    QGamepadManager *joystickManager;
    QGamepad *m_joystick;

    VlcInstance *_vlcInstance;
    VlcMedia *_vlcMedia;
    VlcMediaPlayer *_vlcPlayer;

    QTimer depthPidTimer, statusTexTimer;
    QTimer chartTimer;
    QTimer adiCompassTimer;
    QTimer vehicleCheckTimer;
    QTimer namedValueTimer;

    uint8_t currentVehicle;

    AS::Vehicle_Data_t *vehicle_data_g;

    QHash<QString, float> namedFloatHash;
    QHash<QString, int> activeVehicleHash;

    void resizeEvent(QResizeEvent* event);

    void setupToolBars();

    void stringToHtml(QString &str, QColor _color);

    void setupTimer();

    void setupVideo();

    void setupJoystick();
    void connectJoystickSlots(bool b, QGamepad* m_joystick);

    void setConfigView();

    // Timer callback
    void depthPidControl();
    void fetchStatusTex();
    void updateChart();
    void updateAdiCompass();
    void vehicleCheck();
    void updateNamedValue();
};

#endif // MAINWINDOW_H
