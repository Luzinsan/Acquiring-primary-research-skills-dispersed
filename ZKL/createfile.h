#ifndef CREATEFILE_H
#define CREATEFILE_H
#include <QWidget>

class CreateFile: public QWidget
{
public:
    CreateFile(QWidget *parent = 0);
private:
public slots:
    void createFile();
};

#endif // CREATEFILE_H
