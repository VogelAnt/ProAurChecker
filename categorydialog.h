#ifndef CATEGORYDIALOG_H
#define CATEGORYDIALOG_H

#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include <QVector>
#include <QString>

#include <iostream>

class CategoryDialog : public QDialog {
  Q_OBJECT
public:
  CategoryDialog();
  ~CategoryDialog();

private slots:
  void on_cancelButtonclicked();
  void on_okButtonclicked();
signals:
  void restructureTable(QVector<QString> vector);

private:
  void SetLayoutSpacingMarginsAlignment(QBoxLayout *layout,
                                        Qt::Alignment alignment);
  void SetupLayout();
  QGridLayout *m_grid = nullptr;
  QHBoxLayout *m_buttonLayout = nullptr;
  QVBoxLayout *m_vLayout = nullptr;
  QPushButton *m_okButton = nullptr;
  QPushButton *m_cancelButton = nullptr;
  QCheckBox *m_barren = nullptr;
  QCheckBox *m_alleMuenzen = nullptr;
  QCheckBox *m_kapitalanlage = nullptr;
  QCheckBox *m_deutschland = nullptr;
  QCheckBox *m_oesterreich = nullptr;
  QCheckBox *m_schweiz = nullptr;
  QCheckBox *m_europa = nullptr;
  QCheckBox *m_welt = nullptr;
  QVector<QString> m_selectedProducts;
};

#endif // CATEGORYDIALOG_H
