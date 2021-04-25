#include "mainmenu.h"
#include <QString>
/*
// SettingsMenu::SettingsMenu(QString text) : QMenu(text) {
//  std::cout << "Into CustomMenu" << std::endl;
//  m_lightModeaction = new QAction("&Light Mode", this);
//  m_darkModeaction = new QAction("&Dark Mode", this);
//  m_timerAction = new QAction("&Update Time", this);

//  m_lightModeaction->setCheckable(true);
//  m_darkModeaction->setCheckable(true);

//  m_lightModeaction->setChecked(false);
//  m_darkModeaction->setChecked(false);

//  addAction(m_timerAction);
//  addAction(m_lightModeaction);
//  addAction(m_darkModeaction);
//}

// void SettingsMenu::mouseReleaseEvent(QMouseEvent *e) {
//  std::cout << "into mousereleaseEvent" << std::endl;
//  QAction *action = activeAction();
//  if (action && action->isEnabled()) {
//    action->setEnabled(false);
//    QMenu::mouseReleaseEvent(e);
//    action->setEnabled(true);
//    action->trigger();
//  } else {
//    QMenu::mouseReleaseEvent(e);
//  }
//}
*/

void CustomMenu::mouseReleaseEvent(QMouseEvent *e) {
  std::cout << "into mousereleaseEvent" << std::endl;
  QAction *action = activeAction();
  if (action && action->isEnabled()) {
    action->setEnabled(false);
    QMenu::mouseReleaseEvent(e);
    action->setEnabled(true);
    action->trigger();
  } else {
    QMenu::mouseReleaseEvent(e);
  }
}

/**
 * @brief MainMenu::MainMenu
 * @param parent
 * Filial ComboBox changed send signal to refresh fun ...
 * Kategorie ComboBox changed send signal to refresh fun AND
 * Settings -> Set auto refresh timer
 * Kategorie ComboBox changed send signal to make tables (change header)
 */
MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent) {
  SetupMenus();
  SetupLayouts();
  connect(m_kategorieAuswahlbox, &QComboBox::currentTextChanged, this,
          &MainMenu::on_categoryBoxchanged);
  connect(m_categoryDialog, &CategoryDialog::restructureTable,
          m_comparisonTable, &ComparisonTable::on_restructureTable);
  connect(m_lightModeaction, &QAction::triggered, this,
          &MainMenu::on_SetLightMode);
  connect(m_darkModeaction, &QAction::triggered, this,
          &MainMenu::on_SetDarkMode);
  connect(this, &MainMenu::SetupStandardLook, this, &MainMenu::on_SetDarkMode);
  emit SetupStandardLook();
}
// TODO: I had a function somewhere that can give back the size of the widget

void MainMenu::SetupLayouts() {
  setMinimumSize(1250, 400);
  //  m_settingsMenu = new CustomMenu("&Settings");
  //  this->menuBar()->addMenu(m_settingsMenu);
  m_filialListe << "München"
                << "Berlin"
                << "Bad Homburg"
                << "Dresden"
                << "Düsseldorf"
                << "Hamburg"
                << "Stuttgart";

  m_kategorienListe << "Alle"
                    << "Custom"
                    << "Goldmünzen Kapitalanlage"
                    << "Goldmünzen Deutschland"
                    << "Goldmünzen Österreich"
                    << "Goldmünzen Schweiz"
                    << "Goldmünzen übr Europa"
                    << "Goldmünzen übr Welt";

  m_centralWidget = new QWidget(this);
  m_comparisonTable = new ComparisonTable(m_centralWidget);
  m_priceTable = new PriceOverViewTable(m_centralWidget);
  m_mainLayout = new QHBoxLayout(m_centralWidget);
  m_optionsLayout = new QVBoxLayout();

  m_filialLabel = new QLabel("Filiale wählen", m_centralWidget);
  m_filialAuswahlbox = new QComboBox(m_centralWidget);
  m_filialAuswahlbox->addItems(m_filialListe);

  m_kategorieLabel = new QLabel("Kategorie wählen", m_centralWidget);
  m_kategorieAuswahlbox = new QComboBox(m_centralWidget);
  m_kategorieAuswahlbox->addItems(m_kategorienListe);

  SetLayoutSpacingMarginsAlignment(*m_optionsLayout, Qt::AlignLeft);
  m_optionsLayout->addWidget(m_filialLabel, 1);
  m_optionsLayout->addWidget(m_filialAuswahlbox, 1);
  m_optionsLayout->addWidget(m_kategorieLabel, 1);
  m_optionsLayout->addWidget(m_kategorieAuswahlbox, 1);
  m_optionsLayout->addWidget(m_priceTable, 1);
  m_optionsLayout->addStretch(7);

  m_mainLayout->addLayout(m_optionsLayout, 1);
  m_mainLayout->addWidget(m_comparisonTable, 2);
  m_centralWidget->setLayout(m_mainLayout);
  SetLayoutSpacingMarginsAlignment(*m_mainLayout, Qt::AlignLeft);
  this->setCentralWidget(m_centralWidget);
}

void MainMenu::SetupMenus() {
  m_settingsMenu = new QMenu("Einstellungen", this);
  m_extrasMenu = new QMenu("Extras", this);
  this->menuBar()->addMenu(m_settingsMenu);
  this->menuBar()->addMenu(m_extrasMenu);

  m_lightModeaction = new QAction("&Light Mode", this);
  m_darkModeaction = new QAction("&Dark Mode", this);
  m_timerAction = new QAction("&Timer settings", this);
  m_checkerToolaction = new QAction("&Spot Checker Tool", this);

  m_lightModeaction->setCheckable(true);
  m_darkModeaction->setCheckable(true);

  m_lightModeaction->setChecked(false);
  m_darkModeaction->setChecked(false);

  m_settingsMenu->addAction(m_timerAction);
  m_settingsMenu->addAction(m_lightModeaction);
  m_settingsMenu->addAction(m_darkModeaction);
  m_extrasMenu->addAction(m_checkerToolaction);
}

void MainMenu::on_categoryBoxchanged(const QString &selectedText) {
  qDebug() << selectedText;
  if (selectedText == "Custom") {
    m_categoryDialog = new CategoryDialog();
    m_categoryDialog->show();
  }
}

void MainMenu::SetLayoutSpacingMarginsAlignment(QBoxLayout &layout,
                                                Qt::Alignment alignment) {
  std::cout << "IN SET SPACING FUNCTION" << std::endl;
  layout.setSpacing(0);
  layout.setMargin(0);
  layout.setAlignment(alignment);
  layout.setContentsMargins(0, 0, 0, 0);
}

void MainMenu::on_SetDarkMode() {
  std::cout << "DARK MODE " << std::endl;
  m_darkModeaction->setChecked(true);
  m_lightModeaction->setChecked(false);
}

void MainMenu::on_LaunchSpotCheckerDialog() {}

void MainMenu::on_SetLightMode() {
  std::cout << "LIGHT MODE " << std::endl;
  m_darkModeaction->setChecked(false);
  m_lightModeaction->setChecked(true);
}

MainMenu::~MainMenu() {}
