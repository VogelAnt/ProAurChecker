#ifndef MAINMENU_H
#define MAINMENU_H

#include "comparisontable.h"
#include "priceoverviewtable.h"
#include "categorydialog.h"
#include "spotcheckerdialog.h"

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QComboBox>
#include <QLabel>
#include <QToolButton>
#include <QDebug>
#include <QStringList>
#include <QTextEdit>
#include <QPixmap>
#include <QPalette>
#include <QTextBrowser>

// class SettingsMenu : public QMenu {
// public:
//  SettingsMenu(QString text);
//  ~SettingsMenu();
//  void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

// private:
//  QAction *m_lightModeaction = nullptr;
//  QAction *m_darkModeaction = nullptr;
//  QAction *m_timerAction = nullptr;
//};

class CustomMenu : public QMenu {
public:
  CustomMenu();
  CustomMenu(QString text);
  ~CustomMenu();
  void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

private:
  QAction *m_worldMapaction = nullptr;
  QAction *m_polarPlotaction = nullptr;
  QAction *m_simTimeaction = nullptr;
};

class MainMenu : public QMainWindow {
  Q_OBJECT

public:
  MainMenu(QWidget *parent = nullptr);
  ~MainMenu();
  void on_categoryBoxchanged(const QString &selectedText);

signals:
  void SetupStandardLook();

private slots:
  void on_SetLightMode();
  void on_SetDarkMode();
  void on_LaunchSpotCheckerDialog();

private:
  void SetupMenus();
  void SetupLayouts();

  void SetLayoutSpacingMarginsAlignment(QBoxLayout &layout,
                                        Qt::Alignment alignment);
  QStringList m_kategorienListe;
  QStringList m_filialListe;

  QWidget *m_centralWidget = nullptr;
  QHBoxLayout *m_mainLayout = nullptr;
  QVBoxLayout *m_optionsLayout = nullptr;
  QHBoxLayout *m_kategorieLayout = nullptr;

  QLabel *m_filialLabel = nullptr;
  QComboBox *m_filialAuswahlbox = nullptr;
  QLabel *m_kategorieLabel = nullptr;
  QComboBox *m_kategorieAuswahlbox = nullptr;
  QToolButton *m_kategorieFilterbutton = nullptr;
  ComparisonTable *m_comparisonTable = nullptr;
  PriceOverViewTable *m_priceTable = nullptr;
  CategoryDialog *m_categoryDialog = nullptr;
  QMenu *m_settingsMenu = nullptr;
  QMenu *m_extrasMenu = nullptr;
  QAction *m_lightModeaction = nullptr;
  QAction *m_darkModeaction = nullptr;
  QAction *m_timerAction = nullptr;
  QAction *m_checkerToolaction = nullptr;
  SpotCheckerDialog *m_spotCheckerdialog = nullptr;
};
#endif // MAINMENU_H
