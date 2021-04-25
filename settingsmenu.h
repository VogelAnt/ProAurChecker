#ifndef CUSTOMMENU_H
#define CUSTOMMENU_H

#include <QMenu>
#include <QObject>
#include <QPixmap>
#include <QPalette>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include <iostream>

class SettingsMenu : public QMenu {
public:
  SettingsMenu(QString text);
  ~SettingsMenu();
  void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

private:
  QAction *m_lightModeaction = nullptr;
  QAction *m_darkModeaction = nullptr;
  QAction *m_timerAction = nullptr;
};
#endif // CUSTOMMENU_H
