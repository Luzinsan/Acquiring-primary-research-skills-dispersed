#include <QHBoxLayout>
#include "combobox.h"

ComboBox::ComboBox(QWidget *parent)
    : QWidget(parent) {

  QStringList distros = {"Arch", "Xubuntu", "Redhat", "Debian",
      "Mandriva"};

  QHBoxLayout *hbox = new QHBoxLayout(this);

  combo = new QComboBox();
  combo->addItems(distros);

  hbox->addWidget(combo);
  hbox->addSpacing(15);

  label = new QLabel("Arch", this);
  hbox->addWidget(label);
  // Сигнал activated() нашего QComboBox подключается к слоту setText() метки.
  // Поскольку сигнал перегружен,
  // то мы делаем статическое преобразование данных при помощи оператора static_cast:
  connect(combo, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated),
      label, &QLabel::setText);
}
