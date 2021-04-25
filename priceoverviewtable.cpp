#include "priceoverviewtable.h"

PriceOverViewTable::PriceOverViewTable(QWidget *parent) : QTableWidget(parent) {
  SetupTable();
}

void PriceOverViewTable::SetupTable() {
  //  setMinimumHeight(102);
  setFrameStyle(QFrame::NoFrame);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  //  setMinimumSize(380, 100);
  setMinimumHeight(90);
  setMaximumWidth(448);
  m_columnHeaders << "USD/oz"
                  << "USD/g"
                  << "EUR/oz"
                  << "EUR/g";
  m_rowHeaders << "Gold"
               << "Silber";
  setColumnCount(4);
  setRowCount(2);
  setSortingEnabled(false);
  setHorizontalHeaderLabels(m_columnHeaders);
  setVerticalHeaderLabels(m_rowHeaders);
}

void PriceOverViewTable::on_RefreshTable() {}

PriceOverViewTable::~PriceOverViewTable() {}
