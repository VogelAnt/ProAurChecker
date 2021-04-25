#include "categorydialog.h"

CategoryDialog::CategoryDialog() {
  SetupLayout();
  connect(m_cancelButton, &QPushButton::clicked, this,
          &CategoryDialog::on_cancelButtonclicked);
  connect(m_okButton, &QPushButton::click, this,
          &CategoryDialog::on_okButtonclicked);
}

void CategoryDialog::SetupLayout() {
  //  setMinimumSize(300, 300);
  m_vLayout = new QVBoxLayout(this);
  m_buttonLayout = new QHBoxLayout();
  m_cancelButton = new QPushButton("Cancel", this);
  m_okButton = new QPushButton("OK", this);
  m_buttonLayout->addWidget(m_cancelButton, 1);
  m_buttonLayout->addWidget(m_okButton, 1);

  m_kapitalanlage = new QCheckBox("Goldmünzen zur Kapitalanlage", this);
  m_deutschland = new QCheckBox("Goldmünzen aus Deutschland", this);
  m_oesterreich = new QCheckBox("Goldmünzen aus Österreich", this);
  m_schweiz = new QCheckBox("Münzen aus der Schweiz", this);
  m_europa = new QCheckBox("Goldmünzen übriges Europa", this);
  m_welt = new QCheckBox("Goldmünzen aus der übrigen Welt", this);
  m_barren = new QCheckBox("Goldbarren", this);
  m_vLayout->addWidget(m_barren);
  m_vLayout->addWidget(m_kapitalanlage);
  m_vLayout->addWidget(m_deutschland);
  m_vLayout->addWidget(m_oesterreich);
  m_vLayout->addWidget(m_schweiz);
  m_vLayout->addWidget(m_europa);
  m_vLayout->addWidget(m_welt);
  SetLayoutSpacingMarginsAlignment(m_vLayout, Qt::AlignTop);
  m_vLayout->addLayout(m_buttonLayout);
}

void CategoryDialog::on_cancelButtonclicked() {
  this->destroy();
  this->close();
}

void CategoryDialog::on_okButtonclicked() {
  // get every single selected
  QList<QCheckBox *> CheckBoxWidgetList = this->findChildren<QCheckBox *>();
  foreach (QCheckBox *checkBox, CheckBoxWidgetList) {
    if (checkBox->isChecked()) {
      m_selectedProducts.push_back(checkBox->text());
    }
  }
  emit restructureTable(m_selectedProducts);
}

void CategoryDialog::SetLayoutSpacingMarginsAlignment(QBoxLayout *layout,
                                                      Qt::Alignment alignment) {
  layout->setSpacing(0);
  layout->setMargin(0);
  layout->setAlignment(alignment);
  layout->setContentsMargins(0, 0, 0, 0);
}

CategoryDialog::~CategoryDialog() { qDebug() << "Deleted category dialog"; }
