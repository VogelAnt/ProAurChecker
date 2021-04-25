#include "comparisontable.h"

ComparisonTable::ComparisonTable(QWidget *parent) : QTableWidget(parent) {
  SetupTable();
}

void ComparisonTable::SetupTable() {
  setMinimumWidth(810);
  setMaximumWidth(810);
  m_columnHeader << "Bezeichnung"
                 << "Feingewicht"
                 << "Kaufpreis"
                 << "Buy +/- % Spot"
                 << "Verkaufspreis"
                 << "Sell +/- % Spot"
                 << "Spread (€)"
                 << "Spread (%)";
  setColumnCount(8);
  setSortingEnabled(false);
  setHorizontalHeaderLabels(m_columnHeader);
  verticalHeader()->setVisible(false);
}

void ComparisonTable::on_updateTable() {}

void ComparisonTable::on_restructureTable(QVector<QString> vector) {}

ComparisonTable::~ComparisonTable() {}
