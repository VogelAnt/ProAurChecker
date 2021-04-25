#include "spotcheckerdialog.h"

SpotCheckerDialog::SpotCheckerDialog() { SetupLayout(); }

void SpotCheckerDialog::SetupLayout() {
  m_vLayout = new QVBoxLayout(this);
  m_headerLabel = new QLabel("Spot Checker: ", this);
  m_simpleButton = new QRadioButton("Nach Feingewicht", this);
  m_advButton = new QRadioButton("Nach Gewicht und Reinheit", this);

  m_vLayout->addWidget(m_headerLabel);
  m_vLayout->addWidget(m_simpleButton);
  m_vLayout->addWidget(m_advButton);
}

void SpotCheckerDialog::on_FeingewichtSelected() {}

void SpotCheckerDialog::on_PuritySelected() {}

SpotCheckerDialog::~SpotCheckerDialog() {}
