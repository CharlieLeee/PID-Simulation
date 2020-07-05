#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "qcustomplot.h"
#include "pid/pid_incremental.h"
#include "pid/pid_position.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  
private slots:
  void titleDoubleClick(QMouseEvent *event);
  void axisLabelDoubleClick(QCPAxis* axis, QCPAxis::SelectablePart part);
  void legendDoubleClick(QCPLegend* legend, QCPAbstractLegendItem* item);
  void selectionChanged();
  void mousePress();
  void mouseWheel();
  void removeSelectedGraph();
  void removeAllGraphs();
  void contextMenuRequest(QPoint pos);
  void moveLegend();
  void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);
  
  void on_pushButtonRun_clicked(void);

  void startPidIncrementalThreadSlot();

  void startPidPositionThreadSlot();

  void getPidResultSlot(float, float, float);
  void getPidPropertySlot(float, float, float, float);

signals:
  // update position pid
  void positionPidUpdateSignal(float p, float i, float d, float tar, float act);
  // update incremental pid
  void incrementalPidUpdateSignal(float p, float i, float d, float tar, float act);
  // value changed and replot signal
  void valueChangedReplotSignal(float);
  // start a incremental pid thread
  void startPidIncrementalThreadSignal(void);
  // start a position pid thread
  void startPidPositionThreadSignal(void);

private:
  Ui::MainWindow *ui;

  pid_incremental *ins_pid_incremental = NULL;
  pid_position    *ins_pid_position = NULL;
};

#endif // MAINWINDOW_H
