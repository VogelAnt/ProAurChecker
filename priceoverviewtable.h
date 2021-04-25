#ifndef PRICEOVERVIEWTABLE_H
#define PRICEOVERVIEWTABLE_H

#include <QTableWidget>
#include <QHeaderView>
#include <QObject>
#include <QStringList>

class PriceOverViewTable : public QTableWidget {
  Q_OBJECT
public:
  PriceOverViewTable(QWidget *parent);
  ~PriceOverViewTable();
public slots:
  void on_RefreshTable();

private:
  void SetupTable();
  QStringList m_columnHeaders;
  QStringList m_rowHeaders;
};

#endif // PRICEOVERVIEWTABLE_H
