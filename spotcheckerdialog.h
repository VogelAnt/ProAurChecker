#ifndef SPOTCHECKERDIALOG_H
#define SPOTCHECKERDIALOG_H

#include <QVBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QDialog>
#include <QObject>
#include <QRadioButton>

class SpotCheckerDialog : public QDialog {
  Q_OBJECT
public:
  SpotCheckerDialog();
  ~SpotCheckerDialog();
private slots:
  void on_FeingewichtSelected();
  void on_PuritySelected();

private:
  void SetupLayout();
  QVBoxLayout *m_vLayout = nullptr;
  QHBoxLayout *m_fgLayout = nullptr;
  QHBoxLayout *m_purityLayout = nullptr;
  QLabel *m_headerLabel = nullptr;
  // TODO: rename
  QRadioButton *m_simpleButton = nullptr;
  QRadioButton *m_advButton = nullptr;
};

#endif // SPOTCHECKERDIALOG_H
