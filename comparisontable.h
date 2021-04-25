#ifndef OVERVIEWTABLE_H
#define OVERVIEWTABLE_H

#include <QTableWidget>
#include <QHeaderView>
#include <QObject>
#include <QStringList>
#include <QVector>
#include <QString>

class ComparisonTable : public QTableWidget {
  Q_OBJECT
public:
  ComparisonTable(QWidget *parent);
  ~ComparisonTable();
public slots:
  /**
   * @brief on_updateTable
   * called when the price has been updated
   */
  void on_updateTable();
  void on_restructureTable(QVector<QString> vector);

  //  void on_currentTextChanged(const QString &headerName);

private:
  void SetupTable();
  QStringList m_columnHeader;
};

#endif // OVERVIEWTABLE_H
